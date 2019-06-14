#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define KEY_NUM 9512
#define MEM_SIZE 1024

int main(void) {
	int shm_id;
	void *shm_addr;
	int count = 0;

	if(-1 == (shm_id = shmget((key_t)KEY_NUM, MEM_SIZE, IPC_CREAT | 0666))) {
		perror("shmget() error");
		return -1;
		}
	
	if((void *)-1 == (shm_addr = shmat(shm_id, (void *)0, 0))) {
		perror("shmat() error");
		return -1;
		}
	while(1) {
		char *msg = malloc(sizeof(char) * 10);
		scanf("%s", msg);

// write in the shared memory
		sprintf((char *)shm_addr, "%s", msg);
		//shm 주소에 포인터로 형변환후 카운트 ++
		sleep(1);
	}
return 0;
}
