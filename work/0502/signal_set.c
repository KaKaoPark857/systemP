#include<stdio.h>
#include<signal.h>

int main(void){
	sigset_t set;
	
	sigfillset(&set, SIGINT);
	
	//sigint가 등록되었는지 확인
	switch(sigismember(&set, SIGINT)){
		case 1	: printf("SIGINT가 포함되어 있습니다\n");
				  break;
		case 0	: printf("SIGINT가 포함되어 있지않습니다\n");
				  break;
		default : printf("sigismember() 호출에 실패\n");
		}

	return 0;
}




