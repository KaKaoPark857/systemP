#include <stdio.h>
#include <stdlib.h>
#include "cal5.h"


int main(){
	char sign;
	float a, b;
	float c;

	printf("Insert +, -, *, / : ");
	scanf("%s", &sign);

	printf("Insert the number1 : ");
	scanf("%f", &a);

	printf("Insert the number2 : ");
	scanf("%f", &b);

	switch(sign){
		case '+' :
			c = sum(a,b);
			 break;

		case '-' :
			c = sub(a,b);
			break;

		case '*' :
			c = mul(a,b);
			break;

		case '/' :
			if(a==0){
				printf("ERROR\n");
				break;
			}
			else
				c = nanum(a,b);
			break;
	}
	printf("%lf\n",c);
	return 0;
}
