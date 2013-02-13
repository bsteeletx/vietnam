#include "DirectionalLight.h"
#include "agk.h"

unsigned int DirectionalLight::lightCounter = 0;

DirectionalLight::DirectionalLight(void)
{
	lightID = 0;
}


DirectionalLight::~DirectionalLight(void)
{
}

DirectionalLight::DirectionalLight(Vector Direction, RGBA Color)
{
	lightID = ++lightCounter;
	float dirX = Direction.getDirection().getX();
	float dirY = Direction.getDirection().getY();
	float dirZ = Direction.getDirection().getZ();

	agk::CreateLightDirectional(lightID, dirX, dirY, dirZ, Color.getRed(), Color.getGreen(), Color.getBlue());
}

void DirectionalLight::clear(void)
{
	agk::ClearLightDirectionals();
}

bool DirectionalLight::getExists(void)
{
	if (agk::GetLightDirectionalExists(lightID)== 1)
		return true;
	
	return false;
}

void DirectionalLight::setColor(RGBA Value)
{
	agk::SetLightDirectionalColor(lightID, Value.getRed(), Value.getGreen(), Value.getBlue());
}

void DirectionalLight::setDirection(Vector Direction)
{
	float dirX = Direction.getDirection().getX();
	float dirY = Direction.getDirection().getY();
	float dirZ = Direction.getDirection().getZ();

	agk::SetLightDirectionalDirection(lightID, dirX, dirY, dirZ);
}