/***********************************************************************
 * Source File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#include "angle.h"
#include <math.h>  // for floor()
#include <cassert>
using namespace std;

/************************************
 * ANGLE : NORMALIZE
 ************************************/
double Angle::normalize(double radians) const {
   if (radians >= (M_PI * 2.0)) {
      double multiples = floor(radians / (M_PI * 2.0));
      assert(radians - (M_PI * 2.0) * multiples >= 0.0);
      assert(radians - (M_PI * 2.0) * multiples <= (M_PI * 2.0));
      return radians - ((M_PI * 2.0) * multiples);
   }
   else if (radians < 0.0) {
      double multiples = ceil(-radians / (M_PI * 2.0));
      assert((M_PI * 2.0) * multiples + radians >= 0.0);
      assert((M_PI * 2.0) * multiples + radians <= (M_PI * 2.0));
      return (M_PI * 2.0) * multiples + radians;
   }
   assert(0.0 <= radians && radians <= (M_PI * 2.0));
   return radians;
}



