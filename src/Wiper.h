/*
 * Wiper.h
 *
 *  Created on: 22.06.2015
 *      Author: Moritz Scholjegerdes
 */

#ifndef WIPER_H_
#define WIPER_H_

class Wiper
{
public:
  Wiper (L298 motor, int max_time_s, int min_time_s );
  byte
  wipe();
  void
  stop();
private:
  void
  read_direction ();
  void
  update_direction();
};


#endif /* WIPER_H_ */
