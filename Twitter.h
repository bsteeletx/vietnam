#pragma once

#include "Text.h"

class Twitter
{
public:
	Twitter(Text Key, Text Secret);
	~Twitter(void);

	void Message(Text Message);
	
	void Setup(void);
};

