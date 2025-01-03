/***********************************************************************
* Source File:
* POSITION
* Author:
* Br. Helfrich
* Summary:
* Everything we need to know about a location on the screen.
************************************************************************/
#include "position.h"
#include "velocity.h"
#include "acceleration.h"


/******************************************
* POSITION : CONSTRUCTOR WITH X,Y
* Initialize the position to the passed coordinates
*****************************************/
Position::Position(double x, double y) : x(0.0), y(0.0) {
	setX(x);
	setY(y);
}


/******************************************
* POSITION : ADD
* Update position based on velocity and acceleration over time
* Using the equation: s = s_0 + vt + 1/2 a t^2
*****************************************/
void Position::add(const Acceleration& a, const Velocity& v, double t) {
    x += v.getDX() * t + 0.5 * a.getDDX() * t * t;
    y += v.getDY() * t + 0.5 * a.getDDY() * t * t;
}

void Position::addX(double dx) {
    this->x += dx;
}

void Position::addY(double dy) {
    this->y += dy;
}
