/*
 * CClient.cpp
 *
 *  Created on: Aug 7, 2013
 *      Author: mmx
 */

#include "CClient.h"

CClient::CClient()
{
	m_clientSock = SOCKET_ERROR;
	m_retVal = 0;
	memset (&m_szResp, 0, BUFFER_SIZE + 1);
}

CClient::~CClient()
{
	;
}

bool CClient::isConnected()
{
	return m_clientSock != SOCKET_ERROR;
}

int CClient::showHelp()
{
	std::cout <<
			"\nList of possible commands:"
			"\nhelp          show this help"
			"\nconnect       connect to the server (" << HOST_IP_ADDRESS << ":" << PORT << ")" <<
			"\ngetmodlist    show list of running modules"
			"\nquit          quit the program\n";

	return 0;
}

int CClient::connectToServer()
{
	m_clientSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (m_clientSock == SOCKET_ERROR)
	{
		std::cout << "\nUnable to create socket\n";
		return SOCKET_ERROR;
	}

	hostent *hostEnt = NULL;

	hostEnt = gethostbyname(HOST_NAME);

	if (hostEnt == NULL)
	{
		std::cout << "\nUnable to collect gethostbyname\n";
		m_clientSock = SOCKET_ERROR;
		return SOCKET_ERROR;
	}

	sockaddr_in serverInfo;

	serverInfo.sin_family = AF_INET;
	serverInfo.sin_port = htons(PORT);
	serverInfo.sin_addr = *((in_addr*)*hostEnt->h_addr_list);

	/*
	m_retVal = inet_pton(AF_INET, HOST_IP_ADDRESS, &serverInfo.sin_addr);

	if (m_retVal <= 0)
	{
		std::cout << "\ninet_pton error occured\n";
		m_clientSock = SOCKET_ERROR;
		return SOCKET_ERROR;
	}
	 */
	m_retVal = connect(m_clientSock, (sockaddr*)&serverInfo, sizeof(serverInfo));

	if (m_retVal == SOCKET_ERROR)
	{
		std::cout << "\nUnable to connect\n";
		m_clientSock = SOCKET_ERROR;
		return SOCKET_ERROR;
	}

	std::cout << "\nConnection made sucessfully\n";

	return 0;
}

int CClient::sendRequest(const std::string & command)
{
	std::cout << "\nSending request from client\n";

	m_retVal = send(m_clientSock, command.data(), command.length(), 0);

	if (m_retVal == SOCKET_ERROR)
	{
		std::cout << "\nUnable to send\n";
		return SOCKET_ERROR;
	}

	return 0;
}

int CClient::receiveRespond()
{
	memset (&m_szResp, 0, BUFFER_SIZE + 1);

	m_retVal = recv(m_clientSock, m_szResp, BUFFER_SIZE, 0);

	if (m_retVal == SOCKET_ERROR)
	{
		std::cout << "\nUnable to recv\n";
		return SOCKET_ERROR;
	}

	std::cout << "\nGot the response from server:\n" << m_szResp << std::endl;

	return 0;
}

int CClient::closeSocket()
{
	shutdown(m_clientSock, SHUT_RDWR);

	return 0;
}
