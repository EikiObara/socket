#pragma once

#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

const int MAX_MESSAGE = 100;

class Sock_server {
public:
	Sock_server();
	~Sock_server();

	bool Init(int port);

	bool Send_msg(char *msg);
	bool Recv_msg(char *msg);

private:
	WSADATA wsaData;

	SOCKET selfSock;
	SOCKET clientSock;
	
	sockaddr_in addr;

};


int sock_server();