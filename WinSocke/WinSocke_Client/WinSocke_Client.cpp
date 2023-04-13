#include "stdafx.h"
#include "WS2tcpip.h"
#include <WINSOCK2.H>
#include <stdio.h>
#include <thread>
#include <string>

#define SERVER_ADDRESS "127.0.0.1"
#define PORT           5150
#define MSGSIZE        1024

#pragma comment(lib, "ws2_32.lib")

void RecvThread(SOCKET& sClient)
{
	char        szMessage[MSGSIZE];
	int         ret;
	std::string strClose("ByeBye");

	while (TRUE)
	{
		ret = recv(sClient, szMessage, MSGSIZE, 0);
		if (ret > 0)
		{
			szMessage[ret] = '\0';

			printf("Received [%d bytes]: '%s'\n", ret, szMessage);
			std::string strMessage(szMessage);
			if (strMessage == strClose)
				break;
		}		
	}	
}

int main()
{
	WSADATA     wsaData;
	SOCKET      sClient;
	SOCKADDR_IN server;
	char        szMessage[MSGSIZE];
	int         ret;
	unsigned long ul = 1;
	std::string strClose("ByeBye");

	// Initialize Windows socket library
	WSAStartup(0x0202, &wsaData);

	// Create client socket
	sClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);


	ret = ioctlsocket(sClient, FIONBIO, (unsigned long *)&ul);//设置成非阻塞模式。
	//设置失败。
	if (ret == SOCKET_ERROR)
	{
		printf("Set ioctlsocket Failed");
	}

	// Connect to server
	memset(&server, 0, sizeof(SOCKADDR_IN));
	server.sin_family = AF_INET;
	InetPton(AF_INET, TEXT(SERVER_ADDRESS), &server.sin_addr.s_addr);
	server.sin_port = htons(PORT);

	connect(sClient, (struct sockaddr *)&server, sizeof(SOCKADDR_IN));

	std::thread thRecev(RecvThread, sClient);
	thRecev.detach();

	printf("Please Start Send And Recv:");

	while (TRUE)
	{		
		gets_s(szMessage);

		// Send message
		send(sClient, szMessage, strlen(szMessage), 0);
		std::string strMessage(szMessage);
		if (strMessage == strClose)
			break;
	}
	
	//detach之后不能join了
	//thRecev.join();

	// Clean up
	closesocket(sClient);
	WSACleanup();

	return 0;
}
