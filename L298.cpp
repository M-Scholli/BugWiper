/*
 * L298.cpp
 *
 *  Created on: 19.06.2015
 *      Author: Moritz Scholjegerdes
 */

#include "L298.h"
#include "Arduino.h"

L298::L298(int pin1, int pin2, int pinEnable){
	pinMode(pin1, OUTPUT);
	pinMode(pin2, OUTPUT);
	pinMode(pinEnable, OUTPUT);
	_pin1=pin1;
	_pin2=pin2;
	_pinEnable=pinEnable;
}
