//*********************************************************
//File name :0510.c 
//Author   :µÀ”Ó∫Ω 
//Date    :2024ƒÍ4‘¬13»’ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	int a,b,c=5;
	for(a=1;a<=9;a++)
	{
		if(a<=5)
		{
			for(b=0;b<=5-a;b++)
			{
				printf(" ");
			}
			for(;b<5+a;b++)
			{
				printf("*");
			}	
		}
		else
		{
			for(b=0;b<=a-5;b++)
			{
				printf(" ");
			}
			for(;b<=14-a;b++)
			{
				printf("*");
			}	
		}
		printf("\n");
	}
	return 0; 
}
