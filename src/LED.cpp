/*
 * LED.cpp
 *
 *  Created on: 23.06.2015
 *      Author: Moritz Scholjegerdes
 */

#include "LED.h"

#include "Arduino.h"

Led::Led (byte pin)
{
  _pin = pin;
  init ();
}

void
Led::on (void)
{
  digitalWrite (_pin, HIGH);
}

void
Led::off (void)
{
  digitalWrite (_pin, LOW);
}

void
Led::init (void)
{
  pinMode (_pin, OUTPUT);
}
