/*
 * CClient.h
 *
 *  Created on: Aug 7, 2013
 *      Author: mmx
 */

#ifndef CCLIENT_H_
#define CCLIENT_H_

#include "GlobalConstants.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>
#include <string.h>

class CClient
{
private:
	int m_clientSock;
	int m_retVal;
	char m_szResp[BUFFER_SIZE + 1];
public:
	CClient();
	~CClient();
	bool isConnected();
	int showHelp();
	int connectToServer();
	int sendRequest(const std::string & command);
	int receiveRespond();
	int closeSocket();
};

#endif /* CCLIENT_H_ */
