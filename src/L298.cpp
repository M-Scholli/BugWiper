/*
 * L298.cpp
 *
 *  Created on: 19.06.2015
 *      Author: Moritz Scholjegerdes
 */

#include "L298.h"
#include "Arduino.h"

L298::L298 (byte pin1, byte pin2, byte pinEnable)
{
  pinMode (pin1, OUTPUT);
  pinMode (pin2, OUTPUT);
  pinMode (pinEnable, OUTPUT);
  _pin1 = pin1;
  _pin2 = pin2;
  _pinEnable = pinEnable;
}

void
L298::setPower (int power)
{
  analogWrite (_pinEnable, power);
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
