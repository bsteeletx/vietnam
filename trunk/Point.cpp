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

bool Point::operator== (Point ComparePoint)
{
	if (x != ComparePoint.getX())
		return false;
	if (y != ComparePoint.getY())
		return false;
	if (z != ComparePoint.getZ())
		return false;

	return true;
}

Point operator+ (const Point &Point1, const Point &Point2)
{
	return Point(Point1.x + Point2.x, Point1.y + Point2.y);
}

Point operator- (const Point &Point1, const Point &Point2)
{
	return Point(Point1.x - Point2.x, Point1.y - Point2.y);
}

Point Point::addPoint(Point Additive)
{
	Point Start = *this;

	Start.x += Additive.x;
	Start.y += Additive.y;
	Start.z += Additive.z;

	*this = Start;

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

	if (y < YBEG - SPOT_BORDER_Y - 1.0f)
	{
		xLoc = (x - XBEG_MENU + MENU_BORDER)/(SPOT_WIDTH);
		yLoc = -1.0f;

		if (xLoc > XMAX)
			xLoc = XMAX;
	}
	else
	{
		xLoc = (x - XBEG - SPOT_BORDER_X)/(SPOT_WIDTH);
		yLoc = (y - YBEG - SPOT_BORDER_Y)/SPOT_HEIGHT;
	}

	return Point(agk::Round(xLoc), agk::Round(yLoc));
}

Point Point::getNormalCoords(void)
{
	float xLoc = x;
	float yLoc = y;
	
	xLoc = xLoc*(SPOT_WIDTH) + XBEG + SPOT_BORDER_X;
	yLoc = yLoc*(SPOT_HEIGHT) + YBEG + SPOT_BORDER_Y;

	if (y >= 0)
	{
		if (xLoc < XBEG + SPOT_BORDER_X)
			xLoc = XBEG + SPOT_BORDER_X;
		if (yLoc < YBEG - SPOT_HEIGHT + SPOT_BORDER_Y)
			yLoc = YBEG - SPOT_HEIGHT + SPOT_BORDER_Y;
		if (xLoc > XMAX*(SPOT_WIDTH) + XBEG + SPOT_BORDER_X)
			xLoc = XMAX*(SPOT_WIDTH) + XBEG + SPOT_BORDER_X;
		if (yLoc > YMAX*(SPOT_HEIGHT) + YBEG + SPOT_BORDER_Y)
			yLoc = YMAX*(SPOT_HEIGHT) + YBEG + SPOT_BORDER_Y;

		/*if (y == 0)
		{
			yLoc -= 1.0f;
			xLoc -= 0.1f;
		}*/
	}
	else
	{
		yLoc = MENU_Y;
		
		if (xLoc < XBEG_MENU)
			xLoc = XBEG_MENU;
		else if (xLoc > XMAX*(SPOT_WIDTH + MENU_BORDER) + XBEG_MENU)
			xLoc = XMAX*(SPOT_WIDTH + MENU_BORDER) + XBEG_MENU;
		else
			xLoc = x*(SPOT_WIDTH) + XBEG_MENU;
	}
		
	
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