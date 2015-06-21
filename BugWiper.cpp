// Do not remove the include below
#include "BugWiper.h"
#include "src/L298.h"
#include "src/Button.h"
#include "Arduino.h"
#include "lib/TimerOne.h"
#include "lib/EEPROM.h"

byte motor_direction;

L298 	motor(PIN_OUT_1, PIN_OUT_2, PIN_ENABLE);
Button	tie_up(PIN_TIE_UP, DEBOUNCE_T, LONG_PRESS_T);
Button  wipe(PIN_WIPE, DEBOUNCE_T, LONG_PRESS_T);

void buttonsRead()
{
	tie_up.check_button_state();
	wipe.check_button_state();
}

//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
motor_direction = EEPROM.read(EE_DIRECTION);
motor.stop();
motor.setPower(0);
Timer1.initialize(EVERY_X_MILLIS*1000);
Timer1.attachInterrupt(buttonsRead);
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
}
