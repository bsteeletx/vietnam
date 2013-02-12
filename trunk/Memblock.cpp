#include "Memblock.h"
#include "agk.h"

Memblock::Memblock(void)
{
	memBlockID = 0;
}


Memblock::~Memblock(void)
{
}

Memblock::Memblock(unsigned int size)
{
	memBlockID = agk::CreateMemblock(size);
}

Memblock::Memblock(Image Generator)
{
	memBlockID = agk::CreateMemblockFromImage(Generator.getID());
}

int Memblock::getByte(unsigned int offset)
{
	return agk::GetMemblockByte(memBlockID, offset);
}

bool Memblock::getExists(void)
{
	if (agk::GetMemblockExists(memBlockID))
		return true;

	return false;
}

float Memblock::getFloat(unsigned int offset)
{
	return agk::GetMemblockFloat(memBlockID, offset);
}

unsigned int Memblock::getID(void)
{
	return memBlockID;
}

int Memblock::getInt(unsigned int offset)
{
	return agk::GetMemblockInt(memBlockID, offset);
}

short Memblock::getShort(unsigned int offset)
{
	return agk::GetMemblockShort(memBlockID, offset);
}

unsigned int Memblock::getSize(void)
{
	return agk::GetMemblockSize(memBlockID);
}

void Memblock::setByte(unsigned int offset, int value)
{
	agk::SetMemblockByte(memBlockID, offset, value);
}

void Memblock::setFloat(unsigned int offset, float value)
{
	agk::SetMemblockFloat(memBlockID, offset, value);
}

void Memblock::setInt(unsigned int offset, int value)
{
	agk::SetMemblockInt(memBlockID, offset, value);
}

void Memblock::setShort(unsigned int offset, short value)
{
	agk::SetMemblockShort(memBlockID, offset, value);
}