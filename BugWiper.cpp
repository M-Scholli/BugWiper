// Do not remove the include below
#include "BugWiper.h"

#include "src/L298.h"
#include "src/Button.h"
#include "src/LED.h"
#include "src/Wiping.h"
#include "Arduino.h"
#include "lib/TimerOne/TimerOne.h"
#include "lib/EEPROM.h"

byte motor_direction;

L298 motor (PIN_OUT_1, PIN_OUT_2, PIN_ENABLE);
Button b_tie_up (PIN_TIE_UP, DEBOUNCE_T, LONG_PRESS_T);
Button b_wipe (PIN_WIPE, DEBOUNCE_T, LONG_PRESS_T);
Wiping full_wiping (W_P_START, W_T_MIN, W_T_MAX, W_P_DELAY);
Wiping tieing_up (TU_P_START, TU_T_MIN, TU_T_MAX, TU_P_DELAY);
Led led1 (PIN_LED_1);

void
buttonsRead ()
{
  b_tie_up.check_button_state ();
  b_wipe.check_button_state ();
}

void
key_init ()
{
  pinMode (KEY_TIGHT, INPUT);
  pinMode (KEY_LOCK, INPUT);
  //activate pullups
  digitalWrite (KEY_TIGHT, HIGH);
  digitalWrite (KEY_LOCK, HIGH);
}

//The setup function is called once at startup of the sketch
void
setup ()
{
// Add your initialization code here
  motor_direction = EEPROM.read (EE_DIRECTION);
  motor.stop ();
  motor.setPower (0);
  Timer1.initialize (EVERY_X_MILLIS * 1000);
  Timer1.attachInterrupt (buttonsRead);
  key_init ();
}

// The loop function is called in an endless loop
void
loop ()
{
  if (b_wipe.button_pressed_long ()
      == 1&& digitalRead (KEY_LOCK) == UNLOCK_STATE)
    {
      full_wiping.fullWipe ();
      b_wipe.button_reset ();
      b_tie_up.button_reset ();
    }
  else if (b_tie_up.button_pressed_short ()
      == 1&& digitalRead (KEY_LOCK) == UNLOCK_STATE)
    {
      tieing_up.TieUp ();
      b_wipe.button_reset ();
      b_tie_up.button_reset ();
    }
}
