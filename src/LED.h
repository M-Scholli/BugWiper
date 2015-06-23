/*
 * LED.h
 *
 *  Created on: 23.06.2015
 *      Author: Moritz Scholjegerdes
 */

#ifndef LED_H_
#define LED_H_

#include "Arduino.h"
#include "Time.h"

class Led
{
public:
  Led (byte pin);
  void
  on (void);
  void
  off (void);
  void
  blink_on (unsigned int duration);
  void
  blink_off (void);
  void
  refresh (void);
  void
  toggle (void);
private:
  byte _pin;
  byte blinking;  // 1 = Led is blinking mode
  byte state;
  unsigned int _duration; // time in milliseconds the led is on and off;
  Time t_led;
};

#endif /* LED_H_ */
