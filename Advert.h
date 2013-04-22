#pragma once

#include "Text.h"
#include "Point.h"

class Advert
{
public:
	Advert(void);
	~Advert(void);
	Advert(int horzPos, int vertPos, bool test = false);

	void requestRefresh(void);

	void setAdMobDetails(Text ID);
	void setInneractiveDetails(Text Code);
	void setLocation(unsigned short horz, unsigned short vert, float width, float offsetX = 0.0f, float offsetY = 0.0f);
	void setPosition(Point Location, float width);
	void setPosition(float x, float y, float width);
	void setVisible(bool isVisible);
};

