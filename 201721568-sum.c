#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	pid_t pid;
	pid_t pid2;
	int i;
	int a;
	int n = 1000;

	if(pid = fork() < 0){
		perror("error from the fork()\n");
	}
	else if(pid==0){
		for(i=1; i<=100; i++){
			a += i;
		}/*
		if(pid2 = fork() < 0){
			perror("error form the fork()2\n");
		}
		else if(pid2 == 0){
			for(i=101; i<=200; i++){
				a = i + a;
			}
		}*/
	}
	printf("%d\n",i);	
	exit(EXIT_SUCCESS);
}
