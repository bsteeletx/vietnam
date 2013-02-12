#pragma once

#include "Point.h"
#include "RGBA.h"

class PointLight
{
public:
	PointLight(void);
	PointLight(Point Location, float radius, RGBA Color);
	~PointLight(void);
	PointLight(float x, float y, float z, float radius, RGBA Color);

	void clear(void);

	bool getExists(void);

	void setColor(RGBA Value);
	void setPosition(Point Location);
	void setPosition(float x, float y, float z);
	void setRadius(float value);

protected:
	static unsigned int lightCounter;
	unsigned int lightID;
};

