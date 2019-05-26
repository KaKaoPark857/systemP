#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

int counter = 0;

void sigalarm_handler(int signo){
	printf("alarm!!!!!!@!@!@!@!  %d!!\n",counter++);
	alarm(1);
	}


int main(void){
	int i = 0;
	signal(SIGALRM, sigalarm_handler);
	alarm(5); 

	while(i < 10){
		printf("%d\n",i);
		sleep(1);//알람이 울리기전에 프로그램이 종료됨
		i++;
	}
	alarm(5);

/*
	alarm(1);
	while(1){}
*/	
	return(0);

	
}




