#pragma once

#include "../Defines.h"
#include "Image.h"
#include "RGBA.h"
#include "Vector.h"
#include "Quaternion.h"

class Object
{
public:
	Object(void);
	~Object(void);
	Object(Text Filename, float height = 1.0f);

	bool checkForCollisionsWith(Object Other);
	Object *clone(void);

	Point getAngle(void);
	float getAngleX(void);
	float getAngleY(void);
	float getAngleZ(void);
	CullMode getCullMode(void);
	DepthMode getDepthReadMode(void);
	DepthMode getDepthWrite(void);
	Point getDistanceFrom(Object Other);
	bool getExists(void);
	float getHeight(void);	
	unsigned int getID(void);
	bool getInScreen(void);
	float getLength(void);	
	ObjectType getObjectType(void);
	Quaternion getQuat(void);
	float getQuatW(void);
	float getQuatX(void);
	float getQuatY(void);
	float getQuatZ(void);
	unsigned int getTextureID(void);
	TransparencyMode getTransparency(void);
	bool getVisible(void);
	Point getLocation(void);
	float getWidth(void);
	float getX(void);
	float getY(void);
	float getZ(void);

	//seems too dangerous to use
	//Object *instance(void);
	//void moveGlobal(Point Location);
	void moveGlobalX(float x);
	void moveGlobalY(float y);
	void moveGlobalZ(float z);
	void moveLocal(Point Location);
	void moveLocalX(float x);
	void moveLocalY(float y);
	void moveLocalZ(float z);

	void rotateGlobal(Point RotationAmounts);
	void rotateGlobalX(float x);
	void rotateGlobalY(float y);
	void rotateGlobalZ(float z);
	void rotateLocal(Point RotationAmounts);
	void rotateLocalX(float x);
	void rotateLocalY(float y);
	void rotateLocalZ(float z);

	void setCollisionMode(bool isOn);
	void setColor(RGBA DiffuseColor);
	void setCullMode(CullMode value);
	void setDepthReadMode(DepthMode value);
	void setDepthWrite(DepthMode value);
	void setImage(Image ForObject, unsigned short texStage);
	void setLightMode(bool lightingOn);
	void setLookAt(Point LookLocation);
	void setLookAt(Point LookLocation, float roll);
	void setPosition(Point Location);
	void setPosition(float x, float y, float z);
	void setRotation(Point RotationAmounts);
	void setRotation(float pitch, float yaw, float roll);
	void setRotationQuat(Quaternion Values);
	void setRotationQuat(float w, float x, float y, float z);
	//Not functional yet
	//void setScale(float value);
	void setShader(unsigned int shaderID);
	void setTransparency(TransparencyMode Value);
	void setVisible(bool isVisible);
	void setX(float x);
	void setY(float y);
	void setZ(float z);

protected:
	unsigned int objectID;
	ObjectType ObjectShape;
	
	unsigned int textureID;
	float thisLength;
	float thisHeight;
	float thisWidth;
};

class BoxObject :
	public Object
{
public:
	BoxObject();
	~BoxObject();
	BoxObject(float width, float height, float length);
};

class Cone :
	public Object
{
public:
	Cone();
	~Cone();
	Cone(float height, float diameter, int segments);
};

class Cylinder :
	public Object
{
public:
	Cylinder();
	~Cylinder();
	Cylinder(float height, float diameter, int segments);
};

class Plane :
	public Object
{
public:
	Plane();
	~Plane();
	Plane(float width, float height);
};

class Sphere :
	public Object
{
public:
	Sphere();
	~Sphere();
	Sphere(float diameter, int rows, int columns);
};