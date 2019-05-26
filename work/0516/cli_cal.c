/* echo client; demonstrates unix sockets */
/* http://beej.us/guide/bgipc/examples/echoc.c */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCK_PATH "echo_socket"

typedef struct _Msg{
	int type;
	int operator;
	double value[2];

} Msg;

int main(void) {
	int s, t, len;

	struct sockaddr_un remote;
	struct _Msg;

	if ((s = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
		}
	printf("Trying to connect...\n");

	remote.sun_family = AF_UNIX;

	strcpy(remote.sun_path, SOCK_PATH);

	len = strlen(remote.sun_path) + sizeof(remote.sun_family);

	if (connect(s, (struct sockaddr *)&remote, len) == -1) {
		perror("connect");
		exit(1);
		}
	printf("Connected.\n");
	
	Msg.type = 1;
	Msg.operator = 2;
	Msg.value[0] = 5;
	Msg.value[1] = 100;
	
	while(printf("> "), fgets(&Msg, 100, stdin), !feof(stdin)) {
		if (send(s, &Msg, sizeof(Msg), 0) == -1) {
			perror("send");
			exit(1);
			}
		if ((t=recv(s, &Msg, 100, 0)) > 0) {
			printf("%f", Msg.value[0]);
			
		}
		else {
			if (t < 0) perror("recv");
			else printf("Server closed connection\n");
			exit(1);
			}
		

	}
	close(s);
	return 0;
}
