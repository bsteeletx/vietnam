#pragma once

#include "../Defines.h"
#include "Text.h"
#include "Point.h"

class NFC
{
public:
	NFC(void);
	~NFC(void);

	bool getNFCExists(void);
	unsigned int getRawFirstNFCDevice(void);
	unsigned int getRawNFCCount(void);
	Text getRawNFCData(void);
	DownloadState getRawNFCDataState(void);
	Text getRawNFCName(void);
	unsigned int getRawNextNFCDevice(void);

	void sendRawNFCData(Text Message);

private:
	unsigned int deviceIndex;
};

