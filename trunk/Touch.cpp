#include "Touch.h"
#include "agk.h"

Touch::Touch(void)
{
	touchID = agk::GetRawFirstTouchEvent(true);
}


Touch::~Touch(void)
{
}

bool Touch::getMultiTouchExists(void)
{
	if (agk::GetMultiTouchExists())
		return true;

	return false;
}

/*unsigned int Touch::getRawFirstTouchEvent(bool includeUnknown)
{
	return agk::GetRawFirstTouchEvent((int) includeUnknown);
}*/
	
unsigned short Touch::getRawTouchCount(bool includeUnknown)
{
	return agk::GetRawTouchCount((int) includeUnknown);
}

Point Touch::getRawTouchCurrent(void)
{
	return Point(getRawTouchCurrentX(), getRawTouchCurrentY());
}

float Touch::getRawTouchCurrentX(void)
{
	return agk::GetRawTouchCurrentX(touchID);
}

float Touch::getRawTouchCurrentY(void)
{
	return agk::GetRawTouchCurrentY(touchID);
}

Point Touch::getRawTouchLast(void)
{
	return Point(getRawTouchLastX(), getRawTouchLastY());
}

float Touch::getRawTouchLastX(void)
{
	return agk::GetRawTouchLastX(touchID);
}

float Touch::getRawTouchLastY(void)
{
	return agk::GetRawTouchLastY(touchID);
}

bool Touch::getRawTouchReleased(void)
{
	if (agk::GetRawTouchReleased(touchID))
		return true;

	return false;
}

Point Touch::getRawTouchStart(void)
{
	return Point(getRawTouchStartX(), getRawTouchStartY());
}

float Touch::getRawTouchStartX()
{
	return agk::GetRawTouchStartX(touchID);
}

float Touch::getRawTouchStartY(void)
{
	return agk::GetRawTouchStartY(touchID);
}

float Touch::getRawTouchTime(void)
{
	return agk::GetRawTouchTime(touchID);
}

int Touch::getRawTouchValue(void)
{
	return agk::GetRawTouchValue(touchID);
}

unsigned int Touch::getRawNextTouchEvent(void)
{
	return agk::GetRawNextTouchEvent();
}

void Touch::setRawTouchValue(int value)
{
	agk::SetRawTouchValue(touchID, value);
}
	
