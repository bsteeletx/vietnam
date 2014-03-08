#ifndef _AGKCORE_H_
#define _AGKCORE_H_

#include "Point.h"
#include "Color.h"
#include "Text.h"
#include "../Defines.h"

class AGKCore
{
public:
	AGKCore(void);
	~AGKCore(void);

	//////////Display
	void ClearDepthBuffer(void);
	void ClearScreen(void);

	void DeleteAllImages();
	void DeleteAllSprites();
	void DeleteAllText();

	void EnableClearColor(bool clearEachFrame);
	void EnableClearDepth(bool clearEachFrame);

	unsigned short GetDeviceHeight(void);
	unsigned short GetDeviceWidth(void);
	float GetDisplayAspect(void);
	Orientation GetOrientation(void);
	unsigned int GetPolygonsDrawn(void);
	bool GetResumed(void);
	float GetScreenBoundsBottom(void);
	float GetScreenBoundsLeft(void);
	float GetScreenBoundsRight(void);
	float GetScreenBoundsTop(void);
	unsigned int GetVerticesProcessed(void);
	float GetViewOffsetX(void);
	float GetViewOffsetY(void);
	float GetViewZoom(void);
	unsigned short GetVirtualHeight(void);
	unsigned short GetVirtualWidth(void);

	void Render(void);
	void Render2DBack(void);
	void Render2DFront(void);
	void Render3D(void);

	float ScreenFPS(void);
	Point ScreenToWorld(Point ScreenLoc);
	float ScreenToWorldX(float screenX);
	float ScreenToWorldY(float screenY);
	void SetBorderColor(Color BorderColor);
	void SetDisplayAspect(float aspect);
	void SetOrientationAllowed(bool portrait, bool revPortrait, bool landscape, bool revLandscape);
	void SetResolutionMode(bool setFullRez);
	void SetScissor(); //TODO: Fill out
	void SetSyncRate(); //TODO: Fill out
	void SetTransitionMode(); //TODO: Fill out
	void SetVSync(); //TODO: Fill out
	void SetViewOffset(); //TODO: Fill out
	void SetViewZoom(); //TODO: Fill out
	void SetViewZoomMode(); //TODO: Fill out
	void SetVirtualResolution(); //TODO: Fill out
	void Swap(void);
	void Sync(void);

	void UpdateDeviceSize(unsigned short width, unsigned short height);

	Point WorldToScreen(Point Coordinate);
	float WorldToScreenX(float worldX);
	float WorldToScreenY(float worldY);

	/////////////Strings
	unsigned int Asc(char alpha);

	Text Bin(int value);

	Text Chr(unsigned int ascii);
	unsigned int CountStringTokens(Text Original, char delimeter);

	Text GetStringToken(Text Original, char delimeter, unsigned int token);

	Text Hex(int value);

	Text Left(Text Original, unsigned int count);
	unsigned int Len(Text Test);
	Text Lower(Text Original);

	Text Mid(Text Original, unsigned int position, int length);

	Text Right(Text Original, unsigned int count);

	Text Spaces(unsigned int spaceCount);
	Text Str(float value, unsigned int decimals);
	Text Str(int value);

	Text Upper(Text Original);

	int Val(Text NumberString, int base = 10);
	float ValFloat(Text NumberString);
	
	/////////////////////////////General
	void StepPhysics(float time);

	void Update(float time = 0.0f);
	void Update2D(float time = 0.0f);
	void Update3D(float time = 0.0f);

	/////////////////////////////Misc
	void DownloadExpansionFile(); //TODO: Fill in
	
	void GetAppName(void); //TODO: Fill in
	void GetDeviceLanguage(void); //TODO Fill out
	void GetDeviceName(); //TODO: Fill out
	void GetExpansionFileProgress(); //TODO: Fill out
	void GetExpansionFileState(); //TODO: Fill out
	void GetFrameTime(); //TODO: Fill out
	unsigned int GetLoadedImages(); //TODO: Fill out
	void GetMilliseconds(); //TODO: Fill out
	void GetSeconds(); //TODO: Fill out
	Text GetUnassignedImageFileName(unsigned int uAImage); //TODO: Fill Out
	unsigned int GetUnassignedImages(); //TODO: Fill out

	void HTTPDecode(void); //TODO: fill out
	void HTTPEncode(void); //TODO: fill out

	void Message(); //TODO: Fill out
	
	void ResetTimer(); //TODO: Fill out
		
	void SetDefaultMagFilter(void); //TODO: Fill out
	void SetDefaultMinFilter(void); //TODO: Fill out
	void SetDefaultWrapU(void); //TODO: Fill out
	void SetDefaultWrapV(void); //TODO: Fill out
	void SetExpansionFileVersion(); //TODO: Fill out
	void SetGenerateMipmaps(); //TODO: Fill out
	void setGlobal3DDepth(int depth); //TODO: Fill in
	void SetSortCreated(void); //TODO: Fill out
	void SetSortDepth(void); //TODO: Fill out
	void SetSortTextures(void); //TODO: Fill out
	void SetSortTransparentDepth(void); //TODO: Fill out
	void SetWindowTitle(void); //TODO: Fill out
	void Sha1(void); //TODO: Fill out
	void Sleep(void); //TODO: Fill out
	
	void Timer(void); //TODO: Fill out

	////////////////////////////Maths
	float ACos(float value);
	float ACosRad(float value);
	float ASin(float value);
	float ASinRad(float value);
	float ATan(float value);
	float ATan2(float y, float x);
	float ATan2Rad(float y, float x);
	float ATanFull(float x, float y);
	float ATanFullRad(float x, float y);
	float ATanRad(float value);
	float Abs(float value);

	int Ceil(float value);
	float Cos(float value);
	float CosRad(float value);

	float FMod(float value, float modValue);
	int Floor(float value);

	int Mod(int value, int modValue);

	int Random(void);
	int Random(unsigned int from, unsigned int to);
	int RandomSign(int value);
	int Round(float value);

	void SetRandomSeed(unsigned int value);
	float Sin(float value);
	float SinRad(float value);
	float SqRt(float value);

	float Tan(float value);
	float TanRad(float value);
	int Trunc(float value);

	///////////////////////Drawing
	void DrawLine(); //TODO: FILL OUT
};

#endif