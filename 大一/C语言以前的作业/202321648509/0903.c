//*********************************************************
//File name :0903.c 
//Author   :µÀ”Ó∫Ω 
//Date    :2024ƒÍ5‘¬17»’ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int number(char*);

int main(void)
{
	char a[80];
	int b;
	gets(a);
	b=number(a);
	printf("%d",b);
	return 0;
}

int number(char*p)
{
	int i=0;
	while(*p)
	{
		if(*p>='0'&&*p<='9')
		{
			i++;
		}
		p++;
	}
	return i;
}
