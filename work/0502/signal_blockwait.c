#include<stdio.h>
#include<signal.h>
#include<unistd.h>


void sigint_handler(int signo){
	int ndx;

	printf("Ctrl - c버튼 누르셨나요?\n");
	printf("10초간 대기하겠습니다. Ctrl-z을 눌러주세요\n");
	for(ndx = 10; 0 < ndx; ndx--){
		printf("%d초남았습니다.\n",ndx);
		sleep(1);
	}
}

int main(void){
	
	struct sigaction act;

	act.sa_handler = sigint_handler;//시그널 핸들러 지정
	sigfillset(&act.sa_mask);	//모든 시그널 블록
	
	sigaction(SIGINT, &act, NULL);

	while(1){
		printf("sig action!\n");
		sleep(1);
	}
	return 0;

	
}




