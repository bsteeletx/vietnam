#include "Physics2D.h"
#include "agk.h"

Physics2D::Physics2D(void)
{
}


Physics2D::~Physics2D(void)
{
}

unsigned int Physics2D::getContactSpriteID1(void)
{
	return agk::GetContactSpriteID1();
}

unsigned int Physics2D::getContactSpriteID2(void)
{
	return agk::GetContactSpriteID2();
}

Point Physics2D::getContactWorld(void)
{
	return Point(getContactWorldX(), getContactWorldY());
}

float Physics2D::getContactWorldX(void)
{
	return agk::GetContactWorldX();
}

float Physics2D::getContactWorldY(void)
{
	return agk::GetContactWorldY();
}

bool Physics2D::getFirstContact(void)
{
	if (agk::GetFirstContact())
		return true;

	return false;
}

bool Physics2D::getNextContact(void)
{
	if (agk::GetNextContact())
		return true;

	return false;
}

unsigned short Physics2D::getIslandCount(void)
{
	return agk::GetPhysicsIslandCount();
}

float Physics2D::getSolveTime(void)
{
	return agk::GetPhysicsSolveTime();
}

unsigned int Physics2D::getSpriteContactID2(void)
{
	return agk::GetSpriteContactSpriteID2();
}

Point Physics2D::getSpriteContactWorld(void)
{
	return Point(getSpriteContactWorldX(), getSpriteContactWorldY());
}

float Physics2D::getSpriteContactWorldX(void)
{
	return agk::GetSpriteContactWorldX();
}

float Physics2D::getSpriteContactWorldY(void)
{
	return agk::GetSpriteContactWorldY();
}

bool Physics2D::getSpriteFirstContact(Sprite Object)
{
	if (agk::GetSpriteFirstContact(Object.getID()))
		return true;

	return false;
}

bool Physics2D::getSpriteNextContact(void)
{
	if (agk::GetSpriteNextContact())
		return true;

	return false;
}

void Physics2D::setCCD(bool isOn)
{
	agk::SetPhysicsCCD(isOn);
}

void Physics2D::setDebug(bool isDebug)
{
	if (isDebug)
		agk::SetPhysicsDebugOn();
	else
		agk::SetPhysicsDebugOff();
}

void Physics2D::setGravity(float x, float y)
{
	agk::SetPhysicsGravity(x, y);
}

void Physics2D::setMaxPolygonPoints(unsigned short value)
{
	if (value > 12)
		agk::SetPhysicsMaxPolygonPoints(8);
	else if (value < 2)
		agk::SetPhysicsMaxPolygonPoints(2);
	else
		agk::SetPhysicsMaxPolygonPoints(value);
}

void Physics2D::setScale(float value)
{
	agk::SetPhysicsScale(value);
}

void Physics2D::setSleeping(bool isSleeping)
{
	agk::SetPhysicsSleeping((int) isSleeping);
}

void Physics2D::setThreading(short numOfThreads)
{
	agk::SetPhysicsThreading(numOfThreads);
}

void Physics2D::setWalls(bool bottom, bool left, bool right, bool top)
{
	setWallBottom(bottom);
	setWallLeft(left);
	setWallRight(right);
	setWallTop(top);
}

void Physics2D::setWallBottom(bool isOn)
{
	agk::SetPhysicsWallBottom((int) isOn);
}

void Physics2D::setWallLeft(bool isOn)
{
	agk::SetPhysicsWallLeft((int) isOn);
}

void Physics2D::setWallRight(bool isOn)
{
	agk::SetPhysicsWallRight((int) isOn);
}

void Physics2D::setWallTop(bool isOn)
{
	agk::SetPhysicsWallTop((int) isOn);
}