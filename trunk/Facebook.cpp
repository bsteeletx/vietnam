#include "Facebook.h"
#include "agk.h"

Facebook::Facebook(void)
{
}


Facebook::~Facebook(void)
{
}

#if ((OS == ANDROID) || (OS == IOS))

void Facebook::destroyLikeButton(void)
{
	agk::FacebookDestroyLikeButton();
}

void Facebook::downloadFriendsPhoto(unsigned int friendID)
{
	agk::FacebookDownloadFriendsPhoto(friendID);
}

Text Facebook::getDownloadFile(void)
{

	return Text(agk::GetFacebookDownloadFile());
}

FacebookDownloadState Facebook::getDownloadState(void)
{
	short stateValue = agk::GetFacebookDownloadState();

	if (stateValue < 0)
		return ERRORSTATE;

	else return (FacebookDownloadState) stateValue;
}

void Facebook::getFriends(void)
{
	agk::FacebookGetFriends();
}

unsigned int Facebook::getFriendsCount(void)
{
	return agk::FacebookGetFriendsCount();
}

Text Facebook::getFriendsID(int index)
{
	return Text(agk::FacebookGetFriendsID(index);
}

Text Facebook::getFriendsName(int index)
{
	return Text(agk::FacebookGetFriendsName(index);
}

FacebookDownloadState Facebook::getFriendsState(void)
{
	int state = agk::FacebookGetFriendsState();

	switch (state)
	{
	case -1:
		return ERRORSTATE;
	case 0:
		return DOWNLOADING;
	case 1:
		return FINISHED;
	default:
		return NOACTIVITY;

}

bool Facebook::getLoggedIn(void)
{
	if (agk::GetFacebookLoggedIn() == 1)
		return true;

	return false;
}

Text Facebook::getUserID(void)
{
	return Text(agk::FacebookGetUserID());
}

Text Facebook::getUserName(void)
{
	return Text(agk::FAcebookGetUserName());
}

void Facebook::login(void)
{
	agk::FacebookLogin();
}

void Facebook::logout(void)
{
	agk::FacebookLogout();
}

void Facebook::postOnFriendsWall(Text ID, Text Link, Text Picture, Text Name, Text Caption, Text Description)
{
	agk::FacebookPostOnFriendsWall(ID.getCString(), Link.getCString(), Picture.getCString(), Name.getCString(), Caption.getCSring(), Description.getCString());
}

void Facebook::postOnMyWall(Text Link, Text Picture, Text Name, Text Caption, Text Description)
{
	agk::FacebookPostOnMyWall(Link.getCString(), Picture.getCString(), Name.getCString(), Caption.getCSring(), Description.getCString());
}

void Facebook::setup(Text AppID)
{
	agk::FacebookSetup(AppID.getCString());
}

void Facebook::showLikeButton(Text URL, int x, int y, int width, int height)
{
	agk::FacebookShowLikeButton(URL.getCString(), x, y, width, height);
}

#endif


	void setup(void);
	void showLikeButton(void);