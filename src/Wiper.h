/*
 * Wiper.h
 *
 *  Created on: 22.06.2015
 *      Author: Moritz Scholjegerdes
 */

#ifndef WIPER_H_
#define WIPER_H_

#include "L298.h"

class Wiper
{
public:
  Wiper ();
  void
  fullWipe (L298& motor_driver);
  void
  TieUp (L298& motor_driver);
private:
  void
  read_direction ();
  void
  update_direction ();
};

#endif /* WIPER_H_ */
