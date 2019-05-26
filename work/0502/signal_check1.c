#include<stdio.h>
#include<signal.h>

int main(void){
	sigset_t set;
	
	sigemptyset(&set);//시그널 집합 변수의 내용을 모두 제거
	sigaddset(&set, SIGINT);//시그널 집합변수에 sigint를 추가
	sigaddset(&set, SIGSYS);//이 함수가 있으면 포함 없으면 없음으로 출력

	//sigint가 등록되었는지 확인
	switch(sigismember(&set, SIGINT)){
		case 1	: printf("SIGINT가 포함되어 있습니다\n");
				  break;
		case 0	: printf("SIGINT가 포함되어 있지않습니다\n");
				  break;
		default : printf("sigismember() 호출에 실패\n");
		}
	//sigint 삭제
	sigdelset(&set, SIGINT);

	//sigsys가 등록되어있는지 확인
	switch(sigismember(&set, SIGSYS)){
		case 1	: printf("SIGSYS가 포함\n");
				  break;
		case 0	: printf("SIGSYS가 없음\n");
				  break;
		default : printf("sigismember() 호출 실패\n");
		}
	return 0;
}


