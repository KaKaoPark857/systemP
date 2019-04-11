#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(void) {
	pid_t pid;

	printf("before fork (%d)\n", getpid());
	if(pid = fork() < 0){
		perror("error from the fork()\n");			
	}
	else if (pid==0){
		printf("hi from child! (%d -> %d)\n", getpid(), getppid());
	}
	else{
		printf("hi from parent! (%d)\n", getpid());
	}
	printf("bye (%d)\n", getpid());
		exit(EXIT_SUCCESS);
}
