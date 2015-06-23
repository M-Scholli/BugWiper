/*
 * L298.h
 *
 *  Created on: 19.06.2015
 *      Author: Moritz Scholjegerdes
 */

#ifndef L298_H_
#define L298_H_

#include "Arduino.h"

class L298
{
public:
  L298 (byte pin1, byte pin2, byte pinEnable);
  void
  setPower (byte power);	// power from 0 to 255
  void
  setPower_T1 (int power);	//uses TimerOne.h Power 0 - 1023
  void
  forward ();
  void
  reverse ();
  void
  stop ();
  void
  setDirection (byte direction);
private:
  byte _pin1;
  byte _pin2;
  byte _pinEnable;
  byte pwm_init;
};

#endif /* L298_H_ */
