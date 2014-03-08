#include "InputEditBox.h"
#include "agk.h"

EditBox::EditBox()
{
	_boxID = agk::CreateEditBox();
}

EditBox::~EditBox()
{
//	if (GetExists())
//		agk::DeleteEditBox(_boxID);
}

EditBox::EditBox(unsigned int boxNumber)
{
	_boxID = boxNumber;
	agk::CreateEditBox(_boxID);
}

void EditBox::Delete()
{
	agk::DeleteEditBox(_boxID);
}

void EditBox::FixToScreen(bool toScreen)
{
	if (toScreen)
		agk::FixEditBoxToScreen(_boxID, 1);
	else
		agk::FixEditBoxToScreen(_boxID, 0);
}

bool EditBox::GetActive(void)
{
	if (agk::GetEditBoxActive(_boxID) == 1)
		return true;

	return false;
}

bool EditBox::GetChanged(void)
{
	if (agk::GetEditBoxChanged(_boxID) == 1)
		return true;

	return false;
}

bool EditBox::GetExists(void)
{
	if (agk::GetEditBoxExists(_boxID) == 1)
		return true;

	return false;
}

bool EditBox::GetHasFocus(void)
{
	if (agk::GetEditBoxHasFocus(_boxID) == 1)
		return true;

	return false;
}

float EditBox::GetHeight(void)
{
	return agk::GetEditBoxHeight(_boxID);
}

unsigned int EditBox::GetLines(void)
{
	return agk::GetEditBoxLines(_boxID);
}

Text EditBox::GetText(void)
{
	Text ReturnText(agk::GetEditBoxText(_boxID));
	
	return ReturnText;
}

bool EditBox::GetVisible(void)
{
	if (agk::GetEditBoxVisible(_boxID) == 1)
		return true;

	return false;
}

float EditBox::GetWidth(void)
{
	return agk::GetEditBoxWidth(_boxID);
}

float EditBox::GetX(void)
{
	return agk::GetEditBoxX(_boxID);
}

float EditBox::GetY(void)
{
	return agk::GetEditBoxY(_boxID);
}

void EditBox::SetActive(bool active)
{
	if (active)
		agk::SetEditBoxActive(_boxID, 1);
	else
		agk::SetEditBoxActive(_boxID, 0);
}

void EditBox::SetBackgroundColor(Color Values)
{
	agk::SetEditBoxBackgroundColor(_boxID, Values.GetRed(), Values.GetGreen(), Values.GetBlue(), Values.GetAlpha());
}

void EditBox::SetBackgroundImage(Image Object)
{
	agk::SetEditBoxBackgroundImage(_boxID, Object.GetID());
}

void EditBox::SetBorderColor(Color Values)
{
	agk::SetEditBoxBorderColor(_boxID, Values.GetRed(), Values.GetGreen(), Values.GetBlue(), Values.GetAlpha());
}

void EditBox::SetBorderImage(Image Object)
{
	agk::SetEditBoxBorderImage(_boxID, Object.GetID());
}

void EditBox::SetBorderSize(float size)
{
	if (size >= 0.0f)
		agk::SetEditBoxBorderSize(_boxID, size);
}

void EditBox::SetCursorBlinkTime(float speedInSeconds)
{
	if (speedInSeconds > 0.0f)
		agk::SetEditBoxCursorBlinkTime(_boxID, speedInSeconds);
}

void EditBox::SetCursorColor(Color Values)
{
	agk::SetEditBoxCursorColor(_boxID, Values.GetRed(), Values.GetGreen(), Values.GetBlue());
}

void EditBox::SetCursorWidth(float width)
{
	if (width > 0.0f)
		agk::SetEditBoxCursorWidth(_boxID, width);
}

void EditBox::SetDepth(unsigned int depth)
{
	if (depth <= 10000)
		agk::SetEditBoxDepth(_boxID, depth);
}

void EditBox::SetFocus(bool focus)
{
	if (focus)
		agk::SetEditBoxFocus(_boxID, 1);
	else
		agk::SetEditBoxFocus(_boxID, 0);
}

void EditBox::SetFontImage(Image Object)
{
	agk::SetEditBoxFontImage(_boxID, Object.GetID());
}

void EditBox::SetMaxChars(unsigned int max)
{
	agk::SetEditBoxMaxChars(_boxID, max);
}

void EditBox::SetMaxLines(unsigned int max)
{
	agk::SetEditBoxMaxLines(_boxID, max);
}

void EditBox::SetPosition(Point Location)
{
	agk::SetEditBoxPosition(_boxID, Location.GetX(), Location.GetY());
}

void EditBox::SetScissor(Point TopLeft, Point BottomRight)
{
	agk::SetEditBoxScissor(_boxID, TopLeft.GetX(), TopLeft.GetY(), BottomRight.GetX(), BottomRight.GetY());
}

void EditBox::SetSize(float width, float height)
{
	if (width > 0.0f)
	{
		if (height > 0.0f)
			agk::SetEditBoxSize(_boxID, width, height);
	}
}

void EditBox::SetText(Text Input)
{
	agk::SetEditBoxText(_boxID, Input.GetCString());
}

void EditBox::SetTextColor(Text Input)
{
	agk::SetEditBoxTextColor(_boxID, Input.GetColorRed(), Input.GetColorGreen(), Input.GetColorBlue());
}

void EditBox::SetTextSize(Text Input)
{
	agk::SetEditBoxTextSize(_boxID, Input.GetSize());
}

void EditBox::SetVisible(bool visible)
{
	if (visible)
		agk::SetEditBoxVisible(_boxID, 1);
	else
		agk::SetEditBoxVisible(_boxID, 0);
}

void EditBox::SetWrapText(bool wrapText)
{
	if (wrapText)
		agk::SetEditBoxMultiLine(_boxID, 1);
	else
		agk::SetEditBoxMultiLine(_boxID, 0);
}