#include "AGKCore.h"
#include "agk.h"

AGKCore::AGKCore(void)
{
}


AGKCore::~AGKCore(void)
{
}

unsigned int AGKCore::Asc(char alpha)
{
	const char single[1] = {alpha};
	return agk::Asc(single);
}

Text AGKCore::Bin(int value)
{
	return Text(agk::Bin(value));
}
	
int AGKCore::Ceil(float value)
{
	return agk::Ceil(value);
}

Text AGKCore::Chr(unsigned int ascii)
{
	return Text(agk::Chr(ascii));
}

void AGKCore::ClearDepthBuffer(void)
{
	agk::ClearDepthBuffer();
}

void AGKCore::ClearScreen(void)
{
	agk::ClearScreen();
}

float AGKCore::Cos(float value)
{
	return agk::Cos(value);
}

float AGKCore::CosRad(float value)
{
	return agk::CosRad(value);
}

unsigned int AGKCore::CountStringTokens(Text Original, char delimeter)
{
	char single[1] = { delimeter };

	return agk::CountStringTokens(Original.GetCString(), single);
}

void AGKCore::DeleteAllImages()
{
	agk::DeleteAllImages();
}

void AGKCore::DeleteAllSprites()
{
	agk::DeleteAllSprites();
}

void AGKCore::DeleteAllText()
{
	agk::DeleteAllText();
}

void AGKCore::EnableClearColor(bool clearEachFrame)
{
	if (clearEachFrame)
		agk::EnableClearColor(1);
	else
		agk::EnableClearColor(0);
}

float AGKCore::FMod(float value, float modValue)
{
	return agk::FMod(value, modValue);
}

int AGKCore::Floor(float value)
{
	return agk::Floor(value);
}
	
unsigned short AGKCore::GetDeviceHeight(void)
{
	return agk::GetDeviceHeight();
}

unsigned short AGKCore::GetDeviceWidth(void)
{
	return agk::GetDeviceWidth();
}

float AGKCore::GetDisplayAspect(void)
{
	return agk::GetDisplayAspect();
}

Orientation AGKCore::GetOrientation(void)
{
	return (Orientation) agk::GetOrientation();
}

unsigned int AGKCore::GetPolygonsDrawn(void)
{
	return agk::GetPolygonsDrawn();
}

bool AGKCore::GetResumed(void)
{
	if (agk::GetResumed() == 1)
		return true;
	
	return false;
}

float AGKCore::GetScreenBoundsBottom(void)
{
	return agk::GetScreenBoundsBottom();
}

float AGKCore::GetScreenBoundsLeft(void)
{
	return agk::GetScreenBoundsLeft();
}

float AGKCore::GetScreenBoundsRight(void)
{
	return agk::GetScreenBoundsRight();
}

float AGKCore::GetScreenBoundsTop(void)
{
	return agk::GetScreenBoundsTop();
}

Text AGKCore::GetStringToken(Text Original, char delimeter, unsigned int token)
{
	char single[1] = { delimeter };

	return Text(agk::GetStringToken(Original.GetCString(), single, token));
}

unsigned int AGKCore::GetVerticesProcessed(void)
{
	return agk::GetVerticesProcessed();
}

float AGKCore::GetViewOffsetX(void)
{
	return agk::GetViewOffsetX();
}

float AGKCore::GetViewOffsetY(void)
{
	return agk::GetViewOffsetY();
}

float AGKCore::GetViewZoom(void)
{
	return agk::GetViewZoom();
}

unsigned short AGKCore::GetVirtualHeight(void)
{
	return agk::GetVirtualHeight();
}

unsigned short AGKCore::GetVirtualWidth(void)
{
	return agk::GetVirtualWidth();
}

Text AGKCore::Hex(int value)
{
	return Text(agk::Hex(value));
}

Text AGKCore::Left(Text Original, unsigned int count)
{
	return Text(agk::Left(Original.GetCString(), count));
}

unsigned int AGKCore::Len(Text Original)
{
	return agk::Len(Original.GetCString());
}

Text AGKCore::Lower(Text Original)
{
	return Text(agk::Lower(Original.GetCString()));
}

Text AGKCore::Mid(Text Original, unsigned int position, int length)
{
	return Text(agk::Mid(Original.GetCString(), position, length));
}

int AGKCore::Mod(int value, int modValue)
{
	return agk::Mod(value, modValue);
}

int AGKCore::Random(void)
{
	return agk::Random();
}

int AGKCore::Random(unsigned int from, unsigned int to)
{
	return agk::Random(from, to);
}

int AGKCore::RandomSign(int value)
{
	return agk::RandomSign(value);
}

void AGKCore::Render(void)
{
	agk::Render();
}

void AGKCore::Render2DBack(void)
{
	agk::Render2DBack();
}

void AGKCore::Render2DFront(void)
{
	agk::Render2DFront();
}

void AGKCore::Render3D(void)
{
	agk::Render3D();
}

Text AGKCore::Right(Text Original, unsigned int count)
{
	return Text(agk::Right(Original.GetCString(), count));
}

int AGKCore::Round(float value)
{
	return agk::Round(value);
}
	
float AGKCore::ScreenFPS(void)
{
	return agk::ScreenFPS();
}

Point AGKCore::ScreenToWorld(Point ScreenLoc)
{
	return Point(agk::ScreenToWorldX(ScreenLoc.GetX()), agk::ScreenToWorldY(ScreenLoc.GetY()));
}

float AGKCore::ScreenToWorldX(float x)
{
	return agk::ScreenToWorldX(x);
}

float AGKCore::ScreenToWorldY(float y)
{
	return agk::ScreenToWorldY(y);
}

void AGKCore::SetBorderColor(Color BorderColor)
{
	agk::SetBorderColor(BorderColor.GetRed(), BorderColor.GetGreen(), BorderColor.GetBlue());
}

void AGKCore::SetDisplayAspect(float aspect)
{
	agk::SetDisplayAspect(aspect);
}

void AGKCore::SetOrientationAllowed(bool portrait, bool revPortrait, bool landscape, bool revLandscape)
{
	agk::SetOrientationAllowed((int) portrait, (int) revPortrait, (int) landscape, (int) revLandscape);
}

void AGKCore::SetRandomSeed(unsigned int value)
{
	agk::SetRandomSeed(value);
}

void AGKCore::SetResolutionMode(bool SetFullRez)
{
	agk::SetResolutionMode((int) SetFullRez);
}

float AGKCore::Sin(float value)
{
	return agk::Sin(value);
}

float AGKCore::SinRad(float value)
{
	return agk::SinRad(value);
}

Text AGKCore::Spaces(unsigned int length)
{
	return Text(agk::Spaces(length));
}

float AGKCore::SqRt(float value)
{
	return agk::Sqrt(value);
}

void AGKCore::StepPhysics(float time)
{
	agk::StepPhysics(time);
}

Text AGKCore::Str(float value, unsigned int decimals)
{
	return Text(agk::Str(value, decimals));
}

Text AGKCore::Str(int value)
{
	return Text(agk::Str(value));
}

void AGKCore::Swap(void)
{
	agk::Swap();
}

void AGKCore::Sync(void)
{
	agk::Sync();
}
	
float AGKCore::Tan(float value)
{
	return agk::Tan(value);
}

float AGKCore::TanRad(float value)
{
	return agk::TanRad(value);
}

int AGKCore::Trunc(float value)
{
	return agk::Trunc(value);
}

void AGKCore::Update(float time)
{
	agk::Update(time);
}

void AGKCore::Update2D(float time)
{
	agk::Update2D(time);
}

void AGKCore::Update3D(float time)
{
	agk::Update3D(time);
}

void AGKCore::UpdateDeviceSize(unsigned short width, unsigned short height)
{
	agk::UpdateDeviceSize(width, height);
}

Text AGKCore::Upper(Text Original)
{
	return Text(agk::Upper(Original.GetCString()));
}


int AGKCore::Val(Text NumberString, int base)
{
	return agk::Val(NumberString.GetCString(), base);
}

float AGKCore::ValFloat(Text NumberString)
{
	return agk::ValFloat(NumberString.GetCString());
}
	
Point AGKCore::WorldToScreen(Point Coordinate)
{
	return Point(agk::WorldToScreenX(Coordinate.GetX()), agk::WorldToScreenY(Coordinate.GetY()));
}

float AGKCore::WorldToScreenX(float worldX)
{
	return agk::WorldToScreenX(worldX);
}

float AGKCore::WorldToScreenY(float worldY)
{
	return agk::WorldToScreenY(worldY);
}