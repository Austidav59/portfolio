/***********************************************************************
 * Header File:
 *    LANDER
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the information about the lunar lander
 ************************************************************************/
#pragma once

#include "position.h"
#include "velocity.h"
#include "angle.h"
#include "thrust.h"
#include "uiDraw.h"
#include "ground.h"

#define LANDER_WIDTH           20     // width of the lander
#define MAX_SPEED               4.0   // maximum speed to land
#define LANDER_WEIGHT       15103.00  // weight of the lander in KG
#define LANDER_THRUST       45000.00  // thrust of the main engine in Newtons
#define FUEL_MAIN_THRUST       10.0   // amount of fuel consumed by the main thruster
#define FUEL_ROTATE             1.0   // amount of fuel consumed by the rotation thrusters
#define FUEL_MAX             5000.0   // total amount of fuel

enum Status { PLAYING, SAFE, DEAD };

class TestLander;

class Lander
{
   friend TestLander;

public:
   // Constructor
   Lander(const Position& posUpperRight) : status(PLAYING) { reset(posUpperRight); }
   
   double getAngle() const { return angle.getRadians(); }
   double getAltitude() const { return pos.getY(); }
    bool landedTooHard() const { return velocity.getSpeed() > MAX_SPEED; }
    bool checkGroundCollision(const Ground& ground) const;
   void turnUpsideDown() { angle.setDown(); }
   void reset(const Position& posUpperRight);

   // Getters
   bool     isDead()       const { return status == DEAD;      }
   bool     isLanded()     const { return status == SAFE;      }
   bool     isFlying()     const { return status == PLAYING;   }
   Position getPosition()  const { return pos;                 }
   double   getSpeed()     const { return velocity.getSpeed(); }
   int      getFuel()      const { return (int)fuel;           }
   int      getWidth()     const { return LANDER_WIDTH;        }
   double   getMaxSpeed()  const { return MAX_SPEED;           }

   // Draw the lander
   void draw(const Thrust& thrust, ogstream& gout) const;

   // Handle input and physics
   Acceleration input(const Thrust& thrust, double gravity);
   void coast(Acceleration& acceleration, double time);
   void land() {
      angle.setUp();
      status = SAFE;
   }

   void crash() {
      status = DEAD;
      angle.setDown();
   }

private:
   Status   status;
   Position pos;
   Velocity velocity;
   Angle    angle;
   double   fuel;
};
