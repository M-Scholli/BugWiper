// Do not remove the include below
#include "BugWiper.h"

#include "src/L298.h"
#include "src/Button.h"
#include "src/Wiping.h"
#include "src/Wiper.h"
#include "Arduino.h"
#include "lib/TimerOne.h"
#include "lib/EEPROM.h"

byte motor_direction;

L298 motor (PIN_OUT_1, PIN_OUT_2, PIN_ENABLE);
Button b_tie_up (PIN_TIE_UP, DEBOUNCE_T, LONG_PRESS_T);
Button b_wipe (PIN_WIPE, DEBOUNCE_T, LONG_PRESS_T);
Wiper wiper_a;

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
      wiper_a.fullWipe ();
      b_wipe.button_reset ();
      b_tie_up.button_reset ();
    }
  else if (b_tie_up.button_pressed_short ()
      == 1&& digitalRead (KEY_LOCK) == UNLOCK_STATE)
    {
      wiper_a.TieUp ();
      b_wipe.button_reset ();
      b_tie_up.button_reset ();
    }
}
