#pragma once

#include "Point.h"
#include "Quaternion.h"

class Camera 
{
public:
	Camera(void);
	~Camera(void);

	Point getAngles(void);
	float getAngleX(void);
	float getAngleY(void);
	float getAngleZ(void);
	Point getLocation(void);

	Quaternion getQuat(void);
	float getQuatW(void);
	float getQuatX(void);
	float getQuatY(void);
	float getQuatZ(void);
	float getX(void);
	float getY(void);
	float getZ(void);

	void moveLocal(Point Location);
	void moveLocalX(float x);
	void moveLocalY(float y);
	void moveLocalZ(float z);

	void rotateGlobal(Point RotateAmounts);
	void rotateGlobalX(float x);
	void rotateGlobalY(float y);
	void rotateGlobalZ(float z);

	void setFOV(float value);
	void setLookAt(Point Location, float roll);
	void setPosition(Point Location);
	void setPosition(float x, float y, float z);
	void setRange(float near, float far);
	void setRotation(Point RotationAmounts);
	void setRotation(float x, float y, float z);
	void setRotationQuat(Quaternion Rotation);
	void setRotationQuat(float w, float x, float y, float z);

private:

	unsigned int cameraID;
};

