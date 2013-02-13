#pragma once
#include "Text.h"
#include <string>

class Text;

class File
{
public:
	File();
	~File(void);
	File(bool read, Text Filename);

	File &operator= (const File &NewFile);

	File chooseRaw(Text ValidExtensions);
	void close(void);

	void deleteFolder(void);

	void extractZip(Text ZipFilename, Text Path);

	bool FileEOF(void);

	Text getCurrentDir(void);
	bool getExists(void);

	float getFloat(void);
	int getID(void);
	int getInt(void);
	Text getFirstFile(void);
	Text getFirstFolder(void);
	Text getFolder(void);
	Text getLine(void);
	Text getNextFile(void);
	Text getNextFolder(void);
	Text getReadPath(void);
	unsigned int getSize(void);	
	Text getString(void);
	Text getWritePath(void);

	void makeFolder(Text Name);
	
	void putFloat(float value);
	void putInt(int value);
	void putLine(Text Value);
	void putString(Text Value);

	void reOpen(void);
	short readByte(void);
	float readFloat(void);
	int readInteger(void);
	Text readLine(void);
	Text readString(void);

	void setCurrentDir(Text Dir);
	void setFolder(Text Folder);
	void setWritePath(Text Dir);

	void writeByte(short value);
	void writeFloat(float value);
	void writeInteger(int value);
	void writeLine(Text Value);
	void writeString(Text Value);

protected:
	unsigned int fileID;
	bool openToRead;
	std::string nameOfFile;

	bool getExists(Text Filename);
	bool isOpen(void);
	void open(bool read, Text Filename);
};
