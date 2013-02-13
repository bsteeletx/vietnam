#pragma once

#include "Point.h"
#include "Text.h"
#include "../Defines.h"

class Input
{
public:
	Input(void);
	~Input(void);

	void completeRawJoystickDetection(void);

	bool getAccelerometerExists(void);
	bool getButtonPressed(unsigned short button);
	bool getButtonReleased(unsigned short button);
	bool getButtonState(unsigned short button);
	bool getCameraExists(void);
	bool getCompassExists(void);
	float getDirectionAngle(void);
	float getDirectionSpeed(void);
	float getDirectionX(void);
	float getDirectionY(void);
	bool getGeolocationExists(void);
	bool getGyrometerExists(void);
	bool getJoystickExists(void);
	Point getJoystickLocation(void);
	float getJoystickX(void);
	float getJoystickY(void);
	bool getKeyboardExists(void);
	unsigned int getLastChar(void);
	bool getLightSensorExists(void);
	bool getMouseExists(void);
	bool getOrientationSensorExists(void);
	Point getRawAccel(void);
	float getRawAccelX(void);
	float getRawAccelY(void);
	float getRawAccelZ(void);
	float getRawCompassNorth(bool isMagNorth);
	Text getRawGeoCity(void);
	float getRawGeoLatitude(void);
	float getRawGeoLongitude(void);
	Text getRawGeoPostalCode(void);
	Text getRawGeoState(void);
	Point getRawGyroVelocity(void);
	float getRawGyroVelocityX(void);
	float getRawGyroVelocityY(void);
	float getRawGyroVelocityZ(void);
	Point getRawInclinoPitchYawRoll(void);
	float getRawInclinoPitch(void);
	float getRawInclinoRoll(void);
	float getRawInclinoYaw(void);
	bool getRawKeyPressed(unsigned int key);
	bool getRawKeyReleased(unsigned int key);
	bool getRawKeyState(unsigned int key);
	float getRawLightLevel(void);
	bool getRawMouseLeftPressed(void);
	bool getRawMouseLeftReleased(void);
	bool getRawMouseLeftState(void);
	bool getRawMouseRightPressed(void);
	bool getRawMouseRightReleased(void);
	bool getRawMouseRightState(void);
	Point getRawMouseLocation(void);
	float getRawMouseLocationX(void);
	float getRawMouseLocationY(void);
	float getRawOrientationW(void);
	float getRawOrientationX(void);
	float getRawOrientationY(void);
	float getRawOrientationZ(void);
	Text getText(void);
	bool getTextCancelled(void);
	bool getTextCompleted(void);
	TextInputState getTextState(void);
	bool getPointerPressed(void);
	bool getPointerReleased(void);
	bool getPointerState(void);
	Point getPointerLocation(void);
	float getPointerX(void);
	float getPointerY(void);
	
	void setCursorBlinkTime(float value);
	void setRawMousePosition(Point Location);
	void setRawMousePosition(float x, float y);
	void setRawMouseVisible(bool isVisible);
	void setTextMaxCharacters(unsigned int value);
	void startText(Text Initial = NULL);
	void stopText(void);
};

