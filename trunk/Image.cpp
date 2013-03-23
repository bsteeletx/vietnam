#include "Image.h"
#include "agk.h"
#include "Text.h"

std::vector<Text> Image::ParentImages;
std::vector<unsigned int> Image::parentImageNumbers;
std::vector<Text> Image::NonParentFileNames;
std::vector<unsigned int> Image::nonParentImageNumbers;

Image::~Image(void)
{
	//if (getExists())
		//agk::DeleteImage(imageNumber);
}

Image::Image()
{
	imageNumber = 0;
}

Image::Image(unsigned int copyImageNumber)
{
	imageNumber = agk::LoadImage(agk::GetImageFilename(copyImageNumber));
}

Image::Image(unsigned int assignedImageNumber, Text Filename)
{
	if (agk::GetFileExists(Filename.getCString()))
		agk::LoadImage(assignedImageNumber, Filename.getCString());
}

Image::Image(Text filename, bool blackIsAlpha)
{
	if (_Filename(filename))
		load(filename, blackIsAlpha);
}

Image::Image(unsigned int assignedImageNumber, Text filename, bool blackIsAlpha)
{
	if (_ImageNumber(assignedImageNumber))
	{
		if (_Filename(filename))
			load(assignedImageNumber, filename, blackIsAlpha);
	}
}

Image::Image(Text subImageFilename, unsigned int parentImage)
{
	if (_Filename(subImageFilename))
		loadSub(parentImage, subImageFilename);
}

Image::Image(unsigned int assignedImageNumber, unsigned int parentImage, Text subImageFilename)
{
	if (_Filename(subImageFilename))
		loadSub(parentImage, subImageFilename);
}

Image& Image::operator= (const Image& newImage)
{
	imageNumber = newImage.imageNumber;

	return *this;
}

Image::Image(Point Begin, Point End)
{
	imageNumber = agk::CopyImage(imageNumber, (int) Begin.getX(), (int) Begin.getY(), (int) End.getX(), (int) End.getY());
}

Image::Image(Text codedText)
{
	imageNumber = agk::EncodeQRCode(codedText.getCString(), 2); 
}

Image::Image(File FileToInit, Text PathToParent)
{
	Text ParentImage = PathToParent;
	Text Filename("");
	bool alreadyLoaded = false;

	while(!FileToInit.FileEOF())
	{
		Text Line = FileToInit.getLine();
		Text Start;
		Text End;

		Line.splitAtDelimeter(&Start, &End, ':');

		if (Start == Text("PathFile"))
			Filename = End;
		
		if (Filename != Text(""))
			break;
	}

	//no parent image, bad doggy! no treat for you!
	if (ParentImage == Text(""))
	{
		for (unsigned int i = 0; i < NonParentFileNames.size(); i++)
		{
			if (NonParentFileNames[i] == Filename)
			{
				imageNumber = nonParentImageNumbers[i];
				return;
			}
		}
		
		imageNumber = agk::LoadImage(Filename.getCString());
		nonParentImageNumbers.push_back(imageNumber);
		NonParentFileNames.push_back(Filename);
	}
	else
	{
		//check to see if we've already loaded the parent image in memory
		for (unsigned int i = 0; i < ParentImages.size(); i++)
		{
			//checking each individual element
			if (ParentImages[i] == ParentImage)
			{
				imageNumber = agk::LoadSubImage(parentImageNumbers[i], Filename.getCString());
				alreadyLoaded = true;
				nonParentImageNumbers.push_back(imageNumber);
				NonParentFileNames.push_back(Filename);
				break; //found it, so break out of for
			}

		}

		if (!alreadyLoaded)
		{
			//load the parental image into the static variables
			ParentImages.push_back(ParentImage);
			parentImageNumbers.push_back(agk::LoadImage(ParentImage.getCString()));
			//then load the subimage
			imageNumber = agk::LoadSubImage(parentImageNumbers.back(), Filename.getCString());
			nonParentImageNumbers.push_back(imageNumber);
			NonParentFileNames.push_back(Filename);
		}
	}
	FileToInit.close();
}

Image::Image(Memblock Generator)
{
	agk::CreateImageFromMemblock(Generator.getID());
}

Text Image::decodeQRCode(void)
{
	return agk::DecodeQRCode(imageNumber);
}

bool Image::getExists(void)
{
	if (agk::GetImageExists(imageNumber))
		return true;
	else
		return false;
}

Text Image::getFilename(void)
{
	return agk::GetImageFilename(imageNumber);
}

float Image::getHeight(void)
{
	return agk::GetImageHeight(imageNumber);
}

unsigned int Image::getID(void)
{
	return imageNumber;
}

float Image::getWidth(void)
{
	return agk::GetImageWidth(imageNumber);
}

void Image::print(float percentSize)
{
	agk::PrintImage(imageNumber, percentSize);
}

void Image::save(Text savedFilename)
{
	if (_Filename(savedFilename))
		agk::SaveImage(imageNumber, savedFilename.getCString());
}

void Image::setMagFilter(bool linear)
{
	if (linear)
		agk::SetImageMagFilter(imageNumber, 1);
	else
		agk::SetImageMagFilter(imageNumber, 0);
}

void Image::setAsMask(unsigned int imageToMask, short colorDest, short colorSrc, int offsetXDest, int offsetYDest)
{
	if (_ImageNumber(imageToMask))
	{
		if (_ColorChannel(colorDest))
		{
			if (_ColorChannel(colorSrc))
				agk::SetImageMask(imageToMask, imageNumber, colorDest, colorSrc, offsetXDest, offsetYDest);
		}
	}
}

void Image::setMinFilter(bool linear)
{
	if (linear)
		agk::SetImageMinFilter(imageNumber, 1);
	else
		agk::SetImageMinFilter(imageNumber, 0);
}

void Image::setWrapU(bool repeat)
{
	if (repeat)
		agk::SetImageWrapU(imageNumber, 1);
	else
		agk::SetImageWrapU(imageNumber, 0);
}

void Image::setWrapV(bool repeat)
{
	if (repeat)
		agk::SetImageWrapV(imageNumber, 1);
	else
		agk::SetImageWrapV(imageNumber, 0);
}

void Image::load(Text filename, bool blackIsAlpha)
{
	imageNumber = agk::LoadImage(filename.getCString(), blackIsAlpha);
}

void Image::load(unsigned int assignedImageNumber, Text filename, bool blackIsAlpha)
{
	agk::LoadImage(assignedImageNumber, filename.getCString(), blackIsAlpha);
	imageNumber = assignedImageNumber;
}

void Image::loadSub(unsigned int parentImage, Text subImageFilename)
{
	imageNumber = agk::LoadSubImage(parentImage, subImageFilename.getCString());
}

void Image::loadSub(unsigned int assignedImageNumber, unsigned int parentImage, Text subImageFilename)
{
	agk::LoadSubImage(assignedImageNumber, parentImage, subImageFilename.getCString());
	imageNumber = assignedImageNumber;
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
	short lengthOfString = filename.getLength() - 1;

	for (int i = 3; i > -1; i--)
		tempFilename[3-i] = filename.getChar(lengthOfString - i);

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