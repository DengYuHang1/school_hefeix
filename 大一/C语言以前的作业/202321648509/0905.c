//*********************************************************
//File name :0905.c 
//Author   :µÀ”Ó∫Ω 
//Date    :2024ƒÍ5‘¬17»’ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>
#include <stdbool.h>

bool PRIME (int); 

int main(void)
{
	int a=100;
	while(a<=200)
	{
		if(PRIME(a))
		{
			printf("%d ",a);
		}
		a++;
	}
	return 0;
}

bool PRIME (int a)
{
	bool flag;
	int b;
	
	flag=1;
	for(b=2;b<a;b++)
	{
		if(a%b==0)
		{
			flag=0;
		}
	 } 
	return flag;
}
