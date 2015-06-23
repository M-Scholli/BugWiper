/*
 * Time.cpp
 *
 *  Created on: 23.06.2015
 *      Author: Moritz Scholjegerdes
 */

#include "Time.h"
#include "Arduino.h"

Time::Time (void)
{
  t_start = millis ();
}

unsigned long
Time::since_seconds (void)
{
  unsigned long seconds;
  seconds = t_since_start () / 1000;
  return seconds;
}

unsigned long
Time::t_since_start (void)
{
  unsigned long t;
  t = millis ();
  if (t < t_start) // detect overflow of millis ()
    {
      unsigned int t2;
      t2 = 4294967295 - t_start; // time from t_start to overflow of millis ()
      t = t + t2;
    }
  else
    {
      t = t - t_start;
    }
  return t;
}

