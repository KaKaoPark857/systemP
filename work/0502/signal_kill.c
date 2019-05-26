#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	
	if(argc<2){
		printf("사용법 : ./signal_kill [PID]\n");
	}
	else{
			kill(atoi(argv[1]), SIGKILL);
	}

	return(0);

	
}




