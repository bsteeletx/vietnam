#pragma once

#include "../Defines.h"
#include "Object.h"
#include "Text.h"
#include "Vector.h"
#include "Point.h"

class RayCast
{
public:
	RayCast(void);
	~RayCast(void);
	RayCast(Object Casting, Vector Direction, float radius = 0.0f, bool useSlide = false);
	RayCast(Vector Direction, RayCastMode value, int catGroupSpriteID = 0);
	
	void category(unsigned short category);

	float getFraction(void);
	Point getNormal(void);
	float getNormalX(void);
	float getNormalY(void);
	Point getObjectBounce(void);
	float getObjectBounceX(void);
	float getObjectBounceY(void);
	float getObjectBounceZ(void);
	float getObjectDistance(void);
	unsigned int getObjectHitID(void);
	Point getObjectPosition(void);
	float getObjectX(void);
	float getObjectY(void);
	float getObjectZ(void);
	Point getObjectNormal(void);
	float getObjectNormalX(void);
	float getObjectNormalY(void);
	float getObjectNormalZ(void);
	unsigned short getObjectNumHits(void);
	Point getObjectSlide(void);
	float getObjectSlideX(void);
	float getObjectSlideY(void);
	float getObjectSlideZ(void);
	unsigned int getSpriteID(void);
	Point getPosition(void);
	float getX(void);
	float getY(void);
	

private:
	unsigned int rayCastID;
	unsigned short num2DHits;
};

