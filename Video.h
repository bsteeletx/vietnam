#pragma once

#include "Point.h"
#include "Text.h"

class Video
{
public:
	Video(Text VideoFilename);
	~Video(void);

	float getDuration(void);
	short getError(void);
	float getHeight(void);
	bool getPlaying(void);
	float getPosition(void);
	float getWidth(void);

	void pause(void);
	void play(void);

	void setDimensions(Point Location, float width, float height);
	void setVolume(float value);
	void stop(void);
private:
	short error;
};

