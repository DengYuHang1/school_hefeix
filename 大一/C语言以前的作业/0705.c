//*********************************************************
//File name :0705.c 
//Author   :µËÓîº½ 
//Date    :2024Äê4ÔÂ25ÈÕ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	char a[10][20],b[20];
	int number;
	
	for(number=0;number<10;number++)
	{
		scanf("%s",&a[number][0]);
	}

	scanf("%s",b);
	
	for(number=0;number<10;number++)
	{
		if(strcmp(&a[number][0],b)==0)
		{
			printf("%d",number+1);
		}
	}
	
	return 0; 
} 
