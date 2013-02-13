#include "agk.h"
#include "HTTP.h"

HTTP::HTTP()
{
	httpID = createConnection();
}

HTTP::~HTTP()
{
	deleteConnection();
}

void HTTP::close()
{
	agk::CloseHTTPConnection(httpID);
}

int HTTP::getFile(Text CompleteURLPath, Text LocalStorage, Text PostData)
{
	return agk::GetHTTPFile(httpID, CompleteURLPath.getCString(), LocalStorage.getCString(), PostData.getCString());
}

int HTTP::getFile(Text CompleteURLPath, Text LocalStorage)
{
	return agk::GetHTTPFile(httpID, CompleteURLPath.getCString(), LocalStorage.getCString());
}

bool HTTP::getFileComplete()
{
	if (agk::GetHTTPFileComplete(httpID) == 1)
		return true;

	return false;
}

float HTTP::getFileProgress()
{
	return agk::GetHTTPFileProgress(httpID);
}

Text HTTP::getResponse()
{
	return Text(agk::GetHTTPResponse(httpID));
}

bool HTTP::getResponseReady()
{
	if (agk::GetHTTPResponseReady(httpID) == 1)
		return true;

	return false;
}

int HTTP::sendFile(Text Page, Text PostData, Text LocalFile)
{
	return agk::SendHTTPFile(httpID, Page.getCString(), PostData.getCString(), LocalFile.getCString());
}

Text HTTP::sendRequest(Text Page)
{
	return Text(agk::SendHTTPRequest(httpID, Page.getCString()));
}

Text HTTP::sendRequest(Text Page, Text PostData)
{
	return Text(agk::SendHTTPRequest(httpID, Page.getCString(), PostData.getCString()));
}

int HTTP::sendRequestASync(Text Page, Text PostData)
{
	return agk::SendHTTPRequestASync(httpID, Page.getCString(), PostData.getCString());
}

int HTTP::sendRequestASync(Text Page)
{
	return agk::SendHTTPRequestASync(httpID, Page.getCString());
}

int HTTP::setHost(Text Host, bool isSecure)
{
	if (isSecure)
		return agk::SetHTTPHost(httpID, Host.getCString(), 1);

	return agk::SetHTTPHost(httpID, Host.getCString(), 0);
}

int HTTP::setHost(Text Host, bool isSecure, Text Username, Text Password)
{
	if (isSecure)
		return agk::SetHTTPHost(httpID, Host.getCString(), 1, Username.getCString(), Password.getCString());

	return agk::SetHTTPHost(httpID, Host.getCString(), 0, Username.getCString(), Password.getCString());
}

unsigned int HTTP::createConnection()
{
	return agk::CreateHTTPConnection();
}

void HTTP::deleteConnection()
{
	agk::DeleteHTTPConnection(httpID);
}