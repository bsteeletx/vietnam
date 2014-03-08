#ifndef _INPUTEDITBOX_H_
#define _INPUTEDITBOX_H_

#include "Point.h"
#include "Image.h"
#include "Color.h"
#include "Text.h"
#include "Input.h"

class EditBox : Input
{
public:
	EditBox();
	~EditBox(void);
	EditBox(unsigned int boxNumber);

	void Delete();

	void FixToScreen(bool toScreen);

	bool GetActive(void);
	bool GetChanged(void);
	unsigned int GetCurrent(void);
	bool GetExists(void);
	bool GetHasFocus(void);
	float GetHeight(void);
	unsigned int GetLines(void);
	Text GetText(void);
	bool GetVisible(void);
	float GetWidth(void);
	float GetX(void);
	float GetY(void);

	void SetActive(bool active);
	void SetBackgroundColor(Color Values);
	void SetBackgroundImage(Image Object);
	void SetBorderColor(Color Values);
	void SetBorderImage(Image Object);
	void SetBorderSize(float size);
	void SetCursorBlinkTime(float speedInSeconds);
	void SetCursorColor(Color Values);
	void SetCursorWidth(float width);
	void SetDepth(unsigned int depth);
	void SetExtendedFontImage(void); //TODO: Fill out
	void SetFocus(bool focus);
	void SetFontImage(Image Object);
	void SetMaxChars(unsigned int max);
	void SetMaxLines(unsigned int max);
	void SetMultiLine(bool isMultiLine);
	void SetPasswordMode(bool isPassword);
	void SetPosition(Point Location);
	void SetScissor(Point TopLeft, Point BottomRight);
	void SetSize(float width, float height);
	void SetText(Text Input);
	void SetTextColor(Text Input);
	void SetTextSize(Text Input);
	void SetUseAlternateInput(void); //TODO: Fill out
	void SetVisible(bool visible);
	void SetWrapText(bool wrapText); 

private:
	unsigned int _boxID;
};

#endif