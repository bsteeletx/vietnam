#pragma once

#include "Point.h"
#include "RGBA.h"
#include "Text.h"
#include "../Defines.h"

class GeneralCore
{
public:
	GeneralCore(void);
	~GeneralCore(void);

	float aCos(float value);
	float aCosRad(float value);
	float aSin(float value);
	float aSinRad(float value);
	float aTan(float value);
	float aTan2(float y, float x);
	float aTan2Rad(float y, float x);
	float aTanFull(float x, float y);
	float aTanFullRad(float x, float y);
	float aTanRad(float value);
	float abs(float value);
	unsigned int asc(char alpha);

	Text bin(int value);

	int ceil(float value);
	Text chr(unsigned int ascii);
	void clearDepthBuffer(void);
	void clearScreen(void);
	float cos(float value);
	float cosRad(float value);

	void enableClearColor(bool clearEachFrame);
	
	float fMod(float value, float modValue);
	int floor(float value);

	unsigned short getDeviceHeight(void);
	unsigned short getDeviceWidth(void);
	float getAspect(void);
	Orientation getOrientation(void);
	unsigned int getPolygonsDrawn(void);
	bool getResumed(void);
	float getScreenBoundsBottom(void);
	float getScreenBoundsLeft(void);
	float getScreenBoundsRight(void);
	float getScreenBoundsTop(void);
	unsigned int getVerticesProcessed(void);
	float getViewOffsetX(void);
	float getViewOffsetY(void);
	float getViewZoom(void);
	unsigned short getVirtualHeight(void);
	unsigned short getVirtualWidth(void);
	
	Text hex(int value);

	int mod(int value, int modValue);

	int random(void);
	int random(unsigned int from, unsigned int to);
	int randomSign(int value);
	void render(void);
	void render2DBack(void);
	void render2DFront(void);
	void render3D(void);
	int round(float value);
	
	float screenFPS(void);
	Point screenToWorld(Point ScreenLoc);
	float screenToWorldX(float screenX);
	float screenToWorldY(float screenY);
	void setBorderColor(RGBA BorderColor);
	void setAspect(float aspect);
	void setOrientationAllowed(bool portrait, bool revPortrait, bool landscape, bool revLandscape);
	void setRandomSeed(unsigned int value);
	void setResolutionMode(bool setFullRez);
	float sin(float value);
	float sinRad(float value);
	Text spaces(unsigned int length);
	float sqrt(float value);
	void stepPhysics(float time);
	Text str(float value, unsigned int decimals = 6);
	Text str(int value);
	void swap(void);
	void sync(void);

	float tan(float value);
	float tanRad(float value);
	int trunc(float value);

	void update(float time = 0.0f);
	void update2D(float time = 0.0f);
	void update3D(float time = 0.0f);
	void updateDevicesize(unsigned short width, unsigned short height);

	int val(Text NumberString, int base = 10);
	float valFloat(Text NumberString);

	Point worldToScreen(Point Coordinate);
	float worldToScreenX(float worldX);
	float worldToScreenY(float worldY);
};

