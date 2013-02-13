#include "Input.h"
#include "agk.h"

Input::Input(void)
{
}


Input::~Input(void)
{
}

void Input::completeRawJoystickDetection(void)
{
	agk::CompleteRawJoystickDetection();
}

bool Input::getAccelerometerExists(void)
{
	if (agk::GetAccelerometerExists() == 1)
		return true;

	return false;
}

bool Input::getButtonPressed(unsigned short button)
{
	if (agk::GetButtonPressed(button) == 1)
		return true;

	return false;
}

bool Input::getButtonReleased(unsigned short button)
{
	if (agk::GetButtonReleased(button) == 1)
		return true;

	return false;
}

bool Input::getButtonState(unsigned short button)
{
	if (agk::GetButtonState(button) == 1)
		return true;
	
	return false;
}

bool Input::getCameraExists(void)
{
	if (agk::GetCameraExists() == 1)
		return true;

	return false;
}

bool Input::getCompassExists(void)
{
	if (agk::GetCompassExists() == 1)
		return true;
	
	return false;
}

float Input::getDirectionAngle(void)
{
	return agk::GetDirectionAngle();
}

float Input::getDirectionSpeed(void)
{
	return agk::GetDirectionSpeed();
}

float Input::getDirectionX(void)
{
	return agk::GetDirectionX();
}

float Input::getDirectionY(void)
{
	return agk::GetDirectionY();
}
	
bool Input::getGeolocationExists(void)
{
	if (agk::GetGeolocationExists())
		return true;

	return false;
}

bool Input::getGyrometerExists(void)
{
	if (agk::GetGyrometerExists())
		return true;

	return false;
}
	
bool Input::getJoystickExists(void)
{
	if (agk::GetJoystickExists())
		return true;

	return false;
}

Point Input::getJoystickLocation(void)
{
	return Point(agk::GetJoystickX(), agk::GetJoystickY());
}

float Input::getJoystickX(void)
{
	return agk::GetJoystickX();
}

float Input::getJoystickY(void)
{
	return agk::GetJoystickY();
}
	
bool Input::getKeyboardExists(void)
{
	if (agk::GetKeyboardExists())
		return true;

	return false;
}

unsigned int Input::getLastChar(void)
{
	return agk::GetLastChar();
}
	
bool Input::getLightSensorExists(void)
{
	if (agk::GetLightSensorExists())
		return true;

	return false;
}
	
bool Input::getMouseExists(void)
{
	if (agk::GetMouseExists())
		return true;
	
	return false;
}
	
bool Input::getOrientationSensorExists(void)
{
	if (agk::GetOrientationSensorExists())
		return true;

	return false;
}

Point Input::getRawAccel(void)
{
	return Point(agk::GetRawAccelX(), agk::GetRawAccelY(), agk::GetRawAccelZ());
}

float Input::getRawAccelX(void)
{
	return agk::GetRawAccelX();
}

float Input::getRawAccelY(void)
{
	return agk::GetRawAccelY();
}

float Input::getRawAccelZ(void)
{
	return agk::GetRawAccelZ();
}

float Input::getRawCompassNorth(bool isMagNorth)
{
	return agk::GetRawCompassNorth((int) isMagNorth);
}

Text Input::getRawGeoCity(void)
{
	return Text(agk::GetRawGeoCity());
}
	
float Input::getRawGeoLatitude(void)
{
	return agk::GetRawGeoLatitude();
}
	
float Input::getRawGeoLongitude(void)
{
	return agk::GetRawGeoLongitude();
}
	
Text Input::getRawGeoPostalCode(void)
{
	return Text(agk::GetRawGeoPostalCode());
}
	
Text Input::getRawGeoState(void)
{
	return Text(agk::GetRawGeoState());
}
	
Point Input::getRawGyroVelocity(void)
{
	return Point(getRawGyroVelocityX(), getRawGyroVelocityY(), getRawGyroVelocityZ());
}

float Input::getRawGyroVelocityX(void)
{
	return agk::GetRawGyroVelocityX();
}

float Input::getRawGyroVelocityY(void)
{
	return agk::GetRawGyroVelocityY();
}

float Input::getRawGyroVelocityZ(void)
{
	return agk::GetRawGyroVelocityZ();
}

Point Input::getRawInclinoPitchYawRoll(void)
{
	return Point(getRawInclinoPitch(), getRawInclinoYaw(), getRawInclinoRoll());
}

float Input::getRawInclinoPitch(void)
{
	return agk::GetRawInclinoPitch();
}

float Input::getRawInclinoRoll(void)
{
	return agk::GetRawInclinoRoll();
}

float Input::getRawInclinoYaw(void)
{
	return agk::GetRawInclinoYaw();
}

bool Input::getRawKeyPressed(unsigned int key)
{
	if (agk::GetRawKeyPressed(key))
		return true;

	return false;
}

bool Input::getRawKeyReleased(unsigned int key)
{
	if (agk::GetRawKeyReleased(key))
		return true;

	return false;
}

bool Input::getRawKeyState(unsigned int key)
{
	if (agk::GetRawKeyState(key))
		return true;

	return false;
}

float Input::getRawLightLevel(void)
{
	return agk::GetRawLightLevel();
}

bool Input::getRawMouseLeftPressed(void)
{
	if (agk::GetRawMouseLeftPressed())
		return true;

	return false;
}

bool Input::getRawMouseLeftReleased(void)
{
	if (agk::GetRawMouseLeftReleased())
		return true;

	return false;
}

bool Input::getRawMouseLeftState(void)
{
	if (agk::GetRawMouseLeftState())
		return true;

	return false;
}

bool Input::getRawMouseRightPressed(void)
{
	if (agk::GetRawMouseRightPressed())
		return true;

	return false;
}

bool Input::getRawMouseRightReleased(void)
{
	if (agk::GetRawMouseRightReleased())
		return true;

	return false;
}

bool Input::getRawMouseRightState(void)
{
	if (agk::GetRawMouseRightState())
		return true;

	return false;
}

Point Input::getRawMouseLocation(void)
{
	return Point(getRawMouseLocationX(), getRawMouseLocationY());
}

float Input::getRawMouseLocationX(void)
{
	return agk::GetRawMouseX();
}

float Input::getRawMouseLocationY(void)
{
	return agk::GetRawMouseY();
}

float Input::getRawOrientationW(void)
{
	return agk::GetRawOrientationW();
}

float Input::getRawOrientationX(void)
{
	return agk::GetRawOrientationX();
}

float Input::getRawOrientationY(void)
{
	return agk::GetRawOrientationY();
}

float Input::getRawOrientationZ(void)
{
	return agk::GetRawOrientationZ();
}

Text Input::getText(void)
{
	return Text(agk::GetTextInput());
}

bool Input::getTextCancelled(void)
{
	if (agk::GetTextInputCancelled())
		return true;

	return false;
}

bool Input::getTextCompleted(void)
{
	if (agk::GetTextInputCompleted())
		return true;

	return false;
}

TextInputState Input::getTextState(void)
{
	return (TextInputState) agk::GetTextInputState();
}

bool Input::getPointerPressed(void)
{
	if (agk::GetPointerPressed())
		return true;

	return false;
}

bool Input::getPointerReleased(void)
{
	if (agk::GetPointerReleased())
		return true;

	return false;
}

bool Input::getPointerState(void)
{
	if (agk::GetPointerState())
		return true;

	return false;
}

Point Input::getPointerLocation(void)
{
	return Point(getPointerX(), getPointerY());
}

float Input::getPointerX(void)
{
	return agk::GetPointerX();
}

float Input::getPointerY(void)
{
	return agk::GetPointerY();
}

void Input::setCursorBlinkTime(float value)
{
	agk::SetCursorBlinkTime(value);
}

void Input::setRawMousePosition(Point Location)
{
	agk::SetRawMousePosition(Location.getX(), Location.getY());
}

void Input::setRawMousePosition(float x, float y)
{
	agk::SetRawMousePosition(x, y);
}

void Input::setRawMouseVisible(bool isVisible)
{
	agk::SetRawMouseVisible((int) isVisible);
}

void Input::setTextMaxCharacters(unsigned int value)
{
	agk::SetTextInputMaxChars(value);
}
	
void Input::startText(Text Initial)
{
	if (Initial != NULL)
		agk::StartTextInput(Initial.getCString());
	else
		agk::StartTextInput();
}

void Input::stopText(void)
{
	agk::StopTextInput();
}