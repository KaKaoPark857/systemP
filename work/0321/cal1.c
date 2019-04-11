#include <stdio.h>

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
			 c=a+b;
			 printf("%f\n",c);
			 break;

		case '-' :
			c=a-b;
			printf("%f\n",c);
			break;

		case '*' :
			c=a*b;
			printf("%f\n",c);
			break;

		case '/' :
			if(a==0){
				printf("ERROR\n");
				break;
			}
			else
				c=a/b;
				printf("%f\n",c);
			break;
	}

	return 0;
}
