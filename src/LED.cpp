/*
 * LED.cpp
 *
 *  Created on: 23.06.2015
 *      Author: Moritz Scholjegerdes
 */

#include "LED.h"

#include "Arduino.h"
#include "../lib/Timer/Timer.h"

Led::Led (byte pin)
{
  _pin = pin;
  blinking = 0;
  pinMode (_pin, OUTPUT);
  Timer t_led;
  state = 0;
  _duration = 1000;
  off();
}

void
Led::on (void)
{
  digitalWrite (_pin, HIGH);
  state = 1;
}

void
Led::off (void)
{
  digitalWrite (_pin, LOW);
  state = 0;
}

void
Led::blink_on (unsigned int duration)
{
  _duration = duration;
  blinking = 1;
  t_led.restart ();
  toggle ();
}

void
Led::blink_off (void)
{
  blinking = 0;
  off ();
}

void
Led::refresh (void)
{
  if (blinking == 1 && t_led.t_since_start () >= _duration)
    {
      t_led.restart ();
      toggle ();
    }
}

void
Led::toggle (void)
{
  digitalWrite (_pin, (state) ? HIGH : LOW);
  state = !state;
}
