#include "Image.h"
#include "agk.h"
#include "Text.h"

std::vector<Text> Image::_ParentImages;
std::vector<unsigned int> Image::_parentImageNumbers;
std::vector<Text> Image::_NonParentFileNames;
std::vector<unsigned int> Image::_nonParentImageNumbers;

Image::~Image(void)
{
	//if (GetExists())
		//agk::DeleteImage(_imageNumber);
}

Image::Image()
{
	_imageNumber = 0;
}

Image::Image(unsigned int copyImageNumber)
{
	_imageNumber = agk::LoadImage(agk::GetImageFilename(copyImageNumber));
}

Image::Image(unsigned int assignedImageNumber, Text Filename)
{
	if (agk::GetFileExists(Filename.GetCString()))
		agk::LoadImage(assignedImageNumber, Filename.GetCString());
}

Image::Image(Text filename, bool blackIsAlpha)
{
	if (_Filename(filename))
		_Load(filename, blackIsAlpha);
}

Image::Image(unsigned int assignedImageNumber, Text filename, bool blackIsAlpha)
{
	if (_ImageNumber(assignedImageNumber))
	{
		if (_Filename(filename))
			_Load(assignedImageNumber, filename, blackIsAlpha);
	}
}

Image::Image(Text subImageFilename, unsigned int parentImage)
{
	if (_Filename(subImageFilename))
		_LoadSub(parentImage, subImageFilename);
}

Image::Image(unsigned int assignedImageNumber, unsigned int parentImage, Text subImageFilename)
{
	if (_Filename(subImageFilename))
		_LoadSub(parentImage, subImageFilename);
}

Image& Image::operator= (const Image& newImage)
{
	_imageNumber = newImage._imageNumber;

	return *this;
}

Image::Image(Point Begin, Point End)
{
	_imageNumber = agk::CopyImage(_imageNumber, (int) Begin.GetX(), (int) Begin.GetY(), (int) End.GetX(), (int) End.GetY());
}

Image::Image(Text codedText)
{
	_imageNumber = agk::EncodeQRCode(codedText.GetCString(), 2); 
}

Image::Image(Read FileToInit, Text PathToParent)
{
	Text ParentImage = PathToParent;
	Text Filename("");
	bool alreadyLoaded = false;

	while(!FileToInit.IsEOF())
	{
		Text Line = FileToInit.Line();
		Text Start;
		Text End;

		Line.SplitAtDelimeter(&Start, &End, ':');

		if (Start == Text("PathFile"))
			Filename = End;
		
		if (Filename != Text(""))
			break;
	}

	//no parent image, bad doggy! no treat for you!
	if (ParentImage == Text(""))
	{
		for (unsigned int i = 0; i < _NonParentFileNames.size(); i++)
		{
			if (_NonParentFileNames[i] == Filename)
			{
				_imageNumber = _nonParentImageNumbers[i];
				return;
			}
		}
		
		_imageNumber = agk::LoadImage(Filename.GetCString());
		_nonParentImageNumbers.push_back(_imageNumber);
		_NonParentFileNames.push_back(Filename);
	}
	else
	{
		//check to see if we've already loaded the parent image in memory
		for (unsigned int i = 0; i < _ParentImages.size(); i++)
		{
			//checking each individual element
			if (_ParentImages[i] == ParentImage)
			{
				_imageNumber = agk::LoadSubImage(_parentImageNumbers[i], Filename.GetCString());
				alreadyLoaded = true;
				_nonParentImageNumbers.push_back(_imageNumber);
				_NonParentFileNames.push_back(Filename);
				break; //found it, so break out of for
			}

		}

		if (!alreadyLoaded)
		{
			//load the parental image into the static variables
			_ParentImages.push_back(ParentImage);
			_parentImageNumbers.push_back(agk::LoadImage(ParentImage.GetCString()));
			//then load the subimage
			_imageNumber = agk::LoadSubImage(_parentImageNumbers.back(), Filename.GetCString());
			_nonParentImageNumbers.push_back(_imageNumber);
			_NonParentFileNames.push_back(Filename);
		}
	}
	FileToInit.Close();
}

Image::Image(Memblock Generator)
{
	agk::CreateImageFromMemblock(Generator.GetID());
}

Text Image::DecodeQR(void)
{
	return agk::DecodeQRCode(_imageNumber);
}

void Image::Delete()
{
	agk::DeleteImage(_imageNumber);
}

bool Image::GetExists(void)
{
	if (agk::GetImageExists(_imageNumber))
		return true;
	else
		return false;
}

Text Image::GetFilename(void)
{
	return agk::GetImageFilename(_imageNumber);
}

float Image::GetHeight(void)
{
	return agk::GetImageHeight(_imageNumber);
}

unsigned int Image::GetID(void)
{
	return _imageNumber;
}

float Image::GetWidth(void)
{
	return agk::GetImageWidth(_imageNumber);
}

void Image::Print(float percentSize)
{
	agk::PrintImage(_imageNumber, percentSize);
}

void Image::Save(Text savedFilename)
{
	if (_Filename(savedFilename))
		agk::SaveImage(_imageNumber, savedFilename.GetCString());
}

void Image::SetMagFilter(bool linear)
{
	if (linear)
		agk::SetImageMagFilter(_imageNumber, 1);
	else
		agk::SetImageMagFilter(_imageNumber, 0);
}

void Image::SetAsMask(unsigned int imageToMask, short colorDest, short colorSrc, int offSetXDest, int offSetYDest)
{
	if (_ImageNumber(imageToMask))
	{
		if (_ColorChannel(colorDest))
		{
			if (_ColorChannel(colorSrc))
				agk::SetImageMask(imageToMask, _imageNumber, colorDest, colorSrc, offSetXDest, offSetYDest);
		}
	}
}

void Image::SetMinFilter(bool linear)
{
	if (linear)
		agk::SetImageMinFilter(_imageNumber, 1);
	else
		agk::SetImageMinFilter(_imageNumber, 0);
}

void Image::SetWrapU(bool repeat)
{
	if (repeat)
		agk::SetImageWrapU(_imageNumber, 1);
	else
		agk::SetImageWrapU(_imageNumber, 0);
}

void Image::SetWrapV(bool repeat)
{
	if (repeat)
		agk::SetImageWrapV(_imageNumber, 1);
	else
		agk::SetImageWrapV(_imageNumber, 0);
}

void Image::_Load(Text filename, bool blackIsAlpha)
{
	_imageNumber = agk::LoadImage(filename.GetCString(), blackIsAlpha);
}

void Image::_Load(unsigned int assignedImageNumber, Text filename, bool blackIsAlpha)
{
	agk::LoadImage(assignedImageNumber, filename.GetCString(), blackIsAlpha);
	_imageNumber = assignedImageNumber;
}

void Image::_LoadSub(unsigned int parentImage, Text subImageFilename)
{
	_imageNumber = agk::LoadSubImage(parentImage, subImageFilename.GetCString());
}

void Image::_LoadSub(unsigned int assignedImageNumber, unsigned int parentImage, Text subImageFilename)
{
	agk::LoadSubImage(assignedImageNumber, parentImage, subImageFilename.GetCString());
	_imageNumber = assignedImageNumber;
}

bool Image::_ColorChannel(short value)
{
	if (value > 0)
	{
		if (value < 5)
			return true;
	}

	return false;
}

bool Image::_Filename(Text filename)
{
	char tempFilename[8] = {NULL};
	short lengthOfString = filename.GetLength() - 1;

	for (int i = 3; i > -1; i--)
		tempFilename[3-i] = filename.GetChar(lengthOfString - i);

	if (strcmp(tempFilename, ".jpg") == 0) //equal
		return true;
	if (strcmp(tempFilename, ".png") == 0) //equal
		return true;

	return false;
}

bool Image::_ImageNumber(unsigned int number)
{
	if (number > 0)
	{
		if (agk::GetImageExists(number))
			return true;
	}

	return false;
}