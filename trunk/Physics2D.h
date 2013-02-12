#pragma once

#include "Point.h"
#include "Sprite.h"

class Physics2D
{
public:
	Physics2D(void);
	~Physics2D(void);

	unsigned int getContactSpriteID1(void);
	unsigned int getContactSpriteID2(void);
	Point getContactWorld(void);
	float getContactWorldX(void);
	float getContactWorldY(void);
	bool getFirstContact(void);
	bool getNextContact(void);
	unsigned short getIslandCount(void);
	float getSolveTime(void);
	unsigned int getSpriteContactID2(void);
	Point getSpriteContactWorld(void);
	float getSpriteContactWorldX(void);
	float getSpriteContactWorldY(void);
	bool getSpriteFirstContact(Sprite Object);
	bool getSpriteNextContact(void);
	
	void setCCD(bool isOn = false);
	void setDebug(bool isDebug);
	void setGravity(float x, float y);
	void setMaxPolygonPoints(unsigned short value);
	void setScale(float value);
	void setSleeping(bool isSleeping = true);
	void setThreading(short numOfThreads = -1);
	void setWalls(bool bottom, bool left, bool right, bool top);
	void setWallBottom(bool isOn = false);
	void setWallLeft(bool isOn = false);
	void setWallRight(bool isOn = false);
	void setWallTop(bool isOn = false);
};

