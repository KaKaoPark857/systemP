#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int glob = 42;

int main(void) {
	int var;
	pid_t pid;
	var = 88;

	if(pid = fork() < 0){
		perror("error from the fork()\n");			
	}
	else if (pid==0){
		printf("Child pid : %d\n", getpid());
		glob++;
		var++;
	}
	else{
		printf("Parent pid : %d\n", getpid());
		sleep(1);
	}
	printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
		exit(EXIT_SUCCESS);
}
