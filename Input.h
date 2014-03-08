#pragma once

#include "Point.h"
#include "Text.h"
#include "../Defines.h"

class Input
{
public:
	Input(void);
	~Input(void);

	////////////////Accelerometer
	Point GetDirection();
	float GetDirectionAngle();
	float GetDirectionSpeed();
	float GetDirectionX();
	float GetDirectionY();

	////////////////////Platform Specific & Support
	void CompleteRawJoystickDetection(void);

	bool GetAccelerometerExists(void);
	bool getButtonPressed(unsigned short button);
	bool getButtonReleased(unsigned short button);
	bool getButtonState(unsigned short button);
	bool GetCameraExists(void);
	bool GetCompassExists(void);
	float getDirectionAngle(void);
	float getDirectionSpeed(void);
	float getDirectionX(void);
	float getDirectionY(void);
	bool GetGeolocationExists(void);
	bool GetGyrometerExists(void);
	void GetInclinometerExists(); //TODO: Fill out
	bool GetJoystickExists(void);
	Point getJoystickLocation(void);
	float getJoystickX(void);
	float getJoystickY(void);
	bool GetKeyboardExists(void);
	unsigned int getLastChar(void);
	bool GetLightSensorExists(void);
	bool GetMouseExists(void);
	void GetMultiTouchExists(); //TODO: Fill out
	void GetNFCExists(); //TODO: Fill out
	bool GetOrientationSensorExists(void);
	Point GetRawAccel(void);
	float GetRawAccelX(void);
	float GetRawAccelY(void);
	float GetRawAccelZ(void);
	float GetRawCompassNorth(bool isMagNorth);
	void GetRawFirstNFCDevice(void); //TODO: Fill out
	void GetRawFirstTouchEvent(void); //TODO: Fill out
	Text GetRawGeoCity(void);
	void GetRawGeoCountry(void); //TODO: Fill out
	float GetRawGeoLatitude(void); 
	float GetRawGeoLongitude(void);
	Text GetRawGeoPostalCode(void);
	Text GetRawGeoState(void);
	Point GetRawGyroVelocity(void);
	float GetRawGyroVelocityX(void);
	float GetRawGyroVelocityY(void);
	float GetRawGyroVelocityZ(void);
	Point GetRawInclinoPitchYawRoll(void);
	float GetRawInclinoPitch(void);
	float GetRawInclinoRoll(void);
	float GetRawInclinoYaw(void);
	void GetRawJoystickButtonPressed(); //TODO: Fill out
	void GetRawJoystickButtonReleased(); //TODO: Fill out
	void GetRawJoystickButtonState(); //TODO: Fill out
	void GetRawJoystickExists(); //TODO: Fill out
	void GetRawJoystickRX(); //TODO: Fill out
	void GetGawJoystickRY(); //TODO: Fill out
	void GetGawJoystickRZ(); //TODO: Fill out
	void GetGawJoystickX(); //TODO: Fill out
	void GetGawJoystickY(); //TODO: Fill out
	void GetGawJoystickZ(); //TODO: Fill out
	bool GetRawKeyPressed(unsigned int key);
	bool GetRawKeyReleased(unsigned int key);
	bool GetRawKeyState(unsigned int key);
	void GetRawLastKey(); //TODO: Fill out
	float GetRawLightLevel(void);
	bool GetRawMouseLeftPressed(void);
	bool GetRawMouseLeftReleased(void);
	bool GetRawMouseLeftState(void);
	Point GetRawMouseLocation(void);
	float GetRawMouseLocationX(void);
	float GetRawMouseLocationY(void);
	bool GetRawMouseMiddlePressed(void); //TODO: Fill out this and next 2
	bool GetRawMouseMiddleReleased(void);
	bool GetRawMouseMiddleState(void);
	bool GetRawMouseRightPressed(void);
	bool GetRawMouseRightReleased(void);
	bool GetRawMouseRightState(void);
	void GetRawMouseWheel(); //TODO: Fill out
	void GetRawMouseWheelDelta(); //TODO: Fill out
	void GetRawNextTouchEvent(); //TODO: Fill out
	void GetRawNFCCount(void); //TODO:Fill out
	void GetRawNFCData(void); //TODO: Fill out
	void GetRawNFCDataState(void); //TODO: Fill out
	void GetRawNFCName(void); //TODO: Fill out
	void GetRawNextNFCDevice(void); //TODO: Fill out
	float GetRawOrientationW(void);
	float GetRawOrientationX(void);
	float GetRawOrientationY(void);
	float GetRawOrientationZ(void);
	void GetRawTouchCount(); //TODO: Fill out
	void GetRawTouchCurrentX(); //TODO: Fill out
	void GetRawTouchCurrentY(); //TODO: Fill out
	void GetRawTouchLastX(); //TODO: Fill out
	void GetRawTouchLastY(); //TODO: Fill out
	void GetRawTouchReleased(); //TODO: Fill out
	void GetRawTouchStartX(); //TODO: Fill out
	void GetRawTouchStartY(); //TODO: Fill out
	void GetRawTouchTime(); //TODO: Fill out
	void GetRawTouchType(); //TODO: Fill out
	void GetRawTouchValue(); //TODO: Fill out

	void SendRawNFCData(void); //TODO: Fill out
	void SetRawJoystickDeadZone(); //TODO: Fill out
	void SetRawMousePosition(Point Location);
	void SetRawMousePosition(float x, float y);
	void SetRawMouseVisible(bool isVisible);
	void SetRawTouchValue(void); //TODO: Fill out
};

