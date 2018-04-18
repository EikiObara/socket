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

	bool Init(int port, char *address);	//�����ݒ�

	bool Send_msg(char *msg);	//���b�Z�[�W���M
	bool Recv_msg(char *msg);	//���b�Z�[�W�󂯎��

private:
	WSADATA wsaData;	//�E�B���h�E�Y��

	SOCKET sock;

	sockaddr_in server;

	//�|�[�g
	//�\�P�b�g
	//�~�����ʒu���̎��
};

#endif //_SOCK_CLIENT_H_