//*********************************************************
//File name :0610.c 
//Author   :µËÓîº½ 
//Date    :2024Äê4ÔÂ18ÈÕ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[80],str2[80];
	int a;
	
	gets(str1);
	gets(str2);
	
	strcat(str1,str2);
	
	strupr(str1);
	puts(str1);	
	return 0;
}
