#pragma once

#include "Text.h"

class Twitter
{
public:
	Twitter(Text Key, Text Secret);
	~Twitter(void);

	void message(Text Message);
	
	void setup(void);
};

