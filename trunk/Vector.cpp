#include "Vector.h"

Vector::Vector(void)
{
}

Vector::Vector(Point Begin, Point End)
{
	if (End == Point())
	{//so you can only give one value if necessary
		Finish = Begin;
		Start = Point();
	}
	else
	{
		Start = Begin;
		Finish = End;
	}
}

Vector::~Vector(void)
{
}

Vector& Vector::operator= (const Vector& newVector)
{
	Start = newVector.Start;
	Finish = newVector.Finish;

	return *this;
}

/*bool operator== (Vector& First, Vector& Second)
{
	if (First.Start == Second.Start)
	{
		if (First.Finish == Second.Finish)
			return true;
	}

	return false;
}

bool operator!= (Vector& First, Vector& Second)
{
	if (First == Second)
		return false;
	
	return true;
}*/

Point Vector::getDirection(void)
{
	return Point(getEndPointX() - getStartPointX(), getEndPointY() - getStartPointY(), getEndPointZ() - getStartPointZ());
}

Point Vector::getEndPoint(void)
{
	return Finish;
}

float Vector::getEndPointX(void)
{
	return Finish.getX();
}

float Vector::getEndPointY(void)
{
	return Finish.getY();
}

float Vector::getEndPointZ(void)
{
	return Finish.getZ();
}

Point Vector::getStartPoint(void)
{
	return Start;
}

float Vector::getStartPointX(void)
{
	return Start.getX();
}

float Vector::getStartPointY(void)
{
	return Start.getY();
}

float Vector::getStartPointZ(void)
{
	return Start.getZ();
}

Point Vector::getVelocity(void)
{
	Point ReturnPoint = Point();
	ReturnPoint.setX(getVelocityInX());
	ReturnPoint.setY(getVelocityInY());
	ReturnPoint.setZ(getVelocityInZ());

	return ReturnPoint;
}

float Vector::getVelocityInX(void)
{
	return Finish.getX() - Start.getX();
}

float Vector::getVelocityInY(void)
{
	return Finish.getY() - Start.getY();
}

float Vector::getVelocityInZ(void)
{
	return Finish.getZ() - Start.getZ();
}

void Vector::setStartPoint(Point Begin)
{
	Start = Begin;
}

void Vector::setFinishPoint(Point End)
{
	Finish = End;
}

void Vector::setVectorPoints(Point Begin, Point End)
{
	Start = Begin;
	Finish = End;
}