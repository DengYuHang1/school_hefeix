//*********************************************************
//File name :0505.c 
//Author   :��� 
//Date    :2024��4��13�� 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	unsigned int a,b=0;

	scanf("%u",&a);
	while(a>0)
	{
		b=b*10+a%10;
		a/=10;	
	}
	printf("%u",b);
	return 0;
}

