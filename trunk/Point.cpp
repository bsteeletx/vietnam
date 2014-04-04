#include "Point.h"
#include "agk.h"
#include "../Source/Defines.h"

Point::Point()
{
	_x = 0.0f;
	_y = 0.0f;
	_z = 0.0f;
	_minValue = -100.0f;
	_maxValue = 200.0f;
}

Point::Point(float loc_x, float loc_y, float loc_z, float lowValue, float hiValue)
{
	_x = loc_x;
	_y = loc_y;
	_z = loc_z;
	_minValue = lowValue;
	_maxValue = hiValue;
}

Point::~Point(void)
{
}

Point& Point::operator= (const Point& NewPoint)
{
	_x = NewPoint._x;
	_y = NewPoint._y;
	_z = NewPoint._z;
	_minValue = NewPoint._minValue;
	_maxValue = NewPoint._maxValue;

	return *this;
}

bool Point::operator== (Point ComparePoint)
{
	if (_x != ComparePoint.GetX())
		return false;
	if (_y != ComparePoint.GetY())
		return false;
	if (_z != ComparePoint.GetZ())
		return false;

	return true;
}

Point operator+ (const Point &Point1, const Point &Point2)
{
	return Point(Point1._x + Point2._x, Point1._y + Point2._y);
}

Point operator- (const Point &Point1, const Point &Point2)
{
	return Point(Point1._x - Point2._x, Point1._y - Point2._y);
}

Point Point::AddPoint(Point Additive)
{
	Point Start = *this;

	Start._x += Additive._x;
	Start._y += Additive._y;
	Start._z += Additive._z;

	*this = Start;

	return Start;
}

void Point::Floor(void)
{
	_x = (float) agk::Floor(_x);
	_y = (float) agk::Floor(_x);
	_z = (float) agk::Floor(_x);
}

/*Point Point::Get3DFromScreen(void)
{
	return Point(Get3DXFromScreen(), Get3DYFromScreen(), Get3DZFromScreen());
}

float Point::Get3DXFromScreen(void)
{
	return agk::Get3DVectorXFromScreen(x, y);
}

float Point::Get3DYFromScreen(void)
{
	return agk::Get3DVectorYFromScreen(x, y);
}

float Point::get3DZFromScreen(void)
{
	return agk::Get3DVectorZFromScreen(x, y);
} */

float Point::GetMaxValue(void)
{
	return _maxValue;
}

float Point::GetMinValue(void)
{
	return _minValue;
}

Point Point::GetScreenFrom3D(void)
{
	return Point(GetScreenXFrom3D(), GetScreenYFrom3D());
}

float Point::GetScreenXFrom3D(void)
{
	return agk::GetScreenXFrom3D(_x, _y, _z);
}

float Point::GetScreenYFrom3D(void)
{
	return agk::GetScreenYFrom3D(_x, _y, _z);
}

float Point::GetX(void)
{
	return _x;
}

float Point::GetY(void)
{
	return _y;
}

float Point::GetZ(void)
{
	return _z;
}

#if GRIDGAME == 1
Point Point::GetGridCoords(void)
{
	float xLoc = 0.0f;
	float yLoc = 0.0f;

	if (y < YBEG - SPOT_BORDER_Y - 1.0f)
	{
		xLoc = (_x - XBEG_MENU + MENU_BORDER)/(SPOT_WIDTH);
		yLoc = -1.0f;

		if (xLoc > XMAX)
			xLoc = XMAX;
	}
	else
	{
		xLoc = (_x - XBEG - SPOT_BORDER_X)/(SPOT_WIDTH);
		yLoc = (_y - YBEG - SPOT_BORDER_Y)/SPOT_HEIGHT;
	}

	return Point(agk::Round(xLoc), agk::Round(yLoc));
}

Point Point::GetNormalCoords(void)
{
	float xLoc = _x;
	float yLoc = _y;
	
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
			xLoc = _x*(SPOT_WIDTH) + XBEG_MENU;
	}
		
	
	return Point(xLoc, yLoc);
}

void Point::SetCoordsAsGridCoords(void)
{
	/*x = (int) ((x - XBEG)/(SPOT_WIDTH + SPOT_BORDER));
	y = ((y - YBEG)/(SPOT_HEIGHT + SPOT_BORDER));

	if (y < 0.0f)
		y = -1.0f;
	else
		y = (int) y;*/

	*this = Point(GetGridCoords());
}
#endif

void Point::SetCoords(float loc_x, float loc_y, float loc_z)
{
	float values[3] = {loc_x, loc_y, loc_z};
	
	_ContainCoords(values);

	_x = values[0];
	_y = values[1];
	_z = values[2];
}

void Point::SetX(float loc_x)
{
	_x = _ContainCoord(loc_x);
}

void Point::SetY(float loc_y)
{
	_y = _ContainCoord(loc_y);
}

void Point::SetZ(float loc_z)
{
	_z = _ContainCoord(loc_z);
}

float Point::_ContainCoord(float coord)
{
	if (coord < _minValue)
		return _minValue;
	else if (coord > _maxValue)
		return _maxValue;
	else
		return coord;
}

void Point::_ContainCoords(float coords[])
{
	for (int i = 0; i < 3; i++)
		coords[i] = _ContainCoord(coords[i]);
}