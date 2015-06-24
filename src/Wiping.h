/*
 * Wiping.h
 *
 *  Created on: 21.06.2015
 *      Author: Moritz Scholjegerdes
 */

#ifndef WIPE_H_
#define WIPE_H_

#include "Arduino.h"
#include "L298.h"

class Wiping
{
public:
  Wiping (byte p_start, byte t_min, byte t_max, byte p_delay);
  void
  fullWipe ();
  void
  TieUp ();
  byte
  w_wiping (byte direction);
private:
  byte _p_start;
  byte _p_delay;
  byte _t_min;
  byte _t_max;
};

#endif /* WIPE_H_ */
