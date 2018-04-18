#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

#include "sock_client.h"

int main(void) {
	char *buf1 = {" "};

	Sock_client client;

	client.Init(55555, "127.0.0.1");

	while (1) {
		char buf[MAX_MESSAGE];


		scanf("%[^\n]", buf);
		getchar();

		bool isSucceeded = client.Send_msg(buf);

		if (isSucceeded == false) {
			printf("send_msg failed\n");

			while (getchar() != '\n') { printf("push enter"); }

			break;
		}
		if (strcmp(buf, "end") == 0) {
			break;
		}
	}


	printf("communication finished\n");

	return 0;
}
