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

class Button
{
public:
  Button (byte pin, unsigned int debounce_delay, unsigned int long_delay);
  void
  check_button_state ();
  byte
  button_pressed_long ();
  byte
  button_pressed_short ();
private:
  byte _pin;
  byte _button_press; // button is actual pressed
  byte _long_pressed; 	// button was pressed long
  byte _short_pressed;	// button was pressed short
  unsigned int _debounce_delay;
  unsigned int _long_delay;
  unsigned long time_of_last_press;
  unsigned long time_since_last_press;
};

#endif /* BUTTON_H_ */
