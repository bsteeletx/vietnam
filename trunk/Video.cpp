#include "Video.h"
#include "agk.h"

Video::Video(Text VideoFilename)
{
	error = agk::LoadVideo(VideoFilename.getCString());
}


Video::~Video(void)
{
}

float Video::getDuration(void)
{
	return agk::GetVideoDuration();
}

short Video::getError(void)
{
	return error;
}

float Video::getHeight(void)
{
	return agk::GetVideoHeight();
}

bool Video::getPlaying(void)
{
	if(agk::GetVideoPlaying())
		return true;

	return false;
}

float Video::getPosition(void)
{
	return agk::GetVideoPosition();
}

float Video::getWidth(void)
{
	return agk::GetVideoWidth();
}

void Video::pause(void)
{
	agk::PauseVideo();
}
	
void Video::play(void)
{
	agk::PlayVideo();
}

void Video::setDimensions(Point Location, float width, float height)
{
	agk::SetVideoDimensions(Location.getX(), Location.getY(), width, height);
}

void Video::setVolume(float value)
{
	agk::SetVideoVolume(value);
}
	
void Video::stop(void)
{
	agk::StopVideo();
}