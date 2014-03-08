#ifndef _INPUTVIRTUALBUTTON_H_
#define _INPUTVIRTUALBUTTON_H_

#include "Point.h"
#include "Image.h"
#include "Color.h"
#include "Text.h"
#include "Input.h"

class VirtualButton : Input
{
public:
	VirtualButton();
	~VirtualButton(void);
	VirtualButton(unsigned short buttonNumber, Point Location, float size);

	void Delete();

	bool GetExists(void);
	bool GetPressed(void);
	bool GetReleased(void);
	bool GetState(void);

	void SetActive(bool active);
	void SetAlpha(unsigned short alpha);
	void SetColor(Color Values);
	void SetImageDown(Image Object);
	void SetImageUp(Image Object);
	void SetPosition(Point Location);
	void SetPosition(float x, float y);
	void SetScreenPosition(Point Location, float size);
	void SetSize(float size);
	void SetText(Text InnerLabel);
	void SetVisible(bool visible);

private:
	unsigned short _buttonID;
};

#endif