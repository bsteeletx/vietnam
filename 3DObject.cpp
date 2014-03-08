#include "3DObject.h"
#include "agk.h"

Object::Object(void)
{
	_objectID = 0;
}


Object::~Object(void)
{
}

Object::Object(Text Filename, float height)
{
	if (height != 1.0f)
		_objectID = agk::LoadObject(Filename.GetCString(), height);
	else
		_objectID = agk::LoadObject(Filename.GetCString());
}

BoxObject::BoxObject(void)
{
	_objectID = 0;
	_ObjectShape = BOX;
}

BoxObject::~BoxObject(void)
{
}

BoxObject::BoxObject(float width, float height, float length)
{
	_ObjectShape = BOX;
	_objectID = agk::CreateObjectBox(width, height, length);
}

Cone::Cone(void)
{
	_objectID = 0;
	_ObjectShape = CONE;
}

Cone::~Cone(void)
{
}

Cone::Cone(float height, float diameter, int segments)
{
	_ObjectShape = CONE;
	_objectID = agk::CreateObjectCone(height, diameter, segments);
}

Cylinder::Cylinder(void)
{
	_ObjectShape = CYLINDER;
	_objectID = 0;
}

Cylinder::~Cylinder(void)
{
}

Cylinder::Cylinder(float height, float diameter, int segments)
{
	_ObjectShape = CYLINDER;
	_objectID = agk::CreateObjectCylinder(height, diameter, segments);
}

Plane::Plane(void)
{
	_ObjectShape = PLANE;
	_objectID = 0;
}

Plane::~Plane(void)
{
}

Plane::Plane(float width, float height)
	: Object()
{
	_ObjectShape = PLANE;
	_objectID = agk::CreateObjectPlane(width, height);
	_thisWidth = width;
	_thisHeight = height;
}

Sphere::Sphere(void)
{
	_ObjectShape = SPHERE;
	_objectID = 0;
}

Sphere::~Sphere(void)
{
}

Sphere::Sphere(float diameter, int rows, int columns)
{
	_ObjectShape = SPHERE;
	_objectID = agk::CreateObjectSphere(diameter, rows, columns);
}

Object *Object::Clone(void)
{
	Object *ReturnObj = new Object();
	unsigned int newID = agk::CloneObject(_objectID);

	ReturnObj->_objectID = newID;
	ReturnObj->_ObjectShape = _ObjectShape;

	return ReturnObj;
}

void Object::Delete()
{
	agk::DeleteObject(_objectID);
}

Point Object::GetAngle(void)
{
	return Point(GetAngleX(), GetAngleY(), GetAngleZ());
}

float Object::GetAngleX(void)
{
	return agk::GetObjectAngleX(_objectID);
}

float Object::GetAngleY(void)
{
	return agk::GetObjectAngleY(_objectID);
}

float Object::GetAngleZ(void)
{
	return agk::GetObjectAngleZ(_objectID);
}

CullMode Object::GetCullMode(void)
{
	return (CullMode) agk::GetObjectCullMode(_objectID);
}

DepthMode Object::GetDepthReadMode(void)
{
	return (DepthMode) agk::GetObjectDepthReadMode(_objectID);
}

DepthMode Object::GetDepthWrite(void)
{
	return (DepthMode) agk::GetObjectDepthWrite(_objectID);
}

bool Object::GetExists(void)
{
	if (agk::GetObjectExists(_objectID))
		return true;

	return false;
}

unsigned int Object::GetID(void)
{
	return _objectID;
}

bool Object::GetInScreen(void)
{
	if (agk::GetObjectInScreen(_objectID))
		return true;

	return false;
}

Quaternion Object::GetQuat(void)
{
	return Quaternion(GetQuatW(), GetQuatX(), GetQuatY(), GetQuatZ());
}

float Object::GetQuatW(void)
{
	return agk::GetObjectQuatW(_objectID);
}

float Object::GetQuatX(void)
{
	return agk::GetObjectQuatX(_objectID);
}

float Object::GetQuatY(void)
{
	return agk::GetObjectQuatY(_objectID);
}

float Object::GetQuatZ(void)
{
	return agk::GetObjectQuatZ(_objectID);
}

TransparencyMode Object::GetTransparency(void)
{
	return (TransparencyMode) agk::GetObjectTransparency(_objectID);
}

bool Object::GetVisible(void)
{
	if (agk::GetObjectVisible(_objectID))
		return true;

	return false;
}
	
Point Object::GetLocation(void)
{
	return Point(GetX(), GetY(), GetZ());
}

float Object::GetX(void)
{
	return agk::GetObjectX(_objectID);
}

float Object::GetY(void)
{
	return agk::GetObjectY(_objectID);
}

float Object::GetZ(void)
{
	return agk::GetObjectZ(_objectID);
}

void Object::MoveLocal(Point Location)
{
	MoveLocalX(Location.GetX());
	MoveLocalY(Location.GetY());
	MoveLocalZ(Location.GetZ());
}

void Object::MoveLocalX(float x)
{
	agk::MoveObjectLocalX(_objectID, x);
}

void Object::MoveLocalY(float y)
{
	agk::MoveObjectLocalY(_objectID, y);
}

void Object::MoveLocalZ(float z)
{
	agk::MoveObjectLocalZ(_objectID, z);
}

void Object::RotateGlobal(Point RotationAmounts)
{
	RotateGlobalX(RotationAmounts.GetX());
	RotateGlobalY(RotationAmounts.GetY());
	RotateGlobalZ(RotationAmounts.GetZ());
}

void Object::RotateGlobalX(float x)
{
	agk::RotateObjectGlobalX(_objectID, x);
}

void Object::RotateGlobalY(float y)
{
	agk::RotateObjectGlobalY(_objectID, y);
}

void Object::RotateGlobalZ(float z)
{
	agk::RotateObjectGlobalZ(_objectID, z);
}

void Object::RotateLocal(Point RotationAmounts)
{
	RotateLocalX(RotationAmounts.GetX());
	RotateLocalY(RotationAmounts.GetY());
	RotateLocalZ(RotationAmounts.GetZ());
}

void Object::RotateLocalX(float x)
{
	agk::RotateObjectLocalX(_objectID, x);
}

void Object::RotateLocalY(float y)
{
	agk::RotateObjectLocalY(_objectID, y);
}

void Object::RotateLocalZ(float z)
{
	agk::RotateObjectLocalZ(_objectID, z);
}

void Object::SetCollisionMode(bool isOn)
{
	agk::SetObjectCollisionMode(_objectID, (int) isOn);
}
	
void Object::SetColor(Color DiffuseColor)
{
	agk::SetObjectColor(_objectID, DiffuseColor.GetRed(), DiffuseColor.GetGreen(), DiffuseColor.GetBlue(), DiffuseColor.GetAlpha());
}

void Object::SetCullMode(CullMode value)
{
	agk::SetObjectCullMode(_objectID, value);
}
	
void Object::SetDepthReadMode(DepthMode value)
{
	agk::SetObjectDepthReadMode(_objectID, value);
}

void Object::SetDepthWrite(DepthMode value)
{
	agk::SetObjectDepthWrite(_objectID, value);
}

void Object::SetImage(Image ForObject, unsigned short texStage)
{
	_textureID = ForObject.GetID();
	agk::SetObjectImage(_objectID, _textureID, texStage);
}

void Object::SetLightMode(bool lightingOn)
{
	agk::SetObjectLightMode(_objectID, (int) lightingOn);
}
	
void Object::SetLookAt(Point LookLocation)
{
	agk::SetObjectLookAt(_objectID, LookLocation.GetX(), LookLocation.GetY(), LookLocation.GetZ(), GetAngleZ());
}

void Object::SetLookAt(Point LookLocation, float roll)
{
	agk::SetObjectLookAt(_objectID, LookLocation.GetX(), LookLocation.GetY(), LookLocation.GetZ(), roll);
}

void Object::SetPosition(Point Location)
{
	agk::SetObjectPosition(_objectID, Location.GetX(), Location.GetY(), Location.GetZ());
}

void Object::SetPosition(float x, float y, float z)
{
	agk::SetObjectPosition(_objectID, x, y, z);
}

void Object::SetRotation(Point RotationAmounts)
{
	agk::SetObjectRotation(_objectID, RotationAmounts.GetX(), RotationAmounts.GetY(), RotationAmounts.GetZ());
}

void Object::SetRotation(float pitch, float yaw, float roll)
{
	agk::SetObjectRotation(_objectID, pitch, yaw, roll);
}

void Object::SetRotationQuat(Quaternion Values)
{
	agk::SetObjectRotationQuat(_objectID, Values.GetW(), Values.GetX(), Values.GetY(), Values.GetZ());
}

void Object::SetRotationQuat(float w, float x, float y, float z)
{
	agk::SetObjectRotationQuat(_objectID, w, x, y, z);
}

void Object::SetShader(unsigned int shaderID)
{
	agk::SetObjectShader(_objectID, shaderID);
}
	
void Object::SetTransparency(TransparencyMode Value)
{
	agk::SetObjectTransparency(_objectID, Value);
}

void Object::SetVisible(bool isVisible)
{
	agk::SetObjectVisible(_objectID, (int) isVisible);
}

unsigned int Object::GetTextureID(void)
{
	return _textureID;
}

/*void Object::MoveGlobalX(float x)
{
	SetPosition(GetX() + x, GetY(), GetZ());
}

void Object::MoveGlobalY(float y)
{
	SetPosition(GetX(), GetY() + y, GetZ());
}

void Object::MoveGlobalZ(float z)
{
	SetPosition(GetX(), GetY(), GetZ() + z);
} */

float Object::GetHeight(void)
{
	return _thisHeight;
}

float Object::GetWidth(void)
{
	return _thisWidth;
}

float Object::GetLength(void)
{
	return _thisLength;
}

void Object::SetX(float x)
{
	agk::SetObjectPosition(_objectID, x, GetY(), GetZ());
}

void Object::SetY(float y)
{
	agk::SetObjectPosition(_objectID, GetX(), y, GetZ());
}

void Object::SetZ(float z)
{
	agk::SetObjectPosition(_objectID, GetX(), GetY(), z);
}

bool Object::checkForCollisionsWith(Object Other)
{
	if (agk::Abs(GetX() - Other.GetX()) > (_thisWidth/2.0f))
		return false;
	if (agk::Abs(GetY() - Other.GetY()) > (_thisHeight/2.0f))
		return false;
	if (agk::Abs(GetZ() - Other.GetZ()) > (_thisLength/2.0f))
		return false;

	return true;
}

Point Object::GetDistanceFrom(Object Other)
{
	Point Distance = Point();

	Distance.SetX(GetX() - Other.GetX());
	Distance.SetY(GetY() - Other.GetY());
	Distance.SetZ(GetZ() - Other.GetZ());

	return Distance;
}