#include "Notification.h"
#include "agk.h"

Notification::Notification(void)
{
}


Notification::~Notification(void)
{
}

#if (OS == IOS)
Notification::Notification(Text DateTime, Text Message, Text Data)
{
	agk::NotificationCreate(DateTime.getCString(), Message.getCString(), Data.getCString());
}
bool Notification::get(void)
{
	return (bool) agk::GetNotification();
}
	
Text Notification::getData(void)
{
	return Text(agk::GetNotificationData());
}

int Notification::getType(void)
{
	return agk::GetNotificaitonType();
}

void Notification::reset(void)
{
	agk::NotificationReset();
}

void Notification::setImage(Image Object)
{
	agk::SetNotificationImage(Object.getID());
}

void Notification::setText(Text Object)
{
	agk::SetNotificaitonText(Object.getCString());
}
#endif