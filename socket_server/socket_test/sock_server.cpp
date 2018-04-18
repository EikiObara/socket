#include <cstdio>
#include "sock_server.h"

Sock_server::Sock_server() {
}

Sock_server::~Sock_server() {
	closesocket(selfSock);
	closesocket(clientSock);
	WSACleanup();

	Sleep(1000);
}

bool Sock_server::Init(int port) {

	////////////////////////////////////////////////////////
	int isStartUp = WSAStartup(MAKEWORD(2, 0), &wsaData);

	if (isStartUp != 0) {
		printf("[ERROR][sock_server : Init] start up failed\n");
		return false;
	}
	else {
		printf("[ O K ][sock_server : Init] start up success\n");
	}
	////////////////////////////////////////////////////////////

	//サーバのポートとアドレスの設定
	selfSock = socket(AF_INET, SOCK_STREAM, 0);

	if (selfSock == INVALID_SOCKET) {
		printf("[ERROR][sock_server : Init] socket failed\n");
		return false;
	}
	else {
		printf("[ O K ][sock_server : Init] socket created\n");
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;

	//サーバ切った後TIME_WAITを発生させない
	int yes = 1;
	int isOpt = setsockopt(selfSock, SOL_SOCKET, SO_REUSEADDR, (const char *)&yes, sizeof(yes));

	if (isOpt == -1) {
		printf("[ERROR][Sock_server : Init] socket option failed\n");
		return false;
	}
	else {
		printf("[ O K ][Sock_server : Init] socket option success\n");
	}

	//ソケットの固定
	int isBind = bind(selfSock, (struct sockaddr *)&addr, sizeof(addr));

	if (isBind != 0) {
		printf("[ERROR][Sock_server : Init] bind failed\n");
		return false;
	}
	else {
		printf("[ O K ][Sock_server : Init] bind success\n");
	}

	//サーバを接続可能状態にする
	//第2引数は接続町のクライアント最大値、今回は5人
	int isListen = listen(selfSock, 0);

	if (isListen != 0) {
		printf("[ERROR][Sock_server : Init] listen failed\n");
		return false;
	}
	else {
		printf("[ O K ][Sock_server : Init] listen success\n");
	}

	//bool isWaitConnection = WaitConnection();

	sockaddr_in client;
	int length = sizeof(client);

	printf("\n[     ][Sock_server : WaitConnection]waiting Client ...\n");

	clientSock = accept(selfSock, (struct sockaddr *)&client, &length);

	if (clientSock < 0) {
		printf("[ERROR][Sock_server : WaitConnection] accept failed\n");

		return false;
	}
	else {
		printf("[ O K ][Sock_server : WaitConnection] accept success\n");
	}
	return true;
}


bool Sock_server::Send_msg(char *msg) {
	int isSend = send(clientSock, msg, MAX_MESSAGE, 0);
	if (isSend == SOCKET_ERROR) {
		printf("[ERROR][Sock_server : send_msg] send message failed\n");
		return false;
	}
	return true;
}

bool Sock_server::Recv_msg(char *msg) {
	int isRecv = recv(clientSock, msg, MAX_MESSAGE, 0);
	if (isRecv == SOCKET_ERROR) {
		printf("[ERROR][Sock_server : recv_msg] recieve message failed\n");
		return false;
	}

	return true;
}


