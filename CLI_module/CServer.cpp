/*
 * CServer.cpp
 *
 *  Created on: Aug 7, 2013
 *      Author: mmx
 */

#include "CServer.h"

CServer::CServer()
{
	m_serverSock = SOCKET_ERROR;
	m_clientSock = SOCKET_ERROR;
	m_retVal = 0;
	memset(m_szReq, 0, BUFFER_SIZE + 1);
	m_command = "";
}

CServer::~CServer()
{
	;
}

s_param params1[] =
{
		{ "param1", C_INTEGER, (void*)1 }
};

void* threadFunction1(void* threadArgs)
{
	;
}


int CServer::init()
{
	CModule mod1("mod1", threadFunction1, params1, sizeof(params1));
	//	CModule mod2("mod2", NULL, NULL, 0);
	//	CModule mod3("mod3", NULL, NULL, 0);

	return 0;
}

int CServer::createSocket()
{
	m_serverSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (m_serverSock == SOCKET_ERROR)
	{
		std::cout << "\nUnable to create socket\n";
		return SOCKET_ERROR;
	}

	sockaddr_in serverInfo;
	serverInfo.sin_family = PF_INET;
	serverInfo.sin_port = htons(PORT);
	serverInfo.sin_addr.s_addr = INADDR_ANY;

	m_retVal = bind(m_serverSock, (sockaddr*)&serverInfo, sizeof(serverInfo));

	if (m_retVal == SOCKET_ERROR)
	{
		std::cout << "\nUnable to bind\n";
		return SOCKET_ERROR;
	}

	return 0;
}

int CServer::listenSocket()
{
	m_retVal = listen(m_serverSock, SOMAXCONN);

	if (m_retVal == SOCKET_ERROR)
	{
		std::cout << "\nUnable to listen\n";
		return SOCKET_ERROR;
	}

	m_clientSock = accept(m_serverSock, NULL, NULL);

	if (m_clientSock == SOCKET_ERROR)
	{
		std::cout << "\nUnable to accept\n";
		return SOCKET_ERROR;
	}

	return 0;
}

int CServer::recieveRequest()
{
	memset(m_szReq, 0, BUFFER_SIZE + 1);

	m_retVal = recv(m_clientSock, m_szReq, BUFFER_SIZE, 0);

	if (m_retVal == SOCKET_ERROR)
	{
		std::cout << "Unable to recv\n";
		return SOCKET_ERROR;
	}

	std::cout << "\nGot the request from client:\n" << m_szReq << std::endl;

	m_command = m_szReq;

	return 0;
}

int CServer::parseRequest()
{
	return 0;
}

int CServer::sendRespond()
{
	std::cout << "\nSending response from server\n";

	m_command += "1234567890";

	m_retVal = send(m_clientSock, m_command.data(), m_command.length(), 0);

	if (m_retVal == SOCKET_ERROR)
	{
		std:: cout << "\nUnable to send\n";
		return SOCKET_ERROR;
	}

	return 0;
}


int CServer::closeSocket()
{
	shutdown(m_clientSock, SHUT_RDWR);
	shutdown(m_serverSock, SHUT_RDWR);

	return 0;
}
