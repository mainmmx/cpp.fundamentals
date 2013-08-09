/*
 * CServer.h
 *
 *  Created on: Aug 7, 2013
 *      Author: mmx
 */

#ifndef CSERVER_H_
#define CSERVER_H_

#include "GlobalConstants.h"
#include "CModule.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>
#include <string.h>

class CServer
{
private:
	int m_serverSock;
	int m_clientSock;
	int m_retVal;
	char m_szReq[BUFFER_SIZE + 1];
	char m_szResp[BUFFER_SIZE + 1];
	std::string m_command;
public:
	CServer();
	~CServer();
	int init();
	int createSocket();
	int listenSocket();
	int recieveRequest();
	int parseRequest();
	int sendRespond();
	int closeSocket();
};

#endif /* CSERVER_H_ */
