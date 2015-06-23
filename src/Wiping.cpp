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

Wiping::Wiping (byte p_start, byte t_min, byte t_max)
{
  _p_start = p_start;
  _t_min = t_min;
  _t_max = t_max;
}

byte
Wiping::w_wiping (byte direction)
{
  byte safe = 0;
  byte run = 1;
  Time t;
  motor.setPower (_p_start);
  motor.setDirection (direction);
  while (run == 1)
    {
      if (t.since_seconds () >= _t_max)
	{
	  run = 0;
	}
      if (t.since_seconds () >= _t_min && digitalRead (KEY_TIGHT) == LOW)
	{
	  safe = 1;
	  run = 0;
	}
      // to do: increase power to max during time
    }
  return safe;
}
