#pragma once

#include "File.h"
#include "Text.h"

class MyZipFile :
	public File
{
public:
	MyZipFile(Text ZipFilename);
	~MyZipFile(void);

	void addEntry(Text LocalPathFilename, Text ZipPathFilename);

	void close(void);
};

