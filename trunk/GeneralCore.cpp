#include "GeneralCore.h"
#include "agk.h"

GeneralCore::GeneralCore(void)
{
}


GeneralCore::~GeneralCore(void)
{
}

float GeneralCore::aCos(float value)
{
	return agk::ACos(value);
}

float GeneralCore::aCosRad(float value)
{
	return agk::ACosRad(value);
}

float GeneralCore::aSin(float value)
{
	return agk::ASin(value);
}

float GeneralCore::aSinRad(float value)
{
	return agk::ASinRad(value);
}

float GeneralCore::aTan(float value)
{
	return agk::ATan(value);
}

float GeneralCore::aTan2(float y, float x)
{
	return agk::ATan2(y, x);
}

float GeneralCore::aTan2Rad(float y, float x)
{
	return agk::ATan2Rad(y, x);
}

float GeneralCore::aTanFull(float x, float y)
{
	return agk::ATanFull(x, y);
}

float GeneralCore::aTanFullRad(float x, float y)
{
	return agk::ATanFullRad(x, y);
}

float GeneralCore::abs(float value)
{
	return agk::Abs(value);
}

unsigned int GeneralCore::asc(char alpha)
{
	const char single[1] = {alpha};
	return agk::Asc(single);
}

Text GeneralCore::bin(int value)
{
	return Text(agk::Bin(value));
}
	
int GeneralCore::ceil(float value)
{
	return agk::Ceil(value);
}

Text GeneralCore::chr(unsigned int ascii)
{
	return Text(agk::Chr(ascii));
}

void GeneralCore::clearDepthBuffer(void)
{
	agk::ClearDepthBuffer();
}

void GeneralCore::clearScreen(void)
{
	agk::ClearScreen();
}

float GeneralCore::cos(float value)
{
	return agk::Cos(value);
}

float GeneralCore::cosRad(float value)
{
	return agk::CosRad(value);
}

void GeneralCore::enableClearColor(bool clearEachFrame)
{
	if (clearEachFrame)
		agk::EnableClearColor(1);
	else
		agk::EnableClearColor(0);
}

float GeneralCore::fMod(float value, float modValue)
{
	return agk::FMod(value, modValue);
}

int GeneralCore::floor(float value)
{
	return agk::Floor(value);
}
	
unsigned short GeneralCore::getDeviceHeight(void)
{
	return agk::GetDeviceHeight();
}

unsigned short GeneralCore::getDeviceWidth(void)
{
	return agk::GetDeviceWidth();
}

float GeneralCore::getAspect(void)
{
	return agk::GetDisplayAspect();
}

Orientation GeneralCore::getOrientation(void)
{
	return (Orientation) agk::GetOrientation();
}

unsigned int GeneralCore::getPolygonsDrawn(void)
{
	return agk::GetPolygonsDrawn();
}

bool GeneralCore::getResumed(void)
{
	if (agk::GetResumed() == 1)
		return true;
	
	return false;
}

float GeneralCore::getScreenBoundsBottom(void)
{
	return agk::GetScreenBoundsBottom();
}

float GeneralCore::getScreenBoundsLeft(void)
{
	return agk::GetScreenBoundsLeft();
}

float GeneralCore::getScreenBoundsRight(void)
{
	return agk::GetScreenBoundsRight();
}

float GeneralCore::getScreenBoundsTop(void)
{
	return agk::GetScreenBoundsTop();
}

unsigned int GeneralCore::getVerticesProcessed(void)
{
	return agk::GetVerticesProcessed();
}

float GeneralCore::getViewOffsetX(void)
{
	return agk::GetViewOffsetX();
}

float GeneralCore::getViewOffsetY(void)
{
	return agk::GetViewOffsetY();
}

float GeneralCore::getViewZoom(void)
{
	return agk::GetViewZoom();
}

unsigned short GeneralCore::getVirtualHeight(void)
{
	return agk::GetVirtualHeight();
}

unsigned short GeneralCore::getVirtualWidth(void)
{
	return agk::GetVirtualWidth();
}

Text GeneralCore::hex(int value)
{
	return Text(agk::Hex(value));
}

int GeneralCore::mod(int value, int modValue)
{
	return agk::Mod(value, modValue);
}

int GeneralCore::random(void)
{
	return agk::Random();
}

int GeneralCore::random(unsigned int from, unsigned int to)
{
	return agk::Random(from, to);
}

int GeneralCore::randomSign(int value)
{
	return agk::RandomSign(value);
}

void GeneralCore::render(void)
{
	agk::Render();
}

void GeneralCore::render2DBack(void)
{
	agk::Render2DBack();
}

void GeneralCore::render2DFront(void)
{
	agk::Render2DFront();
}

void GeneralCore::render3D(void)
{
	agk::Render3D();
}

int GeneralCore::round(float value)
{
	return agk::Round(value);
}
	
float GeneralCore::screenFPS(void)
{
	return agk::ScreenFPS();
}

Point GeneralCore::screenToWorld(Point ScreenLoc)
{
	return Point(agk::ScreenToWorldX(ScreenLoc.getX()), agk::ScreenToWorldY(ScreenLoc.getY()));
}

float GeneralCore::screenToWorldX(float x)
{
	return agk::ScreenToWorldX(x);
}

float GeneralCore::screenToWorldY(float y)
{
	return agk::ScreenToWorldY(y);
}

void GeneralCore::setBorderColor(RGBA BorderColor)
{
	agk::SetBorderColor(BorderColor.getRed(), BorderColor.getGreen(), BorderColor.getBlue());
}

void GeneralCore::setAspect(float aspect)
{
	agk::SetDisplayAspect(aspect);
}

void GeneralCore::setOrientationAllowed(bool portrait, bool revPortrait, bool landscape, bool revLandscape)
{
	agk::SetOrientationAllowed((int) portrait, (int) revPortrait, (int) landscape, (int) revLandscape);
}

void GeneralCore::setRandomSeed(unsigned int value)
{
	agk::SetRandomSeed(value);
}

void GeneralCore::setResolutionMode(bool setFullRez)
{
	agk::SetResolutionMode((int) setFullRez);
}

float GeneralCore::sin(float value)
{
	return agk::Sin(value);
}

float GeneralCore::sinRad(float value)
{
	return agk::SinRad(value);
}

Text GeneralCore::spaces(unsigned int length)
{
	return Text(agk::Spaces(length));
}

float GeneralCore::sqrt(float value)
{
	return agk::Sqrt(value);
}

void GeneralCore::stepPhysics(float time)
{
	agk::StepPhysics(time);
}

Text GeneralCore::str(float value, unsigned int decimals)
{
	return Text(agk::Str(value, decimals));
}

Text GeneralCore::str(int value)
{
	return Text(agk::Str(value));
}

void GeneralCore::swap(void)
{
	agk::Swap();
}

void GeneralCore::sync(void)
{
	agk::Sync();
}
	
float GeneralCore::tan(float value)
{
	return agk::Tan(value);
}

float GeneralCore::tanRad(float value)
{
	return agk::TanRad(value);
}

int GeneralCore::trunc(float value)
{
	return agk::Trunc(value);
}

void GeneralCore::update(float time)
{
	agk::Update(time);
}

void GeneralCore::update2D(float time)
{
	agk::Update2D(time);
}

void GeneralCore::update3D(float time)
{
	agk::Update3D(time);
}

void GeneralCore::updateDevicesize(unsigned short width, unsigned short height)
{
	agk::UpdateDeviceSize(width, height);
}

int GeneralCore::val(Text NumberString, int base)
{
	return agk::Val(NumberString.getCString(), base);
}

float GeneralCore::valFloat(Text NumberString)
{
	return agk::ValFloat(NumberString.getCString());
}
	
Point GeneralCore::worldToScreen(Point Coordinate)
{
	return Point(agk::WorldToScreenX(Coordinate.getX()), agk::WorldToScreenY(Coordinate.getY()));
}

float GeneralCore::worldToScreenX(float worldX)
{
	return agk::WorldToScreenX(worldX);
}

float GeneralCore::worldToScreenY(float worldY)
{
	return agk::WorldToScreenY(worldY);
}