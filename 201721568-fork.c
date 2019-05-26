#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

char buf [] = "201721568, Parksangwon";

int main(){
	pid_t pid;
	
	if(write(STDOUT_FILENO, buf, strlen(buf)) != strlen(buf))
		printf("error");

	if(pid = fork() < 0){
		perror("error\n");
	}
	else if (pid == 0){
		printf("%s\n",buf);		
	}
	else
			
	
	exit(EXIT_SUCCESS);
}

