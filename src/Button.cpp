/*
 * Button.cpp
 *
 *  Created on: 20.06.2015
 *      Author: Moritz Scholjegerdes
 */

#include "Button.h"
#include "Arduino.h"

Button::Button (byte pin, unsigned int debounce_delay, unsigned int long_delay)
{
  pinMode (pin, INPUT);
  digitalWrite (pin, HIGH);
  _pin = pin;
  _debounce_delay = debounce_delay;
  _long_delay = long_delay;
  button_reset ();
}

void
Button::check_button_state ()
{
  boolean button_state = digitalRead (_pin);

  if (button_state == LOW && _button_press == 0)
    {
      time_of_last_press = millis ();
      _button_press = 1;
    }

  // In case that millis() was reseted, write time_of_last_press new.
  if (millis () < time_of_last_press)
    {
      time_of_last_press = millis ();
    }

  time_since_last_press = millis () - time_of_last_press;
  if (button_state == HIGH && _button_press == 1
      && time_since_last_press >= _debounce_delay)
    {
      if (time_since_last_press >= _long_delay)
	_long_pressed = 1;
      else
	_short_pressed = 1;
      _button_press = 0;
    }
}

byte
Button::button_pressed_long ()
{
  byte pressed;
  pressed = _long_pressed;
  _long_pressed = 0;
  return pressed;
}

byte
Button::button_pressed_short ()
{
  byte pressed;
  pressed = _short_pressed;
  _short_pressed = 0;
  return pressed;
}

void
Button::button_reset ()
{
  _long_pressed = 0;
  _short_pressed = 0;
  _button_press = 0;
}
