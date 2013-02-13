#pragma once

#include "RGBA.h"
#include "Vector.h"

class DirectionalLight
{
public:
	DirectionalLight(void);
	~DirectionalLight(void);
	DirectionalLight(Vector Direction, RGBA Color);

	void clear(void);

	bool getExists(void);

	void setColor(RGBA Value);
	void setDirection(Vector Direction);

private:
	static unsigned int lightCounter;
	unsigned int lightID;
};

