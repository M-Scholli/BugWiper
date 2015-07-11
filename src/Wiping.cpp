/*
 * Wiping.cpp
 *
 *  Created on: 21.06.2015
 *      Author: Moritz Scholjegerdes
 */

#include "Wiping.h"

#include "Arduino.h"
#include "../BugWiper.h"
#include "L298.h"
#include "../lib/Timer/Timer.h"
#include "../lib/EEPROMex/EEPROMex.h"
#include "../lib/Button/Button.h"

Wiping::Wiping (byte p_start, byte t_min, byte t_max, byte p_delay)
{
  _p_start = p_start;
  _p_delay = p_delay;
  _t_min = t_min;
  _t_max = t_max;
}

void
Wiping::fullWipe ()
{
  byte safe;
  byte direction;
  direction = read_direction ();
  safe = w_wiping (direction);
  if (safe == 0)
    {
      led1.on ();
    }
  else
    {
      direction = toggle_direction (direction);
      update_direction (direction);
    }

}

void
Wiping::TieUp ()
{
  byte safe;
  byte direction;
  direction = read_direction ();
  direction = toggle_direction (direction);
  safe = w_wiping (direction);
  if (safe == 0)
    {
      led1.on ();
    }
}

byte
Wiping::w_wiping (byte direction)
{
  byte safe = 0;
  byte run = 1;
  byte power = _p_start;
  byte p = 0;
  Timer t;
  Timer t2;
  led1.blink_on (LED_BLINK_WIPE);
  motor.setPower (power);
  motor.setDirection (direction);
  while (run == 1)
    {
      led1.refresh ();
      if (t.since_seconds () >= _t_max)
	{
	  run = 0;
	}
      if (t.since_seconds () >= _t_min && digitalRead (KEY_TIGHT) == LOW)
	{
	  safe = 1;
	  run = 0;
	}
      if (power < 255 && t2.t_since_start () >= _p_delay)
	{
	  t2.restart ();
	  power++;
	  motor.setPower (power);
	}
      if (b_wipe.button_press () == 1)
	{
	  run = 0;
	}
      //to do: key / time override
    }
  led1.blink_off ();
  return safe;
}

byte
Wiping::read_direction (void)
{
  byte direction;
  direction = EEPROM.readByte (EE_DIRECTION);
  return direction;
}

void
Wiping::update_direction (byte direction)
{
  EEPROM.updateByte (EE_DIRECTION, direction);
}

byte
Wiping::toggle_direction (byte direction)
{
  if (direction == 1)
    {
      direction = 2;
    }
  else if (direction == 2)
    {
      direction = 1;
    }
  else
    {
      direction = 0;
    }
  return direction;
}
