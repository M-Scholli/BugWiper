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
		L298(int pin1, int pin2, int pinEnable);
		void setPower(int power);
		void forward();
		void reverse();
		void stop();
	private:
		int _pin1;
		int _pin2;
		int _pinEnable;
};


#endif /* L298_H_ */
