#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
	int status;
	pid_t pid;

	if((pid = fork()) < 0){
		perror("error from the fork()\n");			
	}
	else if (pid==0){
		printf("hi from child\n");
		
		sleep(100*1000);


		exit(8);
	}
	else{
		if (wait(&status) != pid)
			perror("wait error\n");
		printf("hi from parent\n");
		if (WIFEXITED(status))
			printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			printf("abnormal termination, signal number = %d\n", WTERMSIG(status));
	}
	exit(EXIT_SUCCESS);

	return 0;
}
