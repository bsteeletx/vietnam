#pragma once

#include "Point.h"

class Vector
{

public:
	Vector(Point Begin, Point End = Point());
	Vector();
	~Vector(void);

	Vector& operator= (const Vector& newVector);
	/*friend bool operator== (Vector& First, Vector& Second);
	friend bool operator!= (Vector& First, Vector& Second);*/
	Point GetDirection(void);
	Point GetEndPoint(void);
	float GetEndPointX(void);
	float GetEndPointY(void);
	float GetEndPointZ(void);
	Point GetStartPoint(void);
	float GetStartPointX(void);
	float GetStartPointY(void);
	float GetStartPointZ(void);
	Point GetVelocity(void);
	float GetVelocityInX(void);
	float GetVelocityInY(void);
	float GetVelocityInZ(void);
	
	void SetStartPoint(Point Begin);
	void SetFinishPoint(Point End);
	void SetVectorPoints(Point Begin, Point End);

private:
	Point _Start;
	Point _Finish;
};