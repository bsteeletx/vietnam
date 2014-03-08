#ifndef _SOUND_H_
#define _SOUND_H_

#include "Text.h"

class Sound
{
public:
	Sound();
	~Sound(void);
	Sound(unsigned int assignedNumber, Text Filename);
	Sound(Text Filename);

	void Delete();

	////////////Properties
	bool GetExists(void);
	unsigned int GetInstances(void);
	
	void Play(unsigned short volume = 100, bool loop = false);
	
	void SetSystemVolume(unsigned short volume);
	void Stop(void);

	////////////////Recording	Not Functional yet
	/*
	void IsRecording(); 

	void Record(void); 
	
	void StopRecording(void); 
	*/
	
	
private:
	unsigned int _soundID;

	bool _Filename(Text Filename);
};
#endif