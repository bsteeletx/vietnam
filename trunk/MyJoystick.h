#pragma once
#include "Point.h"
#include "Image.h"
class MyJoystick
{
public:
	MyJoystick();
	~MyJoystick(void);
	MyJoystick(unsigned short joystickNumber, Point Location, float size);

	bool getExists(void);
	Point getPosition(void);
	bool getRawButtonPressed(unsigned short button);
	bool getRawButtonReleased(unsigned short button);
	bool getRawButtonState(unsigned short button);
	bool getRawExists(void);
	Point getRawR(void);
	float getRawRX(void);
	float getRawRY(void);
	float getRawRZ(void);
	float getX(void);
	float getY(void);

	void setActive(bool active);
	void setAlpha(unsigned short alphaInner, unsigned short alphaOuter);
	void setDeadZone(float play);
	void setImageInner(Image Object);
	void setImageOuter(Image Object);
	void setPosition(Point Location);
	void setRawDeadZone(float threshold);
	void setSize(float size);
	void setVisible(bool visible);

private:
	unsigned short joystickID;
};