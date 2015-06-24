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
#include "Time.h"

Wiping::Wiping (byte p_start, byte t_min, byte t_max, byte p_delay)
{
  _p_start = p_start;
  _p_delay = p_delay;
  _t_min = t_min;
  _t_max = t_max;
}

byte
Wiping::w_wiping (byte direction)
{
  byte safe = 0;
  byte run = 1;
  byte power = _p_start;
  byte p = 0;
  Time t;
  Time t2;
  led1.blink_on(LED_BLINK_WIPE);
  motor.setPower (power);
  motor.setDirection (direction);
  while (run == 1)
    {
      led1.refresh();
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
      //to do: add emergency stop and key override
    }
  led1.blink_off();
  return safe;
}
