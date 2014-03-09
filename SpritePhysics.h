#ifndef _SPRITEPHYSICS_H_
#define _SPRITEPHYSICS_H_

#include "Sprite.h"
#include "Vector.h"

class PhysicsS :
	public Sprite
{
public:
	~PhysicsS(void);
	PhysicsS(void);
	PhysicsS(Point Begin, Point End, short mode = 2);
	PhysicsS(Text Filename, short mode = 2);
	PhysicsS(unsigned int parentImage, Text SubImageFilename, short mode = 2);
	
	//PhysicsSprite& operator=(const PhysicsSprite& TempSprite);

	void AddShapeBox(Point TopLeft, Point BottomRight, float angeInRads);
	void AddShapeCircle(Point CenterOfCircle, float radius);
	void AddShapePolygon(unsigned int numOfPoints, unsigned int pointIndex, Point Location);

	void CalculateCOM(void);
	void ClearShapes(void);
		
	float GetAngularVelocity(void);
	bool GetCollision(Sprite TestSprite);
	float GetCollisionWorldX(void);
	float GetCollisionWorldY(void);
	float GetCollisionX(void);
	float GetCollisionY(void);
	bool GetIsInCategory(unsigned short categoryNum);
	bool GetIsInCollisionGroup(unsigned short collisionNum);
	float GetMass(void);
	bool GetUsingPhysics(void);
	float GetVelocityX(void);
	float GetVelocityY(void);

	void SetAngularDamping(float damp);
	void SetAngularImpulse(float impulse);
	void SetAngularVelocity(float aVelocity);
	void setBounciness(float bounciness);
	void SetCanRotate(bool canRotate);
	void SetCategoryBit(unsigned short categoryNum, bool inCategory);
	void SetCategoryBits(unsigned int bits);
	void SetCollideBit(unsigned short collisionNum, bool inCollision);
	void SetCollideByBit(unsigned int bits);
	void SetCOM(Point COM);
	void SetDamping(float damp);
	void SetDelete(void);
	void SetForce(Vector Force);
	void SetGroup(int group); 
	void SetFriction(float friction);
	void SetImpulse(Vector Impulse);
	void SetIsBullet(bool isBullet);
	void SetIsSensor(bool isSensor);
	void SetMass(float massInKG);
	void SetRestitution(float value);
	void SetTorque(float torque);
	void SetVelocity(float xVelocity, float yVelocity);
	void SetShape(short shapeType);
	void SetShapeBox(Point TopLeft, Point BottomRight, float angleInRads = 0.0f);
	void SetShapeCircle(Point CenterOfCircle, float radius);
	void SetShapePolygon(short numOfPoints, short pointIndex, Point Location);

	void togglePhysics(void);

private:
	bool _usingPhysics;
	bool _category[16];
	bool _collision[16];
	
	void _SetOff(void);
	void _SetOn(short mode = 2);

	bool _Mode(short value = 2);	
	bool _Shape(short shapeType);
	bool _ShapePolygon(short numOfPoints, short pointIndex);
	bool _UnsignedFloat(float value);
	bool _ZeroToFifteen(unsigned int value);
	bool _ZeroToMaxInt(unsigned int value, unsigned int maxValue);
	bool _ZeroToOneFloat(float value);
};
#endif