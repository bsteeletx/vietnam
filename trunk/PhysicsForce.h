#pragma once

#include "Physics2D.h"
#include "Point.h"

class PhysicsForce : 
	public Physics2D
{
public:
	PhysicsForce();
	~PhysicsForce();
	PhysicsForce(Point Location, float power, float limit, float range, bool fade);

	void setPosition(Point Location);
	void setPower(float powerInNewtons);
	void setRange(float range);

private:
	unsigned int forceID;
};