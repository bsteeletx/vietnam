#include "Twitter.h"
#include "agk.h"

Twitter::Twitter(Text Key, Text Secret)
{
	char twitterKey[128] = {NULL};
	char twitterSecret[128] = {NULL};
	strcpy(twitterKey, Key.getCString());
	strcpy(twitterSecret, Secret.getCString());
	agk::TwitterSetup(twitterKey, twitterSecret);
}


Twitter::~Twitter(void)
{
}

void Twitter::message(Text Message)
{
	char tweet[256] = {NULL};
	
	if (Message.len() <= 140)
	{
		strcpy(tweet, Message.getCString());
		agk::TwitterMessage(tweet);
	}
}
