#pragma once

//#include "Vector.h"

class Point
{
public:
	Point();
	Point(float loc_x, float loc_y, float loc_z = 0.0f, float lowValue = 0.0f, float hiValue = 100.0f);
	~Point(void);

	bool operator== (const Point ComparePoint);

	Point addPoint(Point Additive);
	
	void floor(void);

	Point get3DFromScreen(void);
	float get3DXFromScreen(void);
	float get3DYFromScreen(void);
	float get3DZFromScreen(void);
	float getMaxValue(void);
	float getMinValue(void);
	float getX(void);
	float getY(void);
	float getZ(void);
	Point getGridCoords(void);
	Point getNormalCoords(void);
	Point getScreenFrom3D(void);
	float getScreenXFrom3D(void);
	float getScreenYFrom3D(void);

	void setCoordsAsGridCoords(void);
	void setCoords(float loc_x, float loc_y, float loc_z = 0.0f);
	void setMaxValue(float value);
	void setMinValue(float value);
	void setX(float loc_x);
	void setY(float loc_y);
	void setZ(float loc_z);


protected:
	float x;
	float y;
	float z;

private:
	float maxValue;
	float minValue;

	float containCoord(float coord);
	void containCoords(float coords[]);
};