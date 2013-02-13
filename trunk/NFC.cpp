#include "NFC.h"
#include "agk.h"

NFC::NFC(void)
{
	deviceIndex = 0;
}


NFC::~NFC(void)
{
}

bool NFC::getNFCExists(void)
{
	if (agk::GetNFCExists())
		return true;

	return false;
}

unsigned int NFC::getRawNFCCount(void)
{
	return agk::GetRawNFCCount();
}

Text NFC::getRawNFCData(void)
{
	return Text(agk::GetRawNFCData(deviceIndex));
}
	
DownloadState NFC::getRawNFCDataState(void)
{
	return (DownloadState) agk::GetRawNFCDataState(deviceIndex);
}
	
Text NFC::getRawNFCName(void)
{
	return Text(agk::GetRawNFCName(deviceIndex));
}

unsigned int NFC::getRawFirstNFCDevice(void)
{
	return agk::GetRawFirstNFCDevice();
}
	
unsigned int NFC::getRawNextNFCDevice(void)
{
	return agk::GetRawNextNFCDevice();
}

void NFC::sendRawNFCData(Text Message)
{
	char buffer[64] = {NULL};

	strcpy (buffer, Message.getCString());

	agk::SendRawNFCData(deviceIndex, buffer);
}