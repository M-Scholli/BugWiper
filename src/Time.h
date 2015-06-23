/*
 * Time.h
 *
 *  Created on: 23.06.2015
 *      Author: Moritz Scholjegerdes
 */

#ifndef TIME_H_
#define TIME_H_

class Time
{
public:
  Time (void);
  unsigned long
  since_seconds (void);
  unsigned long
  t_since_start (void);
private:
  unsigned long t_start;
};

#endif /* TIME_H_ */
