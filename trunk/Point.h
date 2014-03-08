#pragma once

//#include "Vector.h"
#include "../Defines.h"

class Point
{
public:
	Point();
	Point(float loc_x, float loc_y, float loc_z = 0.0f, float lowValue = 0.0f, float hiValue = 100.0f);
	~Point(void);

	bool operator== (const Point ComparePoint);
	friend Point operator+ (const Point &Point1, const Point &Point2);
	friend Point operator- (const Point &Point1, const Point &Point2);

	Point AddPoint(Point Additive);
	
	void Floor(void);

	float GetMaxValue(void);
	float GetMinValue(void);
	float GetX(void);
	float GetY(void);
	float GetZ(void);
#if GRIDGAME == 1
	Point GetGridCoords(void);
	Point GetNormalCoords(void);
#endif
	Point GetScreenFrom3D(void);
	float GetScreenXFrom3D(void);
	float GetScreenYFrom3D(void);

#if GRIDGAME == 1
	void SetCoordsAsGridCoords(void);
#endif
	void SetCoords(float loc_x, float loc_y, float loc_z = 0.0f);
	void SetMaxValue(float value);
	void SetMinValue(float value);
	void SetX(float loc_x);
	void SetY(float loc_y);
	void SetZ(float loc_z);


protected:
	float _x;
	float _y;
	float _z;

private:
	float _maxValue;
	float _minValue;

	float _ContainCoord(float coord);
	void _ContainCoords(float coords[]);
};