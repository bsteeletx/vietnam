#include "Object.h"
#include "agk.h"

Object::Object(void)
{
	objectID = 0;
}


Object::~Object(void)
{
}

Object::Object(Text Filename, float height)
{
	if (height != 1.0f)
		objectID = agk::LoadObject(Filename.getCString(), height);
	else
		objectID = agk::LoadObject(Filename.getCString());
}

BoxObject::BoxObject(void)
{
	objectID = 0;
	ObjectShape = BOX;
}

BoxObject::~BoxObject(void)
{
}

BoxObject::BoxObject(float width, float height, float length)
{
	ObjectShape = BOX;
	objectID = agk::CreateObjectBox(width, height, length);
}

Cone::Cone(void)
{
	objectID = 0;
	ObjectShape = CONE;
}

Cone::~Cone(void)
{
}

Cone::Cone(float height, float diameter, int segments)
{
	ObjectShape = CONE;
	objectID = agk::CreateObjectCone(height, diameter, segments);
}

Cylinder::Cylinder(void)
{
	ObjectShape = CYLINDER;
	objectID = 0;
}

Cylinder::~Cylinder(void)
{
}

Cylinder::Cylinder(float height, float diameter, int segments)
{
	ObjectShape = CYLINDER;
	objectID = agk::CreateObjectCylinder(height, diameter, segments);
}

Plane::Plane(void)
{
	ObjectShape = PLANE;
	objectID = 0;
}

Plane::~Plane(void)
{
}

Plane::Plane(float width, float height)
	: Object()
{
	ObjectShape = PLANE;
	objectID = agk::CreateObjectPlane(width, height);
	thisWidth = width;
	thisHeight = height;
}

Sphere::Sphere(void)
{
	ObjectShape = SPHERE;
	objectID = 0;
}

Sphere::~Sphere(void)
{
}

Sphere::Sphere(float diameter, int rows, int columns)
{
	ObjectShape = SPHERE;
	objectID = agk::CreateObjectSphere(diameter, rows, columns);
}

Object *Object::clone(void)
{
	Object *ReturnObj = new Object();
	unsigned int newID = agk::CloneObject(objectID);

	ReturnObj->objectID = newID;
	ReturnObj->ObjectShape = ObjectShape;

	return ReturnObj;
}

Point Object::getAngle(void)
{
	return Point(getAngleX(), getAngleY(), getAngleZ());
}

float Object::getAngleX(void)
{
	return agk::GetObjectAngleX(objectID);
}

float Object::getAngleY(void)
{
	return agk::GetObjectAngleY(objectID);
}

float Object::getAngleZ(void)
{
	return agk::GetObjectAngleZ(objectID);
}

CullMode Object::getCullMode(void)
{
	return (CullMode) agk::GetObjectCullMode(objectID);
}

DepthMode Object::getDepthReadMode(void)
{
	return (DepthMode) agk::GetObjectDepthReadMode(objectID);
}

DepthMode Object::getDepthWrite(void)
{
	return (DepthMode) agk::GetObjectDepthWrite(objectID);
}

bool Object::getExists(void)
{
	if (agk::GetObjectExists(objectID))
		return true;

	return false;
}

unsigned int Object::getID(void)
{
	return objectID;
}

bool Object::getInScreen(void)
{
	if (agk::GetObjectInScreen(objectID))
		return true;

	return false;
}

Quaternion Object::getQuat(void)
{
	return Quaternion(getQuatW(), getQuatX(), getQuatY(), getQuatZ());
}

float Object::getQuatW(void)
{
	return agk::GetObjectQuatW(objectID);
}

float Object::getQuatX(void)
{
	return agk::GetObjectQuatX(objectID);
}

float Object::getQuatY(void)
{
	return agk::GetObjectQuatY(objectID);
}

float Object::getQuatZ(void)
{
	return agk::GetObjectQuatZ(objectID);
}

TransparencyMode Object::getTransparency(void)
{
	return (TransparencyMode) agk::GetObjectTransparency(objectID);
}

bool Object::getVisible(void)
{
	if (agk::GetObjectVisible(objectID))
		return true;

	return false;
}
	
Point Object::getLocation(void)
{
	return Point(getX(), getY(), getZ());
}

float Object::getX(void)
{
	return agk::GetObjectX(objectID);
}

float Object::getY(void)
{
	return agk::GetObjectY(objectID);
}

float Object::getZ(void)
{
	return agk::GetObjectZ(objectID);
}

void Object::moveLocal(Point Location)
{
	moveLocalX(Location.getX());
	moveLocalY(Location.getY());
	moveLocalZ(Location.getZ());
}

void Object::moveLocalX(float x)
{
	agk::MoveObjectLocalX(objectID, x);
}

void Object::moveLocalY(float y)
{
	agk::MoveObjectLocalY(objectID, y);
}

void Object::moveLocalZ(float z)
{
	agk::MoveObjectLocalZ(objectID, z);
}

void Object::rotateGlobal(Point RotationAmounts)
{
	rotateGlobalX(RotationAmounts.getX());
	rotateGlobalY(RotationAmounts.getY());
	rotateGlobalZ(RotationAmounts.getZ());
}

void Object::rotateGlobalX(float x)
{
	agk::RotateObjectGlobalX(objectID, x);
}

void Object::rotateGlobalY(float y)
{
	agk::RotateObjectGlobalY(objectID, y);
}

void Object::rotateGlobalZ(float z)
{
	agk::RotateObjectGlobalZ(objectID, z);
}

void Object::rotateLocal(Point RotationAmounts)
{
	rotateLocalX(RotationAmounts.getX());
	rotateLocalY(RotationAmounts.getY());
	rotateLocalZ(RotationAmounts.getZ());
}

void Object::rotateLocalX(float x)
{
	agk::RotateObjectLocalX(objectID, x);
}

void Object::rotateLocalY(float y)
{
	agk::RotateObjectLocalY(objectID, y);
}

void Object::rotateLocalZ(float z)
{
	agk::RotateObjectLocalZ(objectID, z);
}

void Object::setCollisionMode(bool isOn)
{
	agk::SetObjectCollisionMode(objectID, (int) isOn);
}
	
void Object::setColor(RGBA DiffuseColor)
{
	agk::SetObjectColor(objectID, DiffuseColor.getRed(), DiffuseColor.getGreen(), DiffuseColor.getBlue(), DiffuseColor.getAlpha());
}

void Object::setCullMode(CullMode value)
{
	agk::SetObjectCullMode(objectID, value);
}
	
void Object::setDepthReadMode(DepthMode value)
{
	agk::SetObjectDepthReadMode(objectID, value);
}

void Object::setDepthWrite(DepthMode value)
{
	agk::SetObjectDepthWrite(objectID, value);
}

void Object::setImage(Image ForObject, unsigned short texStage)
{
	textureID = ForObject.getID();
	agk::SetObjectImage(objectID, textureID, texStage);
}

void Object::setLightMode(bool lightingOn)
{
	agk::SetObjectLightMode(objectID, (int) lightingOn);
}
	
void Object::setLookAt(Point LookLocation)
{
	agk::SetObjectLookAt(objectID, LookLocation.getX(), LookLocation.getY(), LookLocation.getZ(), getAngleZ());
}

void Object::setLookAt(Point LookLocation, float roll)
{
	agk::SetObjectLookAt(objectID, LookLocation.getX(), LookLocation.getY(), LookLocation.getZ(), roll);
}

void Object::setPosition(Point Location)
{
	agk::SetObjectPosition(objectID, Location.getX(), Location.getY(), Location.getZ());
}

void Object::setPosition(float x, float y, float z)
{
	agk::SetObjectPosition(objectID, x, y, z);
}

void Object::setRotation(Point RotationAmounts)
{
	agk::SetObjectRotation(objectID, RotationAmounts.getX(), RotationAmounts.getY(), RotationAmounts.getZ());
}

void Object::setRotation(float pitch, float yaw, float roll)
{
	agk::SetObjectRotation(objectID, pitch, yaw, roll);
}

void Object::setRotationQuat(Quaternion Values)
{
	agk::SetObjectRotationQuat(objectID, Values.getW(), Values.getX(), Values.getY(), Values.getZ());
}

void Object::setRotationQuat(float w, float x, float y, float z)
{
	agk::SetObjectRotationQuat(objectID, w, x, y, z);
}

void Object::setShader(unsigned int shaderID)
{
	agk::SetObjectShader(objectID, shaderID);
}
	
void Object::setTransparency(TransparencyMode Value)
{
	agk::SetObjectTransparency(objectID, Value);
}

void Object::setVisible(bool isVisible)
{
	agk::SetObjectVisible(objectID, (int) isVisible);
}

unsigned int Object::getTextureID(void)
{
	return textureID;
}

void Object::moveGlobalX(float x)
{
	setPosition(getX() + x, getY(), getZ());
}

void Object::moveGlobalY(float y)
{
	setPosition(getX(), getY() + y, getZ());
}

void Object::moveGlobalZ(float z)
{
	setPosition(getX(), getY(), getZ() + z);
}

float Object::getHeight(void)
{
	return thisHeight;
}

float Object::getWidth(void)
{
	return thisWidth;
}

float Object::getLength(void)
{
	return thisLength;
}

void Object::setX(float x)
{
	agk::SetObjectPosition(objectID, x, getY(), getZ());
}

void Object::setY(float y)
{
	agk::SetObjectPosition(objectID, getX(), y, getZ());
}

void Object::setZ(float z)
{
	agk::SetObjectPosition(objectID, getX(), getY(), z);
}

bool Object::checkForCollisionsWith(Object Other)
{
	if (agk::Abs(getX() - Other.getX()) > (thisWidth/2.0f))
		return false;
	if (agk::Abs(getY() - Other.getY()) > (thisHeight/2.0f))
		return false;
	if (agk::Abs(getZ() - Other.getZ()) > (thisLength/2.0f))
		return false;

	return true;
}

Point Object::getDistanceFrom(Object Other)
{
	Point Distance = Point();

	Distance.setX(getX() - Other.getX());
	Distance.setY(getY() - Other.getY());
	Distance.setZ(getZ() - Other.getZ());

	return Distance;
}