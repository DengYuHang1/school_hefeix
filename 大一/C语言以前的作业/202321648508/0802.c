//*********************************************************
//File name :0802.c 
//Author   :µÀ”Ó∫Ω 
//Date    :2024ƒÍ5‘¬10»’ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	int a[10],*p,*max;
	
	for(p=a;p-a<10;p++)
	{
		scanf("%d",p);
	}
	
	max=a;
	for(p=a+1;p-a<10;p++)
	{
		if(*max<*p)
		{
			max=p;
		}
	}
	
	printf("%d %d",max-a,*max);
	return 0;
 } 
