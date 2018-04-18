#include <cstdio>
#include "sock_server.h"

int main(void) {
	printf("started server program\n");

	Sock_server server;

	server.Init(55555);

	while (1) {
		char buf[MAX_MESSAGE];

		bool isSucceeded;

		isSucceeded = server.Recv_msg(buf);

		printf("%s\n", buf);

		if (strcmp(buf, "end") == 0) {
			break;
		}
	}

	printf("finished server program\n");

	return 0;
}