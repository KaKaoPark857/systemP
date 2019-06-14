#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define BUFF_SIZE 1024
typedef struct {
	long data_type;
	int data_num;
	char data_buff[BUFF_SIZE];
} msg_t;

//항상 메시지 큐의 생성부분(msgget()함수의 seed값)을 하드코딩으로 해야할까

int main(void) {
	int msqid;
	int ndx = 0;
	msg_t data;
	
	if(-1 == (msqid = msgget((key_t)21568, IPC_CREAT | 0666))) {//키값은 1234 
		perror("msgget() error");
		exit(1);
		}
	while(1) {
		data.data_type = (ndx++ % 3) + 1; 
		// data_type = {1, 2, 3} 데이터타입을 자동으로 123
		data.data_num = ndx;
		sprintf(data.data_buff, "type=%ld, ndx=%d", data.data_type, ndx);
		
		if(-1 == msgsnd(msqid, &data, sizeof(msg_t) - sizeof(long), 0)) {
			perror("msgsnd() error");
			exit(1);
		}
		sleep(1);
	}
return 0;
}
