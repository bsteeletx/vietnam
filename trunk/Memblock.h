#pragma once

#include "Image.h"

class Image;

class Memblock
{
public:
	Memblock(void);
	~Memblock(void);
	Memblock(Image Generator);
	Memblock(unsigned int size);
	
	int getByte(unsigned int offset);
	bool getExists(void);
	float getFloat(unsigned int offset);
	unsigned int getID(void);
	int getInt(unsigned int offset);
	short getShort(unsigned int offset);
	unsigned int getSize(void);

	void setByte(unsigned int offset, int value);
	void setFloat(unsigned int offset, float value);
	void setInt(unsigned int offset, int value);
	void setShort(unsigned int offset, short value);

private:
	unsigned int memBlockID;
};

