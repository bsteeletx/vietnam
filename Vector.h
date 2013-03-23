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
	Point getDirection(void);
	Point getEndPoint(void);
	float getEndPointX(void);
	float getEndPointY(void);
	float getEndPointZ(void);
	Point getStartPoint(void);
	float getStartPointX(void);
	float getStartPointY(void);
	float getStartPointZ(void);
	Point getVelocity(void);
	float getVelocityInX(void);
	float getVelocityInY(void);
	float getVelocityInZ(void);
	
	void setStartPoint(Point Begin);
	void setFinishPoint(Point End);
	void setVectorPoints(Point Begin, Point End);

private:
	Point Start;
	Point Finish;
};