#include "Vector.h"

Vector::Vector(void)
{
}

Vector::Vector(Point Begin, Point End)
{
	if (End == Point())
	{//so you can only give one value if necessary
		_Finish = Begin;
		_Start = Point();
	}
	else
	{
		_Start = Begin;
		_Finish = End;
	}
}

Vector::~Vector(void)
{
}

Vector& Vector::operator= (const Vector& newVector)
{
	_Start = newVector._Start;
	_Finish = newVector._Finish;

	return *this;
}

/*bool operator== (Vector& First, Vector& Second)
{
	if (First._Start == Second._Start)
	{
		if (First._Finish == Second._Finish)
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

Point Vector::GetDirection(void)
{
	return Point(GetEndPointX() - GetStartPointX(), GetEndPointY() - GetStartPointY(), GetEndPointZ() - GetStartPointZ());
}

Point Vector::GetEndPoint(void)
{
	return _Finish;
}

float Vector::GetEndPointX(void)
{
	return _Finish.GetX();
}

float Vector::GetEndPointY(void)
{
	return _Finish.GetY();
}

float Vector::GetEndPointZ(void)
{
	return _Finish.GetZ();
}

Point Vector::GetStartPoint(void)
{
	return _Start;
}

float Vector::GetStartPointX(void)
{
	return _Start.GetX();
}

float Vector::GetStartPointY(void)
{
	return _Start.GetY();
}

float Vector::GetStartPointZ(void)
{
	return _Start.GetZ();
}

Point Vector::GetVelocity(void)
{
	Point ReturnPoint = Point();
	ReturnPoint.SetX(GetVelocityInX());
	ReturnPoint.SetY(GetVelocityInY());
	ReturnPoint.SetZ(GetVelocityInZ());

	return ReturnPoint;
}

float Vector::GetVelocityInX(void)
{
	return _Finish.GetX() - _Start.GetX();
}

float Vector::GetVelocityInY(void)
{
	return _Finish.GetY() - _Start.GetY();
}

float Vector::GetVelocityInZ(void)
{
	return _Finish.GetZ() - _Start.GetZ();
}

void Vector::SetStartPoint(Point Begin)
{
	_Start = Begin;
}

void Vector::SetFinishPoint(Point End)
{
	_Finish = End;
}

void Vector::SetVectorPoints(Point Begin, Point End)
{
	_Start = Begin;
	_Finish = End;
}