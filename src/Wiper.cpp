/*
 * Wiper.cpp
 *
 *  Created on: 22.06.2015
 *      Author: Moritz Scholjegerdes
 */

#include "Wiper.h"

#include "Wiping.h"
#include "Arduino.h"
#include "L298.h"
#include "../BugWiper.h"

Wiper::Wiper ()
{

}

void
Wiper::fullWipe ()
{
  byte safe;
  byte direction;
  // to do: read direction
  safe = full_wiping.w_wiping (direction);
  if (safe == 0)
    {
      led1.on ();
    }
  else
    {
      // to do: toggle direction
    }

}

void
Wiper::TieUp ()
{
  byte safe;
  byte direction;
  // to do: read direction
  safe = tieing_up.w_wiping (direction);
  if (safe == 0)
    {
      led1.on ();
    }
}
