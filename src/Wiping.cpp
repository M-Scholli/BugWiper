/*
 * Wiping.cpp
 *
 *  Created on: 21.06.2015
 *      Author: Moritz Scholjegerdes
 */

#include "Wiping.h"
#include "Arduino.h"
#include "L298.h"

Wiping::Wiping (L298, byte p_start, byte t_min, byte t_max)
{
  _p_start = p_start;
  _t_min = t_min;
  _t_max = t_max;
}

byte
Wiping::w_wiping (byte direction)
{
  byte safe = 0;
  return safe;
}
