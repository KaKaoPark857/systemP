#include<stdio.h>
#include<signal.h>
#include<unistd.h>

struct sigaction act_new;
struct sigaction act_old;

void sigint_handler(int signo){
	printf("can't exit\n");
	printf("Are u push Ctrl-c?\n");
	sigaction(SIGINT, &act_old, NULL);
}

int main(void){

	act_new.sa_handler = sigint_handler;//시그널 핸들러 지정
	sigemptyset(&act_new.sa_mask);	//시그널 처리중 블록될 시그널은 없음

	//sigint를 지정하면서 act_old에 이전 정보를 구합니다.
	sigaction(SIGINT, &act_new, &act_old);
	
	while(1){
		printf("sig action!\n");
		sleep(1);
	}
	return 0;

	
}




