#include "Point.h"
#include "agk.h"
#include "../Defines.h"

Point::Point()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	minValue = -100.0f;
	maxValue = 200.0f;
}

Point::Point(float loc_x, float loc_y, float loc_z, float lowValue, float hiValue)
{
	x = loc_x;
	y = loc_y;
	z = loc_z;
	minValue = lowValue;
	maxValue = hiValue;
}

Point::~Point(void)
{
}

Point Point::addPoint(Point Additive)
{
	Point Start = *this;

	Start.x += Additive.x;
	Start.y += Additive.y;
	Start.z += Additive.z;

	return Start;
}

void Point::floor(void)
{
	x = (float) agk::Floor(x);
	y = (float) agk::Floor(x);
	z = (float) agk::Floor(x);
}

Point Point::get3DFromScreen(void)
{
	return Point(get3DXFromScreen(), get3DYFromScreen(), get3DZFromScreen());
}

float Point::get3DXFromScreen(void)
{
	return agk::Get3DVectorXFromScreen(x, y);
}

float Point::get3DYFromScreen(void)
{
	return agk::Get3DVectorYFromScreen(x, y);
}

float Point::get3DZFromScreen(void)
{
	return agk::Get3DVectorZFromScreen(x, y);
}

float Point::getMaxValue(void)
{
	return maxValue;
}

float Point::getMinValue(void)
{
	return minValue;
}

Point Point::getScreenFrom3D(void)
{
	return Point(getScreenXFrom3D(), getScreenYFrom3D());
}

float Point::getScreenXFrom3D(void)
{
	return agk::GetScreenXFrom3D(x, y, z);
}

float Point::getScreenYFrom3D(void)
{
	return agk::GetScreenYFrom3D(x, y, z);
}

float Point::getX(void)
{
	return x;
}

float Point::getY(void)
{
	return y;
}

float Point::getZ(void)
{
	return z;
}
#ifdef GRIDGAME
Point Point::getGridCoords(void)
{
	float xLoc = 0.0f;
	float yLoc = 0.0f;

	/*if (y < 0)
	{
		xLoc = (x - 5.0f)/(SPOT_WIDTH + SPOT_BORDER);
		yLoc = y;
	}
	else
	{*/
	xLoc = agk::Round((x - XBEG)/(SPOT_WIDTH + SPOT_BORDER));
	yLoc = (y - YBEG)/(SPOT_HEIGHT + SPOT_BORDER);
	//}

	return Point((int) xLoc, (int) yLoc);
}

Point Point::getNormalCoords(void)
{
	float xLoc = x;
	float yLoc = y;
	//Point ReturnPoint = Point();

	xLoc = xLoc*(SPOT_WIDTH + SPOT_BORDER) + XBEG;
	yLoc = yLoc*(SPOT_HEIGHT + SPOT_BORDER)+ YBEG;

	if (xLoc < XBEG)
		xLoc = XBEG;
	if (yLoc < YBEG - SPOT_HEIGHT + SPOT_BORDER)
		yLoc = YBEG - SPOT_HEIGHT + SPOT_BORDER;
	if (xLoc > XMAX*(SPOT_WIDTH + SPOT_BORDER) + XBEG)
		xLoc = XMAX*(SPOT_WIDTH + SPOT_BORDER) + XBEG;
	if (yLoc > YMAX*(SPOT_HEIGHT + SPOT_BORDER) + YBEG)
		yLoc = YMAX*(SPOT_HEIGHT + SPOT_BORDER) + YBEG;

	//ReturnPoint.setX(agk::Floor(agk::Get3DVectorXFromScreen(x, y)));
	//ReturnPoint.setY(agk::Floor(agk::Get3DVectorYFromScreen(x, y)));
	//ReturnPoint.setZ(agk::Floor(agk::Get3DVectorZFromScreen(x, y)));

	/*float newX = 15.0f;
	float newY = 60.5f;
	bool increasingXUp = false;

	newX += (x*10.0f); //10 across the bottom
	newY += (y - 1)*(2.0f - x)*2.0f;

	if (x < 4)
		increasingXUp = true;
	
	if (increasingXUp)
	{
		newX -= y*6.75f;
		newX += (4.0f - x)*3.75f;
	}
	else
	{
		if (x == 0)
			newX += (y*3.5f); //even the center increases this much per row
		else
			newX -= ((4 - x) * ((4 - x)/5));
	}

	if (y < 0)
		ReturnPoint = Point(5.0f + (x*10.0f), 5.0f);
	else
		ReturnPoint = Point(newX, newY);*/
	
	return Point(xLoc, yLoc);
}

void Point::setCoordsAsGridCoords(void)
{
	/*x = (int) ((x - XBEG)/(SPOT_WIDTH + SPOT_BORDER));
	y = ((y - YBEG)/(SPOT_HEIGHT + SPOT_BORDER));

	if (y < 0.0f)
		y = -1.0f;
	else
		y = (int) y;*/

	*this = Point(getGridCoords());
}
#endif

void Point::setCoords(float loc_x, float loc_y, float loc_z)
{
	float values[3] = {loc_x, loc_y, loc_z};
	
	containCoords(values);

	x = values[0];
	y = values[1];
	z = values[2];
}

void Point::setX(float loc_x)
{
	x = containCoord(loc_x);
}

void Point::setY(float loc_y)
{
	y = containCoord(loc_y);
}

void Point::setZ(float loc_z)
{
	z = containCoord(loc_z);
}

float Point::containCoord(float coord)
{
	if (coord < minValue)
		return minValue;
	else if (coord > maxValue)
		return maxValue;
	else
		return coord;
}

void Point::containCoords(float coords[])
{
	for (int i = 0; i < 3; i++)
		coords[i] = containCoord(coords[i]);
}