/*
 * Button.h
 *
 *  Created on: 20.06.2015
 *      Author: Moritz Scholjegerdes
 *
 *      Checking if a button was pressed long or short with debounce for active low Buttons with use of the internal pullups.
 *
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "Arduino.h"
#include "../lib/Timer/Timer.h"

class Button
{
public:
  Button (byte pin, unsigned int debounce_delay, unsigned int long_delay);
  void
  check_button_state (void);
  byte
  button_pressed_long (void);
  byte
  button_press_long (void);
  byte
  button_pressed_short (void);
  void
  button_reset (void);
private:
  byte _pin;
  byte _button_press; // button is actual pressed
  byte _long_pressed; 	// button was pressed long
  byte _short_pressed;	// button was pressed short
  byte long_press; 	// button is pressing long
  byte long_first;
  Timer t1;
  unsigned int _debounce_delay;
  unsigned int _long_delay;
  boolean button_state;
};

#endif /* BUTTON_H_ */
