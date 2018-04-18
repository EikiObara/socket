#pragma once

#ifndef _SOCK_CLIENT_H_
#define _SOCK_CLIENT_H_

#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

const int MAX_MESSAGE = 100;

class Sock_client {
public:
	Sock_client();
	~Sock_client();

	bool Init(int port, char *address);	//初期設定

	bool Send_msg(char *msg);	//メッセージ送信
	bool Recv_msg(char *msg);	//メッセージ受け取り

private:
	WSADATA wsaData;	//ウィンドウズで

	SOCKET sock;

	sockaddr_in server;

	//ポート
	//ソケット
	//欲しい位置情報の種類
};

#endif //_SOCK_CLIENT_H_