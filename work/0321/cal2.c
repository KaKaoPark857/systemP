#include <stdio.h>
#include <stdlib.h>

float sum(float a, float b){
	float c = 0;
	c = a+b;
	return c;
}

float sub(float a, float b){
	float c = 0;
	c = a-b;
	return c;
}

float mul(float a, float b){
	float c = 0;
	c = a*b;
	return c;
}

float nanum(float a, float b){
	float c = 0;
	c = a/b;
	return c;
}

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
	printf("%f\n",c);
	return 0;
}
