#pragma once

#include "../Defines.h"
#include "Image.h"
#include "Text.h"

class Notification
{
public:
	Notification(void);
	~Notification(void);
#if (OS == IOS)
	Notification(Text DateTime, Text Message, Text Data);
	bool get(void);
	Text getData(void);
	int getType(void);

	void reset(void);

	void setImage(Image Object);
	void setText(Text Object);
#endif
};

