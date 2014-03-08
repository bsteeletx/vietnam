#ifndef _INPUTVIRTUALJOYSTICK_H_
#define _INPUTVIRTUALJOYSTICK_H_

#include "Input.h"
#include "Image.h"

class VirtualJoystick : Input
{
public:
	VirtualJoystick(Point Location, float diameter);
	~VirtualJoystick();

	void Delete();

	bool GetExists();
	Point GetPosition();
	
	void SetActive(bool isActive);
	void SetAlpha(unsigned short outerAlpha, unsigned short innerAlpha);
	void SetDeadZone(float value);
	void SetImageInner(Image Inner);
	void SetImageOuter(Image Outer);
	void SetPosition(Point Position);
	void SetSize(float diameter);
	void SetVisible(bool isVisible);

private:
	unsigned short _joystickID;
	static bool _joysticks[4];

	void _Add(Point Location, float diameter);
	unsigned short _GetJoystickID();
	float _GetX();
	float _GetY();
};
#endif