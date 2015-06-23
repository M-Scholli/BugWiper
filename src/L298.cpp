/*
 * L298.cpp
 *
 *  Created on: 19.06.2015
 *      Author: Moritz Scholjegerdes
 */

#include "L298.h"
#include "Arduino.h"
#include "../lib/TimerOne/TimerOne.h"

L298::L298 (byte pin1, byte pin2, byte pinEnable)
{
  pinMode (pin1, OUTPUT);
  pinMode (pin2, OUTPUT);
  pinMode (pinEnable, OUTPUT);
  _pin1 = pin1;
  _pin2 = pin2;
  _pinEnable = pinEnable;
  pwm_init = 0;
}

void
L298::setPower (byte power)
{
  analogWrite (_pinEnable, power);
}

void
L298::setPower_T1 (int power)
{
  if (pwm_init == 0)
    {
      Timer1.pwm (_pinEnable, power);
      pwm_init = 1;
    }
  else
    {
      Timer1.setPwmDuty (_pinEnable, power);
    }
}
void
L298::forward ()
{
  digitalWrite (_pin1, LOW);
  digitalWrite (_pin2, HIGH);
}

void
L298::reverse ()
{
  digitalWrite (_pin1, HIGH);
  digitalWrite (_pin2, LOW);
}

void
L298::stop ()
{
  digitalWrite (_pin1, LOW);
  digitalWrite (_pin2, LOW);
}

void
L298::setDirection (byte direction)
{
  switch (direction)
    {
    case 1:
      forward ();
    case 2:
      reverse ();
    default:
      stop ();
    }

}
