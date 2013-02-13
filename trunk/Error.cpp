#include "Error.h"
#include "agk.h"

Error::Error(void)
{
}


Error::~Error(void)
{
}

Text Error::getLast(void)
{
	return Text(agk::GetLastError());
}

bool Error::getOccurred(void)
{
	if (agk::GetErrorOccurred() == 1)
		return true;
	
	return false;
}

void Error::log(Text Error)
{
	char logMessage[64];

	if (Error.getLength() < 64)
		strcpy(logMessage, Error.getCString());

	agk::Log(logMessage);
}

void Error::setMode(unsigned short mode)
{
	agk::SetErrorMode(mode);
}