/*
 * client.cpp
 *
 *  Created on: Aug 7, 2013
 *      Author: mmx
 */

#include "CClient.h"
#include <iostream>

int main()
{
	CClient client;
	std::string command = "";

	while (true)
	{
		std::cout << "\ncommand: ";
		getline(std::cin, command);

		if ("help" == command)
		{
//			std::cout << command;
			client.showHelp();
		}
		else if ("connect" == command)
		{
//			std::cout << command;
			client.connectToServer();
		}
		else if ("quit" == command)
		{
//			std::cout << command;
			break;
		}
		else if ("" == command)
		{
			;
		}
		else
		{
//			std::cout << command;
			if (client.isConnected())
			{
				client.sendRequest(command);
				client.receiveRespond();
			}
			else
			{
				std::cout <<
						"\nThere is no connection to the server."
						"\nPlease use command connect or help to list all possible commands.\n";
			}
		}
	}

	client.closeSocket();

	return 0;
}
