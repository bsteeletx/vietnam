#include "Quaternion.h"


Quaternion::Quaternion(void)
{
	wRot = xRot = yRot = zRot = 0.0f;
}


Quaternion::~Quaternion(void)
{
}

Quaternion::Quaternion(float w, float x, float y, float z)
{
	wRot = w;
	xRot = x;
	yRot = y;
	zRot = z;
}

float Quaternion::getW(void)
{
	return wRot;
}

float Quaternion::getX(void)
{
	return xRot;
}

float Quaternion::getY(void)
{
	return yRot;
}

float Quaternion::getZ(void)
{
	return zRot;
}

void Quaternion::resetAllTo(float w, float x, float y, float z)
{
	wRot = w;
	xRot = x;
	yRot = y;
	zRot = z;
}
	
void Quaternion::setW(float value)
{
	wRot = value;
}

void Quaternion::setX(float value)
{
	xRot = value;
}

void Quaternion::setY(float value)
{
	yRot = value;
}

void Quaternion::setZ(float value)
{
	zRot = value;
}