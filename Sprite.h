#ifndef _SPRITE_H_
#define _SPRITE_H_
#include "Image.h"
#include "Color.h"
#include "FileRead.h"
#include "Text.h"

class Sprite: public Image
{
public:
	~Sprite(void);
	Sprite(void);
	Sprite (Color SpriteColor);
	Sprite (Text Filename, unsigned int assignedImageNumber, unsigned int assignedSpriteNumber);
	Sprite (Point Begin, Point End, unsigned int assignedSpriteNumber = 0);
	Sprite (Text Filename, bool blackIsAlpha = false, unsigned int assignedSpriteNumber = 0); 
	Sprite (unsigned int parentImage, Text SubImageFilename, unsigned int assignedSpriteNumber = 0);
	Sprite (Read FileToInit, Text PathToParent);
			
	Sprite& operator= (const Sprite& newSprite);
	Sprite& operator<< (const Image& Object);

	//////////////////Properties
	//unsigned int clone(void);
	//unsigned int clone(unsigned int assignedSpriteNumber);
	Sprite Clone(void);
	bool collidedWith(Sprite TestSprite);
	bool collidedWith(unsigned int testSpriteNumber);

	void Delete();
	void Draw();

	void FixToScreen(bool screen = 1);

	bool GetActive(void);
	float GetAngle(void);
	float GetAngleInRad(void);
	short GetColorAlpha(void);	
	short GetColorBlue(void);
	short GetColorGreen(void);
	short GetColorRed(void);	
	short GetDepth(void);
	bool GetExists(void);
	int GetGroup(void);
	float GetHeight(void);
	int GetHit(Point HitLocation);
	int GetHitCategory(int categories, Point HitLocation);
	int GetHitGroup(Point HitLocation);
	bool GetHitTest(Point HitLocation);
	unsigned int GetImageID(void);
	Point GetOffset(void);
	int GetPixelFromX(float x); 
	int GetPixelFromY(float y); 
	Point GetPosition(void);
	Point GetPositionByOffset(void);
	Point GetPositionFromPixel(Point PixelLocation);
	Point GetPositionFromWorld(Point Point1, Point Point2);
	unsigned int GetSpriteNumber(void);
	bool GetVisible(void);
	float GetWidth(void);
	float GetWorldX(float x, float y);
	float GetWorldY(float x, float y);
	Point getWorldPosition(Point Point1, Point Point2);
	//float GetXByOffset(void);
	float GetXFromPixel(int x);
	float GetXFromWorld(Point ToConvert);
	//float GetYByOffset(void);
	float GetYFromPixel(int y);
	float GetYFromWorld(Point ToConvert);

	void Move(Point Speed);
	void MoveX(float x);
	void MoveY(float y);

	void ResetUV(void);

	void SetActive(bool isActive);
	void SetAngle(float angle); 
	void SetAngleInRad(float rad);
	void SetColor(Color SpriteColor);
	void SetColorAlpha(short alpha); 	
	void SetColorBlue(short blue); 
	void SetColorGreen(short green); 
	void SetColorRed(short red);	
	void SetDepth(short depth); 
	void SetFlip(bool horizontal, bool vertical);
	void setGroup(int group);
	void SetImage(Image newImage, bool reshape = false);
	void SetOffset(float x, float y);
	virtual void SetPosition(float x, float y);
	virtual void SetPosition(Point Locaiton);
	//void SetPositionByOffset(float x, float y);
	void SetPositionByOffset(Point Location);
	void SetScale(float x, float y);
	void SetScaleByOffset(Point Offset);
	void SetScissor(Point TopLeft, Point BottomRight);
	void SetSize(float width = -1.0f, float height = -1.0f);
	void SetSnap(bool snap = true);
	void SetTransparencySetting(short setting);
	void SetUV(Point UV1, Point UV2, Point UV3, Point UV4);
	void SetUVBorder(float border = 0.5f);
	void SetUVOffset(float u, float v);
	void SetUVScale(float u, float v);
	virtual void SetVisible(bool visible);
	void SetX(float x);
	void SetXByOffset(float x);
	void SetY(float y);
	void SetYByOffset(float y);

	//////////////////////////Collision
	bool GetCollision(Sprite TestSprite); 
	bool GetCollision(unsigned int testSpriteNumber);
	int GetCollisionGroup(void);
	float GetDistanceFrom(Sprite TestSprite);
	float GetDistancePoint1X(void);
	float GetDistancePoint1Y(void);
	float GetDistancePoint2X(void);
	float GetDistancePoint2Y(void);
	bool GetInBox(Point TopLeft, Point BottomRight);
	bool GetInCircle(Point CenterOfCircle, float radius);

	void SetCollisionGroup(int groupID);

protected:
	unsigned int _spriteNumber;
	Color _SpriteColor;
	
	float _GetOffsetX(void);
	float _GetOffsetY(void);
	float _GetX(void);
	float _GetY(void);
	
	
private:
	void _Create(unsigned int assignedSpriteNumber = 0);

	bool _Depth(short value);
	bool _SpriteNumber(unsigned int number);
	bool _TransparencySetting(short setting);
	bool _UVBorder(float border);
};
#endif