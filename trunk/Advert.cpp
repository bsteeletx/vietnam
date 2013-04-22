#include "Advert.h"
#include "agk.h"

Advert::Advert(void)
{
}


Advert::~Advert(void)
{
}

Advert::Advert(int horzPos, int vertPos, bool test)
{
	setAdMobDetails("a151743d4c4b2b4");

	if (test)
		agk::CreateAdvert(0, horzPos, vertPos, 1);
	else
		agk::CreateAdvert(0, horzPos, vertPos, 0);
}

void Advert::requestRefresh(void)
{
	agk::RequestAdvertRefresh();
}

void Advert::setAdMobDetails(Text ID)
{
	char newString[64] = {NULL};

	if (ID.getLength() < 64)
		strcpy(newString, ID.getCString());

	agk::SetAdMobDetails(newString);
}

void Advert::setInneractiveDetails(Text Code)
{
	agk::SetInneractiveDetails(Code.getCString());
}

void Advert::setLocation(unsigned short horz, unsigned short vert, float width, float offsetX, float offsetY)
{
	agk::SetAdvertLocation(horz, vert, offsetX, offsetY, width);
}

void Advert::setPosition(Point Location, float width)
{
	agk::SetAdvertPosition(Location.getX(), Location.getY(), width);
}

void Advert::setPosition(float x, float y, float width)
{
	agk::SetAdvertPosition(x, y, width);
}

void Advert::setVisible(bool isVisible)
{
	if (isVisible)
		agk::SetAdvertVisible(1);
	else
		agk::SetAdvertVisible(0);
}