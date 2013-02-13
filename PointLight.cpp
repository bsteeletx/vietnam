#include "PointLight.h"
#include "agk.h"

unsigned int PointLight::lightCounter;

PointLight::PointLight(void)
{
	lightID = 0;
}

PointLight::PointLight(Point Location, float radius, RGBA Color)
{
	if (agk::GetLightPointExists(lightCounter) == 1)
		lightID = ++lightCounter;
	else
		lightID = 1;

	agk::CreateLightPoint(lightID, Location.getX(), Location.getY(), Location.getZ(), radius, Color.getRed(), Color.getGreen(), Color.getBlue());
}


PointLight::~PointLight(void)
{
}

PointLight::PointLight(float x, float y, float z, float radius, RGBA Color)
{
	if (agk::GetLightPointExists(lightCounter) == 1)
		lightID = ++lightCounter;
	else
		lightID = 1;

	agk::CreateLightPoint(lightID, x, y, z, radius, Color.getRed(), Color.getGreen(), Color.getBlue());
}


void PointLight::clear(void)
{
	agk::ClearLightPoints();
}
	
bool PointLight::getExists(void)
{
	if (agk::GetLightPointExists(lightID))
		return true;

	return false;
}

void PointLight::setColor(RGBA Value)
{
	agk::SetLightPointColor(lightID, Value.getRed(), Value.getGreen(), Value.getBlue());
}

void PointLight::setPosition(Point Location)
{
	agk::SetLightPointPosition(lightID, Location.getX(), Location.getY(), Location.getZ());
}
	
void PointLight::setPosition(float x, float y, float z)
{
	agk::SetLightPointPosition(lightID, x, y, z);
}
	
void PointLight::setRadius(float value)
{
	agk::SetLightPointRadius(lightID, value);
}