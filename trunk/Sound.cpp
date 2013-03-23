#include "agk.h"
#include "Sound.h"

Sound::Sound(void)
{
	soundID = 0;
}

Sound::~Sound(void)
{
	//if (getExists())
	//	agk::DeleteSound(soundID);
}

Sound::Sound(unsigned int assignedNumber, Text Filename)
{
	if (assignedNumber)
	{
		if (_Filename(Filename))
		{
			agk::LoadSound(assignedNumber, Filename.getCString());
			soundID = assignedNumber;
		}
	}
}

Sound::Sound(Text Filename)
{
	if (_Filename(Filename))
		soundID = agk::LoadSound(Filename.getCString());
}

bool Sound::getExists(void)
{
	if (agk::GetSoundExists(soundID) == 1)
		return true;

	return false;
}

unsigned int Sound::getInstances(void)
{
	return agk::GetSoundInstances(soundID);
}

void Sound::play(unsigned short volume, bool loop)
{
	if (volume <= 100)
	{
		if (loop)
			agk::PlaySound(soundID, volume, 1);
		else
			agk::PlaySound(soundID, volume, 0);
	}
}

void Sound::setSystemVolume(unsigned short volume)
{
	if (volume <= 100)
		agk::SetSoundSystemVolume(volume);
}

void Sound::stop(void)
{
	agk::StopSound(soundID);
}

bool Sound::_Filename(Text Filename)
{
	Text Extension = Filename.right(4);
	short lengthOfString = Filename.getLength() - 1;

	//for (int i = 3; i > 0; i--)
		//tempFilename[i] = Filename.getChar(lengthOfString - 1);
	
	if (Extension == Text(".wav"))
		return true;
	if (Extension == Text(".mp3"))
		return true;

	return false;
}