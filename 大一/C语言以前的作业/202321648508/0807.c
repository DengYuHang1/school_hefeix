//*********************************************************
//File name :0807.c 
//Author   :µËÓîº½ 
//Date    :2024Äê5ÔÂ10ÈÕ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	char str[80],*first,*last,temp;
	
	gets(str);
	
	first=str;
	last=str;
	while(*last)
	{
		last++;
	}
	last--;
	
	while(first<last)
	{
		temp=*first;
		*first=*last;
		*last=temp;
		first++;
		last--; 
	}
	
	puts(str);
	return 0;
}
