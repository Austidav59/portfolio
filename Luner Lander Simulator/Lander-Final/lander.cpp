/***********************************************************************
* Source File:
*    LANDER
* Author:
*    Br. Helfrich
* Summary:
*    All the information about the lunar lander
************************************************************************/
#include "lander.h"
#include "acceleration.h"
#include <cmath>
#include <iostream>
#include "ground.h"

void Lander::reset(const Position& posUpperRight)
{
   angle.setUp();  
   velocity.setDX(random(-10.0, -4.0));
   velocity.setDY(random(-2.0, 2.0));
   pos.setX(posUpperRight.getX() - 1.0);
   pos.setY(random(posUpperRight.getY() * 0.75, posUpperRight.getY() * 0.95)); 
   status = PLAYING;
   fuel = FUEL_MAX;
}

void Lander::draw(const Thrust& thrust, ogstream& gout) const
{
   gout.drawLander(pos, angle.getRadians());
   
   if (isFlying() && fuel > 0.0)
      gout.drawLanderFlames(pos, angle.getRadians(),
         thrust.isMain(), thrust.isClock(), thrust.isCounter());
}

Acceleration Lander::input(const Thrust& thrust, double gravity)
{
    Acceleration a;
    
    // Apply gravity
    a.addDDY(gravity);
    
    // If there's no fuel, only gravity affects the lander
    if (fuel <= 0.0)
    {
        fuel = 0.0;  // Ensure fuel doesn't go negative
        return a;
    }
    
    // Main thruster
    if (thrust.isMain())
    {
        double power = (LANDER_THRUST / LANDER_WEIGHT);
        a.addDDX(-sin(angle.getRadians()) * power);
        a.addDDY(cos(angle.getRadians()) * power);
        fuel -= FUEL_MAIN_THRUST;
    }
    
    // Clockwise rotation thruster
    if (thrust.isClock())
    {
        angle.add(0.1);  // Rotate clockwise
        fuel -= FUEL_ROTATE;
    }
    
    // Counter-clockwise rotation thruster
    if (thrust.isCounter())
    {
        angle.add(-0.1);  // Rotate counter-clockwise
        fuel -= FUEL_ROTATE;
    }
    
    // Ensure fuel doesn't go negative
    if (fuel < 0.0)
        fuel = 0.0;
    
    return a;
}

void Lander::coast(Acceleration& acceleration, double time) {
    // Update position
    pos.addX(velocity.getDX() * time + 0.5 * acceleration.getDDX() * time * time);
    pos.addY(velocity.getDY() * time + 0.5 * acceleration.getDDY() * time * time);
    
    // Update velocity
    velocity.add(acceleration, time);

    // Check for landing or crash
    if (pos.getY() <= 0)
    {
        if (landedTooHard())
        {
            crash();
        }
        else
        {
            land();
        }
    }
}


bool Lander::checkGroundCollision(const Ground& ground) const
{
    return ground.hitGround(pos, getWidth());
}

