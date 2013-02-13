#pragma once

#include "Text.h"
#include "Point.h"

class Touch
{
public:
	Touch(void);
	~Touch(void);
	
	bool getMultiTouchExists(void);
	unsigned int getRawFirstTouchEvent(bool includeUnknown = false);
	unsigned short getRawTouchCount(bool includeUnknown = false);
	Point getRawTouchCurrent(void);
	float getRawTouchCurrentX(void);
	float getRawTouchCurrentY(void);
	Point getRawTouchLast(void);
	float getRawTouchLastX(void);
	float getRawTouchLastY(void);
	bool getRawTouchReleased(void);
	Point getRawTouchStart(void);
	float getRawTouchStartX(void);
	float getRawTouchStartY(void);
	float getRawTouchTime(void);
	int getRawTouchValue(void);
	unsigned int getRawNextTouchEvent(void);

	void setRawTouchValue(int value);

private:
	unsigned int touchID;
};

