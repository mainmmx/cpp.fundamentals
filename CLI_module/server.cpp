/*
 * server.cpp
 *
 *  Created on: Aug 7, 2013
 *      Author: mmx
 */

#include "CServer.h"

int main()
{
	CServer server;

	server.init();

	server.createSocket();
	server.listenSocket();

	while (0 == server.recieveRequest())
	{
		server.parseRequest();
		server.sendRespond();
	}

	server.closeSocket();

	return 0;
}
