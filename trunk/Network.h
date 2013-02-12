#pragma once

#include "Text.h"

class Network
{
public:
	Network();
	~Network();
	Network(Text NetworkName, Text MyName);
	Network(Text NetNameOrIP, Text MyName, unsigned short portNumber = 1025);

	void deleteClient(unsigned int client);

	bool getClientDisconnected(unsigned int client);
	float getClientFloat(unsigned int client);
	int getClientInt(unsigned int client);
	Text getClientName(unsigned int client);
	short getClientPing(unsigned int client);
	Text getClientUserData(unsigned int client);
	unsigned int getFirstClient(void);
	unsigned int getMyClientID(void);
	unsigned int getNextClient(void);
	short getNumClients(void);
	unsigned int getServerID(void);

	bool isActive(void);

	void setClientUserData(unsigned int client, unsigned int index, int value);
	void setLatency(unsigned short latency);
	void setLocalFloat(Text VariableName, float value, bool resetAfterRead);
	void setLocalInt(Text VariableName, int value, bool resetAfterRead);
	void setNoMoreClients(void);

protected:
	unsigned int networkID;
	unsigned short port;

private:
	bool isHost;

	void close(void);

	bool isANum(char test);
};