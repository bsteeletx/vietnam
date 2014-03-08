#include "Input.h"
#include "agk.h"

Input::Input(void)
{
}


Input::~Input(void)
{
}

void Input::CompleteRawJoystickDetection(void)
{
	agk::CompleteRawJoystickDetection();
}

bool Input::GetAccelerometerExists(void)
{
	if (agk::GetAccelerometerExists() == 1)
		return true;

	return false;
}

bool Input::GetCameraExists(void)
{
	if (agk::GetCameraExists() == 1)
		return true;

	return false;
}

bool Input::GetCompassExists(void)
{
	if (agk::GetCompassExists() == 1)
		return true;
	
	return false;
}

float Input::GetDirectionAngle(void)
{
	return agk::GetDirectionAngle();
}

float Input::GetDirectionSpeed(void)
{
	return agk::GetDirectionSpeed();
}

float Input::GetDirectionX(void)
{
	return agk::GetDirectionX();
}

float Input::GetDirectionY(void)
{
	return agk::GetDirectionY();
}
	
bool Input::GetGeolocationExists(void)
{
	if (agk::GetGeolocationExists())
		return true;

	return false;
}

bool Input::GetGyrometerExists(void)
{
	if (agk::GetGyrometerExists())
		return true;

	return false;
}
	
bool Input::GetJoystickExists(void)
{
	if (agk::GetJoystickExists())
		return true;

	return false;
}

bool Input::GetKeyboardExists(void)
{
	if (agk::GetKeyboardExists())
		return true;

	return false;
}

bool Input::GetLightSensorExists(void)
{
	if (agk::GetLightSensorExists())
		return true;

	return false;
}
	
bool Input::GetMouseExists(void)
{
	if (agk::GetMouseExists())
		return true;
	
	return false;
}
	
bool Input::GetOrientationSensorExists(void)
{
	if (agk::GetOrientationSensorExists())
		return true;

	return false;
}

Point Input::GetRawAccel(void)
{
	return Point(agk::GetRawAccelX(), agk::GetRawAccelY(), agk::GetRawAccelZ());
}

float Input::GetRawAccelX(void)
{
	return agk::GetRawAccelX();
}

float Input::GetRawAccelY(void)
{
	return agk::GetRawAccelY();
}

float Input::GetRawAccelZ(void)
{
	return agk::GetRawAccelZ();
}

float Input::GetRawCompassNorth(bool isMagNorth)
{
	return agk::GetRawCompassNorth((int) isMagNorth);
}

Text Input::GetRawGeoCity(void)
{
	return Text(agk::GetRawGeoCity());
}
	
float Input::GetRawGeoLatitude(void)
{
	return agk::GetRawGeoLatitude();
}
	
float Input::GetRawGeoLongitude(void)
{
	return agk::GetRawGeoLongitude();
}
	
Text Input::GetRawGeoPostalCode(void)
{
	return Text(agk::GetRawGeoPostalCode());
}
	
Text Input::GetRawGeoState(void)
{
	return Text(agk::GetRawGeoState());
}
	
Point Input::GetRawGyroVelocity(void)
{
	return Point(GetRawGyroVelocityX(), GetRawGyroVelocityY(), GetRawGyroVelocityZ());
}

float Input::GetRawGyroVelocityX(void)
{
	return agk::GetRawGyroVelocityX();
}

float Input::GetRawGyroVelocityY(void)
{
	return agk::GetRawGyroVelocityY();
}

float Input::GetRawGyroVelocityZ(void)
{
	return agk::GetRawGyroVelocityZ();
}

Point Input::GetRawInclinoPitchYawRoll(void)
{
	return Point(GetRawInclinoPitch(), GetRawInclinoYaw(), GetRawInclinoRoll());
}

float Input::GetRawInclinoPitch(void)
{
	return agk::GetRawInclinoPitch();
}

float Input::GetRawInclinoRoll(void)
{
	return agk::GetRawInclinoRoll();
}

float Input::GetRawInclinoYaw(void)
{
	return agk::GetRawInclinoYaw();
}

bool Input::GetRawKeyPressed(unsigned int key)
{
	if (agk::GetRawKeyPressed(key))
		return true;

	return false;
}

bool Input::GetRawKeyReleased(unsigned int key)
{
	if (agk::GetRawKeyReleased(key))
		return true;

	return false;
}

bool Input::GetRawKeyState(unsigned int key)
{
	if (agk::GetRawKeyState(key))
		return true;

	return false;
}

float Input::GetRawLightLevel(void)
{
	return agk::GetRawLightLevel();
}

bool Input::GetRawMouseLeftPressed(void)
{
	if (agk::GetRawMouseLeftPressed())
		return true;

	return false;
}

bool Input::GetRawMouseLeftReleased(void)
{
	if (agk::GetRawMouseLeftReleased())
		return true;

	return false;
}

bool Input::GetRawMouseLeftState(void)
{
	if (agk::GetRawMouseLeftState())
		return true;

	return false;
}

bool Input::GetRawMouseRightPressed(void)
{
	if (agk::GetRawMouseRightPressed())
		return true;

	return false;
}

bool Input::GetRawMouseRightReleased(void)
{
	if (agk::GetRawMouseRightReleased())
		return true;

	return false;
}

bool Input::GetRawMouseRightState(void)
{
	if (agk::GetRawMouseRightState())
		return true;

	return false;
}

Point Input::GetRawMouseLocation(void)
{
	return Point(GetRawMouseLocationX(), GetRawMouseLocationY());
}

float Input::GetRawMouseLocationX(void)
{
	return agk::GetRawMouseX();
}

float Input::GetRawMouseLocationY(void)
{
	return agk::GetRawMouseY();
}

float Input::GetRawOrientationW(void)
{
	return agk::GetRawOrientationW();
}

float Input::GetRawOrientationX(void)
{
	return agk::GetRawOrientationX();
}

float Input::GetRawOrientationY(void)
{
	return agk::GetRawOrientationY();
}

float Input::GetRawOrientationZ(void)
{
	return agk::GetRawOrientationZ();
}

void Input::SetRawMousePosition(Point Location)
{
	agk::SetRawMousePosition(Location.GetX(), Location.GetY());
}

void Input::SetRawMousePosition(float x, float y)
{
	agk::SetRawMousePosition(x, y);
}

void Input::SetRawMouseVisible(bool isVisible)
{
	agk::SetRawMouseVisible((int) isVisible);
}