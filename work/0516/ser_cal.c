/* echo server; demonstrates unix sockets */
/* http://beej.us/guide/bgipc/examples/echos.c */
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
} msg;

int main(void) {
	int s, s2, len;

	unsigned t;

	struct sockaddr_un local, remote;//sockaddress에 필요한 주소를 작성
	struct _Msg;
	
	if ((s = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {//socket()파라미터
		perror("socket");
		exit(1);
	}

	local.sun_family = AF_UNIX;//서버쪽 sun_family

	strcpy(local.sun_path, SOCK_PATH);//sun_path : address
	
	unlink(local.sun_path);

	len = strlen(local.sun_path) + sizeof(local.sun_family);

	if (bind(s, (struct sockaddr *)&local, len) == -1) {//연결 bind
		perror("bind");
		exit(1);
	}
		if (listen(s, 5) == -1) {
			perror("listen");
			exit(1);
		}
		int count = 0;
	for(;;) {//무한루프
		int done, n;
		
		printf("%d time connected\n",count);
		count = count + 1;

		printf("Waiting for a connection...\n");
		t = sizeof(remote);

		if ((s2 = accept(s, (struct sockaddr *)&remote, &t)) == -1) {
			perror("accept\n");
			exit(1);
			}
		printf("Connected.\n");
		done = 0;

		do {
			n = recv(s2, &msg, 100, 0);//클라이언트로 받은 ip개수 
			if (n <= 0) {
				if (n < 0) perror("recv");
				done = 1;
				}
			if (!done)
				if (msg.operator == 1){
					msg.value[0] = msg.value[0] + msg.value[1];
				}
				else if(msg.operator == 2){
					msg.value[0] = msg.value[0] - msg.value[1];
				}
				else if(msg.operator ==3){
					msg.value[0] = msg.value[0] * msg.value[1];			
				}
				else{
					msg.value[0] = msg.value[0] / msg.value[1];			
					}
				} while (!done);
			msg.type=2;

			close(s2);
		}
		
	return 0;
}
