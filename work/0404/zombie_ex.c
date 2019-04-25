#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
	pid_t pid;
	int i;
	
	for(i = 0; i<5; i++){
		if ((pid = fork())<0) {
			perror("fork error");
		}
		else if (pid == 0) {
			printf("bye from child %d: %d\n", i, getpid());
			exit(EXIT_SUCCESS);
		}
		}
	sleep(60);
	printf("bye from parent\n");
	
	exit(EXIT_SUCCESS);

	return 0;
}
