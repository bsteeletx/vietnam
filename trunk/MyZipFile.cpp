#include "MyZipFile.h"
#include "agk.h"

MyZipFile::MyZipFile(Text ZipFilename)
{
	fileID = agk::CreateZip(ZipFilename.getCString());
}


MyZipFile::~MyZipFile(void)
{
}

void MyZipFile::addEntry(Text LocalPathFilename, Text ZipPathFilename)
{
	agk::AddZipEntry(fileID, LocalPathFilename.getCString(), ZipPathFilename.getCString());
}

void MyZipFile::close(void)
{
	agk::CloseZip(fileID);
}