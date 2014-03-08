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
	agk::_Create(DateTime, Message, Data);
}
bool Notification::Get(void)
{
	return (bool) agk::GetNotification();
}
	
Text Notification::GetData(void)
{
	return Text(agk::GetNotificationData());
}

int Notification::GetType(void)
{
	return agk::GetNotificaitonType();
}

void Notification::Reset(void)
{
	agk::NotificationReset();
}

void Notification::SetImage(Image Object)
{
	agk::SetNotificationImage(Object.GetID());
}

void Notification::SetText(Text Object)
{
	agk::SetNotificaitonText(Object.GetCString());
}

void Notification::_Create(Text DateTime, Text Message, Text Data)
{
	agk::NotificationCreate(DateTime.getCString(), Message.getCString(), Data.getCString());
}
#endif