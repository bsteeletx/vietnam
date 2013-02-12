#pragma once

#include "Text.h"

class Error
{
public:
	Error(void);
	~Error(void);

	Text getLast(void);

	bool getOccurred(void);

	void log(Text Error);
	
	void setMode(unsigned short mode);
};

