//*********************************************************
//File name :0806.c 
//Author   :µËÓîº½ 
//Date    :2024Äê5ÔÂ10ÈÕ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	char str1[80],str2[80],*p1,*p2;
	
	gets(str1);
	gets(str2);
	
	p1=str1;
	while(*p1)
	{
		p1++;
	}
	p2=str2;
	
	while(*p2)
	{
		*p1=*p2;
		p1++;
		p2++;
	}
	p1='\0';
	
	puts(str1);
	return 0;
}
