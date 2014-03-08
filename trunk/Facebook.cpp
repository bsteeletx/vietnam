#include "Facebook.h"
#include "agk.h"

Facebook::Facebook(void)
{
}


Facebook::~Facebook(void)
{
}

#if ((OS == ANDROID) || (OS == IOS))

void Facebook::DestroyLikeButton(void)
{
	agk::FacebookDestroyLikeButton();
}

void Facebook::DownloadFriendsPhoto(unsigned int friendID)
{
	agk::FacebookDownloadFriendsPhoto(friendID);
}

Text Facebook::GetDownloadFile(void)
{

	return Text(agk::GetFacebookDownloadFile());
}

FacebookDownloadState Facebook::GetDownloadState(void)
{
	short stateValue = agk::GetFacebookDownloadState();

	if (stateValue < 0)
		return ERRORSTATE;

	else return (FacebookDownloadState) stateValue;
}

void Facebook::GetFriends(void)
{
	agk::FacebookGetFriends();
}

unsigned int Facebook::GetFriendsCount(void)
{
	return agk::FacebookGetFriendsCount();
}

Text Facebook::GetFriendsID(int index)
{
	return Text(agk::FacebookGetFriendsID(index);
}

Text Facebook::GetFriendsName(int index)
{
	return Text(agk::FacebookGetFriendsName(index);
}

FacebookDownloadState Facebook::GetFriendsState(void)
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

bool Facebook::GetLoggedIn(void)
{
	if (agk::GetFacebookLoggedIn() == 1)
		return true;

	return false;
}

Text Facebook::GetUserID(void)
{
	return Text(agk::FacebookGetUserID());
}

Text Facebook::GetUserName(void)
{
	return Text(agk::FAcebookGetUserName());
}

void Facebook::Login(void)
{
	agk::FacebookLogin();
}

void Facebook::Logout(void)
{
	agk::FacebookLogout();
}

void Facebook::PostOnFriendsWall(Text ID, Text Link, Text Picture, Text Name, Text Caption, Text Description)
{
	agk::FacebookPostOnFriendsWall(ID.getCString(), Link.getCString(), Picture.getCString(), Name.getCString(), Caption.getCSring(), Description.getCString());
}

void Facebook::PostOnMyWall(Text Link, Text Picture, Text Name, Text Caption, Text Description)
{
	agk::FacebookPostOnMyWall(Link.getCString(), Picture.getCString(), Name.getCString(), Caption.getCSring(), Description.getCString());
}

void Facebook::Setup(Text AppID)
{
	agk::FacebookSetup(AppID.getCString());
}

void Facebook::ShowLikeButton(Text URL, int x, int y, int width, int height)
{
	agk::FacebookShowLikeButton(URL.getCString(), x, y, width, height);
}

#endif


	void setup(void);
	void showLikeButton(void);