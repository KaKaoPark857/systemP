#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void){
	//int i;//1. double로 변수 설정 
	double i;
	double j;
//	char *bug = NULL;
	char *bug = malloc(sizeof(int));//sizeof(char *)

	for(i=0; i<5; i++){
//		printf("loop %d : ",i);//1. %lf로 변경
		printf("loop %d : ",(int)i);
		j = i/2 + i;//2.i앞에 double로 입력가능 or 2를 2.0으로 변경
		printf("\tj is %lf \n",j);
	}

	strcpy(bug,"hi");
	printf("bug is %s\n",bug);

	return 0;

}
