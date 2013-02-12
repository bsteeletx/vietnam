#pragma once
#include "Image.h"
#include "RGBA.h"
//#include "Point.h"
//#include "Defines.h"
#include "File.h"
#include "Text.h"

class Sprite: public Image
{
public:
	~Sprite(void);
	Sprite(void);
	Sprite (Text Filename, unsigned int assignedImageNumber, unsigned int assignedSpriteNumber);
	Sprite (Point Begin, Point End, unsigned int assignedSpriteNumber = 0);
	Sprite (Text Filename, bool blackIsAlpha = false, unsigned int assignedSpriteNumber = 0); 
	Sprite (unsigned int parentImage, Text SubImageFilename, unsigned int assignedSpriteNumber = 0);
	Sprite (File FileToInit, Text PathToParent);
		
	Sprite& operator= (const Sprite& newSprite);
	Sprite& operator<< (const Image& Object);

	unsigned int clone(void);
	unsigned int clone(unsigned int assignedSpriteNumber);
	bool collidedWith(Sprite TestSprite);
	bool collidedWith(unsigned int testSpriteNumber);
	
	void deleteAll(void);

	void fixToScreen(bool screen = 1);

	bool getActive(void);
	float getAngle(void);
	float getAngleInRad(void);
	short getColorAlpha(void);	
	short getColorBlue(void);
	short getColorGreen(void);
	short getColorRed(void);	
	int getCollision(Sprite OtherSprite);
	int getCollisionGroup(void);
	short getDepth(void);
	float getDistanceFrom(Sprite TestSprite);
	float getDistancePoint1X(void);
	float getDistancePoint1Y(void);
	float getDistancePoint2X(void);
	float getDistancePoint2Y(void);
	bool getExists(void);
	int getGroup(void);
	float getHeight(void);
	int getHit(Point HitLocation);
	int getHitCategory(int categories, Point HitLocation);
	int getHitGroup(Point HitLocation);
	bool getHitTest(Point HitLocation);
	unsigned int getImageID(void);
	bool getInBox(Point TopLeft, Point BottomRight);
	bool getInCircle(Point CenterOfCircle, float radius);
	int getPixelFromX(float x); 
	int getPixelFromY(float y); 
	Point getPosition(void);
	Point getPositionByOffset(void);
	Point getPositionFromPixel(Point PixelLocation);
	Point getPositionFromWorld(Point Point1, Point Point2);
	unsigned int getSpriteNumber(void);
	bool getVisible(void);
	float getWidth(void);
	float getWorldX(float x, float y);
	float getWorldY(float x, float y);
	Point getWorldPosition(Point Point1, Point Point2);
	float getX(void);
	float getXByOffset(void);
	float getXFromPixel(int x);
	float getXFromWorld(Point ToConvert);
	float getY(void);
	float getYByOffset(void);
	float getYFromPixel(int y);
	float getYFromWorld(Point ToConvert);

	void resetUV(void);

	void setActive(bool isActive);
	void setAngle(float angle); 
	void setAngleInRad(float rad);
	void setColor(RGBA Values);
	void setColorAlpha(short alpha); 	
	void setColorBlue(short blue); 
	void setColorGreen(short green); 
	void setColorRed(short red);	
	void setCollisionGroup(int groupID);
	void setDepth(short depth); 
	void setFlip(bool horizontal, bool vertical);
	void setGroup(int group);
	void setImage(Image newImage, bool reshape = false);
	void setOffset(float x, float y);
	virtual void setPosition(float x, float y);
	virtual void setPosition(Point Locaiton);
	void setPositionByOffset(float x, float y);
	void setPositionByOffset(Point Location);
	void setScale(float x, float y);
	void setScaleByOffset(float x, float y);
	void setScissor(Point TopLeft, Point BottomRight);
	void setSize(float width = -1.0f, float height = -1.0f);
	void setSnap(bool snap = true);
	void setTransparencySetting(short setting);
	void setUV(Point UV1, Point UV2, Point UV3, Point UV4);
	void setUVBorder(float border = 0.5f);
	void setUVOffset(float u, float v);
	void setUVScale(float u, float v);
	virtual void setVisible(bool visible);
	void setX(float x);
	void setY(float y);

protected:
	unsigned int spriteNumber;
	RGBA ColorValues;
	
private:
	void create(unsigned int assignedSpriteNumber = 0);

	bool _Depth(short value);
	bool _SpriteNumber(unsigned int number);
	bool _TransparencySetting(short setting);
	bool _UVBorder(float border);
};