//*********************************************************
//File name :0910.c 
//Author   :µËÓîº½ 
//Date    :2024Äê5ÔÂ18ÈÕ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

void statis (char*,int*);

int main(void)
{
	char str[80];
	int a[26]={0},b;
	
	gets(str);
	statis(str,a);
	
	for(b=0;b<26;b++)
	{
		printf("%c=%d ",'a'+b,a[b]);
	}
	
	return 0;
}

void statis (char*str,int*a)
{
	int c;
	while(*str)
	{
		if(*str>='A'&&*str<='Z')
		{
			c=*str-65;
		}
		else if(*str>='a'&&*str<='z')
		{
			c=*str-97;
		}
		a[c]++;
		str++;
	}
}
