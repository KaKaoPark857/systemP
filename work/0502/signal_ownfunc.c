#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void(*old_fun)(int);

void sigint_handler(int signo){
	printf("can't exit\n");
//	signal(SIGINT, old_fun); 
	signal(SIGINT, SIG_DFL);
}

int main(void){
	

	old_fun = signal(SIGINT, sigint_handler);
	
	while(1){
		printf("sig handler reg!\n");
		sleep(1);
	}
	return 0;

	
}




