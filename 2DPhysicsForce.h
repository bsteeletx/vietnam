#ifndef _2DPHYSICSFORCE_H_
#define _2DPHYSICSFORCE_H_

#include "Point.h"

class Force
{
public:
	Force();
	~Force();
	Force(Point Location, float power, float limit, float range, bool fade);

	void Delete();

	void SetPosition(Point Location);
	void SetPower(float powerInNewtons);
	void SetRange(float range);

private:
	unsigned int _forceID;

	void _Create(Point Location, float power, float limit, float range, bool fade);
};
#endif