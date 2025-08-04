//*********************************************************
//File name :0505.c 
//Author   :µËÓîº½ 
//Date    :2024Äê4ÔÂ13ÈÕ 
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

