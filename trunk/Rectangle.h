#pragma once

#include "Point.h"
#include "Vector.h"

class RectangleBounds
{

public:
	RectangleBounds(Point TopLeft, Point BottomRight);
	RectangleBounds();
	~RectangleBounds(void);

	RectangleBounds& operator= (const RectangleBounds& newRectangle);

	bool ContainsPoint(Point ToCheck);

	float GetBottom();
	Point GetBottomLeft();
	Point GetBottomRight();
	bool GetCrossedBottom();
	bool GetCrossedLeft();
	bool GetCrossedRight();
	bool GetCrossedTop();
	unsigned short GetCrossings();
	float GetLeft();
	bool GetLineIntersects(Vector Line);
	float GetRight();
	float GetTop();
	Point GetTopLeft();
	Point GetTopRight();

private:
	Point *_TopLeft;
	Point *_BottomRight;
	bool _crossesBottom;
	bool _crossesLeft;
	bool _crossesRight;
	bool _crossesTop;

	bool _GetContainsLine(Vector Line);
	bool _GetLineIntersectsLine(Vector First, Vector Second);
};