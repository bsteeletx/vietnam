#include "2DPhysicsForce.h"
#include "agk.h"

Force::Force(void)
{
	_forceID = 0;
}

Force::~Force(void)
{
	//agk::DeletePhysicsForce(forceID);
}

Force::Force(Point Location, float power, float limit, float range, bool fade)
{
	_Create(Location, power, limit, range, fade);
}

void Force::Delete()
{
	agk::DeletePhysicsForce(_forceID);
}

void Force::SetPosition(Point Location)
{
	agk::SetPhysicsForcePosition(_forceID, Location.GetX(), Location.GetY());
}

void Force::SetPower(float powerInNewtons)
{
	agk::SetPhysicsForcePower(_forceID, powerInNewtons);
}

void Force::SetRange(float range)
{
	agk::SetPhysicsForceRange(_forceID, range);
}

void Force::_Create(Point Location, float power, float limit, float range, bool fade)
{
	if (fade)
		_forceID = agk::CreatePhysicsForce(Location.GetX(), Location.GetY(), power, limit, range, 1);
	else
		_forceID = agk::CreatePhysicsForce(Location.GetX(), Location.GetY(), power, limit, range, 1);
}