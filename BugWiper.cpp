// Do not remove the include below
#include "BugWiper.h"
#include "L298.h"
#include "Arduino.h"

L298 motor(7,8,9);

//The setup function is called once at startup of the sketch
void setup()
{
// Add your initialization code here
motor.stop();
motor.setPower(0);
}

// The loop function is called in an endless loop
void loop()
{
//Add your repeated code here
}
