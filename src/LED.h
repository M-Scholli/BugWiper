/*
 * LED.h
 *
 *  Created on: 23.06.2015
 *      Author: Moritz Scholjegerdes
 */

#ifndef LED_H_
#define LED_H_

#include "Arduino.h"

class Led
{
public:
  Led (byte pin);
  void
  on (void);
  void
  off (void);
private:
  void
  init (void);
  byte _pin;
};

#endif /* LED_H_ */
