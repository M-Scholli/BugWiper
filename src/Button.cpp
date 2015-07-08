/*
 * Button.cpp
 *
 *  Created on: 20.06.2015
 *      Author: Moritz Scholjegerdes
 */

#include "Button.h"
#include "Arduino.h"
#include "../lib/Timer/Timer.h"

Button::Button (byte pin, unsigned int debounce_delay, unsigned int long_delay)
{
  pinMode (pin, INPUT);
  digitalWrite (pin, HIGH);
  _pin = pin;
  _debounce_delay = debounce_delay;
  _long_delay = long_delay;
  Timer t1;
  button_reset ();
}

void
Button::check_button_state ()
{
  boolean button_state = digitalRead (_pin);

  if (button_state == LOW && _button_press == 0)
    {
      t1.restart ();
      _button_press = 1;
    }
  if (t1.t_since_start () >= _long_delay && _button_press == 1
      && long_first == 0)
    {
      long_press = 1;
      long_first = 1;
    }
  if (button_state == HIGH && _button_press == 1
      && t1.t_since_start () >= _debounce_delay)
    {
      if (t1.t_since_start () >= _long_delay)
	{
	  _long_pressed = 1;
	}
      else
	{
	  _short_pressed = 1;
	}
      t1.restart ();
      _button_press = 2;
    }
  if (t1.t_since_start () >= _debounce_delay && _button_press == 2)
    {
      _button_press = 0;
      long_first = 0;
    }
}

byte
Button::button_pressed_long (void)
{
  byte pressed;
  pressed = _long_pressed;
  _long_pressed = 0;
  return pressed;
}

byte
Button::button_press_long (void)
{
  byte press;
  press = long_press;
  long_press = 0;
  return press;
}

byte
Button::button_pressed_short (void)
{
  byte pressed;
  pressed = _short_pressed;
  _short_pressed = 0;
  return pressed;
}

void
Button::button_reset (void)
{
  _long_pressed = 0;
  _short_pressed = 0;
  _button_press = 2;
  long_first = 0;
  t1.restart ();
}
