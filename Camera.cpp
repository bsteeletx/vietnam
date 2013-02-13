#include "Camera.h"
#include "agk.h"

Camera::Camera(void)
{
	cameraID = 1;
}

Camera::~Camera(void)
{
}

Point Camera::getAngles(void)
{
	return Point(agk::GetCameraAngleX(cameraID), agk::GetCameraAngleY(cameraID), agk::GetCameraAngleZ(cameraID));
}

float Camera::getAngleX(void)
{
	return agk::GetCameraAngleX(cameraID);
}

float Camera::getAngleY(void)
{
	return agk::GetCameraAngleY(cameraID);
}

float Camera::getAngleZ(void)
{
	return agk::GetCameraAngleZ(cameraID);
}

Point Camera::getLocation(void)
{
	return Point(agk::GetCameraX(cameraID), agk::GetCameraY(cameraID), agk::GetCameraZ(cameraID));
}

Quaternion Camera::getQuat(void)
{
	return Quaternion(getQuatW(), getQuatX(), getQuatY(), getQuatZ());
}

float Camera::getQuatW(void)
{
	return agk::GetCameraQuatW(cameraID);
}

float Camera::getQuatX(void)
{
	return agk::GetCameraQuatX(cameraID);
}

float Camera::getQuatY(void)
{
	return agk::GetCameraQuatY(cameraID);
}

float Camera::getQuatZ(void)
{
	return agk::GetCameraQuatZ(cameraID);
}

float Camera::getX(void)
{
	return agk::GetCameraX(cameraID);
}

float Camera::getY(void)
{
	return agk::GetCameraY(cameraID);
}

float Camera::getZ(void)
{
	return agk::GetCameraZ(cameraID);
}

void Camera::moveLocal(Point Location)
{
	agk::MoveCameraLocalX(cameraID, Location.getX());
	agk::MoveCameraLocalY(cameraID, Location.getY());
	agk::MoveCameraLocalZ(cameraID, Location.getZ());
}

void Camera::moveLocalX(float x)
{
	agk::MoveCameraLocalX(cameraID, x);
}

void Camera::moveLocalY(float y)
{
	agk::MoveCameraLocalY(cameraID, y);
}

void Camera::moveLocalZ(float z)
{
	agk::MoveCameraLocalZ(cameraID, z);
}

void Camera::rotateGlobal(Point RotateAmounts)
{
	agk::RotateCameraGlobalX(cameraID, RotateAmounts.getX());
	agk::RotateCameraGlobalY(cameraID, RotateAmounts.getY());
	agk::RotateCameraGlobalZ(cameraID, RotateAmounts.getZ());
}

void Camera::rotateGlobalX(float x)
{
	agk::RotateCameraGlobalX(cameraID, x);
}

void Camera::rotateGlobalY(float y)
{
	agk::RotateCameraGlobalY(cameraID, y);
}

void Camera::rotateGlobalZ(float z)
{
	agk::RotateCameraGlobalZ(cameraID, z);
}

void Camera::setFOV(float value)
{
	agk::SetCameraFOV(cameraID, value);
}

void Camera::setLookAt(Point Location, float roll)
{
	agk::SetCameraLookAt(cameraID, Location.getX(), Location.getY(), Location.getZ(), roll);
}

void Camera::setPosition(Point Location)
{
	agk::SetCameraPosition(cameraID, Location.getX(), Location.getY(), Location.getZ());
}

void Camera::setPosition(float x, float y, float z)
{
	agk::SetCameraPosition(cameraID, x, y, z);
}

void Camera::setRange(float nearValue, float farValue)
{
	agk::SetCameraRange(cameraID, nearValue, farValue);
}
	
void Camera::setRotation(Point RotationAmounts)
{
	agk::SetCameraRotation(cameraID, RotationAmounts.getX(), RotationAmounts.getY(), RotationAmounts.getZ());
}

void Camera::setRotation(float x, float y, float z)
{
	agk::SetCameraRotation(cameraID, x, y, z);
}

void Camera::setRotationQuat(Quaternion Rotation)
{
	agk::SetCameraRotationQuat(cameraID, Rotation.getW(), Rotation.getX(), Rotation.getY(), Rotation.getZ());
}

void Camera::setRotationQuat(float w, float x, float y, float z)
{
	agk::SetCameraRotationQuat(cameraID, w, x, y, z);
}