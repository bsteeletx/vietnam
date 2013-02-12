#include "MyJoystick.h"
#include "agk.h"

MyJoystick::MyJoystick(void)
{
	joystickID = 0;
}

MyJoystick::~MyJoystick(void)
{
	//if (getExists())
	//	agk::DeleteVirtualJoystick(joystickID);
}

MyJoystick::MyJoystick(unsigned short joystickNumber, Point Location, float size)
{
	if (joystickNumber < 5)
	{
		joystickID = joystickNumber;
		if (joystickNumber)
			agk::AddVirtualJoystick(joystickID, Location.getX(), Location.getY(), size);
	}
}

bool MyJoystick::getExists(void)
{
	if (agk::GetVirtualJoystickExists(joystickID) == 1)
		return true;

	return false;
}

bool MyJoystick::getRawButtonPressed(unsigned short button)
{
	if (agk::GetRawJoystickButtonPressed(joystickID, button))
		return true;

	return false;
}

bool MyJoystick::getRawButtonReleased(unsigned short button)
{
	if (agk::GetRawJoystickButtonReleased(joystickID, button))
		return true;

	return false;
}

bool MyJoystick::getRawButtonState(unsigned short button)
{
	if(agk::GetRawJoystickButtonState(joystickID, button))
		return true;

	return false;
}

bool MyJoystick::getRawExists(void)
{
	if (agk::GetRawJoystickExists(joystickID))
		return true;

	return false;
}

Point MyJoystick::getRawR(void)
{
	return Point(getRawRX(), getRawRY(), getRawRZ());
}

float MyJoystick::getRawRX(void)
{
	return agk::GetRawJoystickRX(joystickID);
}

float MyJoystick::getRawRY(void)
{
	return agk::GetRawJoystickRY(joystickID);
}

float MyJoystick::getRawRZ(void)
{
	return agk::GetRawJoystickRZ(joystickID);
}

float MyJoystick::getX(void)
{
	return agk::GetVirtualJoystickX(joystickID);
}

float MyJoystick::getY(void)
{
	return agk::GetVirtualJoystickY(joystickID);
}

void MyJoystick::setActive(bool active)
{
	if (active)
		agk::SetVirtualJoystickActive(joystickID, 1);
	else
		agk::SetVirtualJoystickActive(joystickID, 0);
}

void MyJoystick::setAlpha(unsigned short alphaInner, unsigned short alphaOuter)
{
	if (alphaInner < 256)
	{
		if (alphaOuter < 256)
			agk::SetVirtualJoystickAlpha(joystickID, alphaInner, alphaOuter);
	}
}

void MyJoystick::setDeadZone(float play)
{
	if (play >= 0.0f)
	{
		if (play <= 1.0f)
			agk::SetVirtualJoystickDeadZone(play);
	}
}

void MyJoystick::setImageInner(Image Object)
{
	agk::SetVirtualJoystickImageInner(joystickID, Object.getID());
}

void MyJoystick::setImageOuter(Image Object)
{
	agk::SetVirtualJoystickImageOuter(joystickID, Object.getID());
}

void MyJoystick::setPosition(Point Location)
{
	agk::SetJoystickScreenPosition(joystickID, Location.getX(), Location.getY());
}

void MyJoystick::setRawDeadZone(float threshold)
{
	agk::SetRawJoystickDeadZone(threshold);
}

void MyJoystick::setSize(float size)
{
	if (size >= 0.0f)
		agk::SetVirtualJoystickSize(joystickID, size);
}

void MyJoystick::setVisible(bool visible)
{
	if (visible)
		agk::SetVirtualJoystickVisible(joystickID, 1);
	else
		agk::SetVirtualJoystickVisible(joystickID, 0);
}