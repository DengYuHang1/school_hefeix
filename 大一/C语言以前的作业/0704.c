//*********************************************************
//File name :0704.c 
//Author   :µËÓîº½ 
//Date    :2024Äê4ÔÂ25ÈÕ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[40],b;
	int c,d,e;
	
	gets(a);
	scanf("%c",&b);
	c=strlen(a);
	 
	e=0; 
	for(d=0;d<c;d++)
	{
		if(a[d]==b)
		{
			e++;
		 } 
	}
	
	printf("%d",e);

	return 0; 
} 
