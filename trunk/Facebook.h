#pragma once

#include "File.h"
#include "Text.h"
#include "../Defines.h"

class Facebook
{
public:
	Facebook(void);
	~Facebook(void);

#if ((OS == ANDROID) || (OS == IOS))
	void destroyLikeButton(void);
	void downloadFriendsPhoto(unsigned int friendID);

	Text getDownloadFile(void);
	FacebookDownloadState getDownloadState(void);
	void getFriends(void);
	unsigned int getFriendsCount(void);
	Text getFriendsID(int index);
	Text getFreindsName(int index);
	FacebookDownloadState getFriendsState(void);
	bool getLoggedIn(void);
	Text getUserID(void);
	Text getUserName(void);

	void login(void);
	void logout(void);

	void postOnFriendsWall(Text ID, Text Link, Text Picture, Text Name, Text Caption, Text Description);
	void postOnMyWall(Text Link, Text Picture, Text Name, Text Caption, Text Description);

	void setup(Text AppID);
	void showLikeButton(Text URL, int x, int y, int width, int height);
#endif
};

