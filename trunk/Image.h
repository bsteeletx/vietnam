#ifndef _IMAGE_H_
#define _IMAGE_H_

#include "Memblock.h"
#include "Point.h"
#include "Text.h"
#include "FileRead.h"
#include <vector>

class Text;
class Memblock;
class Read;

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
	Image (Read FileToInit, Text PathToParent);
	Image (Memblock Generator);
	
	//operators
	Image& operator= (const Image& newImage);
	
	//////////////////////General
	unsigned int Copy(Point Begin, Point End); 

	void Delete();
	
	void Get(); //TODO: Fill out
	bool GetExists(void);
	Text GetFilename(void);
	float GetHeight(void);
	unsigned int GetID(void);
	float GetWidth(void);

	void Print(float percentSize); 

	void Save(Text savedFilename); 
	void SetAsMask(unsigned int imageToMask, short colorDest, short colorSrc, int offsetXDest, int offsetYDest); 
	void SetMagFilter(bool linear);
	void SetMask(void); //TODO: Fill out
	void SetMinFilter(bool linear);
	void SetSavePixels(void); //TODO: Fill out
	void SetTransparentColor(void); //TODO: Fill out
	void SetWrapU(bool repeat);
	void SetWrapV(bool repeat);

	/////////////////////QR
	Text DecodeQR(); 

	void EncodeQR(); //TODO: Fill out
		
private:
	bool _ImageNumber(unsigned int number);
	
	void _Load(Text Filename, bool blackIsAlpha = false);
	void _Load(unsigned int assignedImageNumber, Text Filename, bool blackIsAlpha = false);
	void _LoadSub(unsigned int parentImage, Text SubImageFilename);
	void _LoadSub(unsigned int assignedImageNumber, unsigned int parentImage, Text subImageFilename);

	//bool _ParentNumber(unsigned int number);
	static std::vector<Text> _ParentImages;
	static std::vector<Text> _NonParentFileNames;
	static std::vector<unsigned int> _parentImageNumbers;
	static std::vector<unsigned int> _nonParentImageNumbers;

protected:
	bool _ColorChannel(short value);
	bool _Filename(Text filename);
	unsigned int _imageNumber;
};
#endif