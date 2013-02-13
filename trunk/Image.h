#pragma once

#include "Memblock.h"
#include "Point.h"
#include "Text.h"
#include "File.h"
#include <vector>

class Text;
class File;
class Memblock;

class Image
{
public:
	//constructors/deconstructors
	~Image(void);
	Image(void);
	Image (unsigned int assignedImageNumber, Text Filename);
	Image (unsigned int copyImageNumber);
	Image (Point Begin, Point End);
	Image (Text EncodedText);
	Image (Text Filename, bool blackIsAlpha); 
	Image (unsigned int assignedImageNumber, Text Filename, bool blackIsAlpha = false);
	Image (Text SubImageFilename, unsigned int parentImage);
	Image (unsigned int assignedImageumber, unsigned int parentImage, Text SubImageFilename);
	Image (File FileToInit, Text PathToParent);
	Image (Memblock Generator);
	
	//operators
	Image& operator= (const Image& newImage);
	
	//methods
	unsigned int copy(Point Begin, Point End); 

	Text decodeQRCode(void);
	void deleteAll(void);

	unsigned int encodeQRCode(Text CodedMessage);

	unsigned int getCaptured(void);
	unsigned int getChosen(void);
	bool getExists(void);
	Text getFilename(void);
	float getHeight(void);
	unsigned int getID(void);
	float getWidth(void);

	bool isCapturing(void);
	bool isChoosing(void);

	void print(float percentSize); 

	void save(Text savedFilename); 
	void setAsMask(unsigned int imageToMask, short colorDest, short colorSrc, int offsetXDest, int offsetYDest); 
	void setAsQRCode(void);
	void setMagFilter(bool linear);
	void setMinFilter(bool linear);
	void setWrapU(bool repeat);
	void setWrapV(bool repeat);
	void showCaptureScreen(void);
	void showChooseScreen(void);
	
private:
	void load(Text Filename, bool blackIsAlpha = false);
	void load(unsigned int assignedImageNumber, Text Filename, bool blackIsAlpha = false);
	void loadSub(unsigned int parentImage, Text SubImageFilename);
	void loadSub(unsigned int assignedImageNumber, unsigned int parentImage, Text subImageFilename);

	bool _Filename(Text filename);
	bool _ImageNumber(unsigned int number);
	//bool _ParentNumber(unsigned int number);
	static std::vector<Text> ParentImages;
	static std::vector<Text> NonParentFileNames;
	static std::vector<unsigned int> parentImageNumbers;
	static std::vector<unsigned int> nonParentImageNumbers;

protected:
	bool _ColorChannel(short value);
	unsigned int imageNumber;
};