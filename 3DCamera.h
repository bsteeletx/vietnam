#pragma once

#include "Point.h"
#include "Quaternion.h"

class Camera 
{
public:
	Camera(void);
	~Camera(void);

	Point GetAngles(void);
	float GetAngleX(void);
	float GetAngleY(void);
	float GetAngleZ(void);
	Point GetLocation(void);

	Quaternion GetQuat(void);
	float GetQuatW(void);
	float GetQuatX(void);
	float GetQuatY(void);
	float GetQuatZ(void);
	float GetX(void);
	float GetY(void);
	float GetZ(void);

	void MoveLocal(Point Location);
	void MoveLocalX(float x);
	void MoveLocalY(float y);
	void MoveLocalZ(float z);

	void RotateGlobal(Point RotateAmounts);
	void RotateGlobalX(float x);
	void RotateGlobalY(float y);
	void RotateGlobalZ(float z);
	void RotateLocal(Point RotateAmounts); 
	/*void RotateLocalX(float x);
	void RotateLocalY(float y);
	void RotateLocalZ(float z);*//////////Should just use full Rotate

	void SetFOV(float value);
	void SetLookAt(Point Location, float roll);
	void SetPosition(Point Location);
	void SetPosition(float x, float y, float z);
	void SetRange(float near, float far);
	void SetRotation(Point RotationAmounts);
	void SetRotation(float x, float y, float z);
	void SetRotationQuat(Quaternion Rotation);
	void SetRotationQuat(float w, float x, float y, float z);

private:

	unsigned int _cameraID;
};

