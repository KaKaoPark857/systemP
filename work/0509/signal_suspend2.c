#include<stdio.h>
#include<unistd.h>
#include<signal.h>

struct sigaction act_new;

void sigint_handler(int signo){
	printf("recevie\n");

}



int main(void){
	sigset_t sigset;

	sigfillset(&sigset);
	sigdelset(&sigset, SIGUSR1);

	printf("PID : %d, waiting for only SIGUSR1\n", getpid());

	sigsuspend(&sigset);

	sigaction(SIGINT, &act_new, NULL);


	return 0;

}


