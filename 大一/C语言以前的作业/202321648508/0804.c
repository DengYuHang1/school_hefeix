//*********************************************************
//File name :0804.c 
//Author   :邓宇航 
//Date    :2024年5月10日 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	char a[80],*p;
	int lowercase=0,capital=0;
	
	gets(a);
	
	for(p=a;*p!='\0';p++)
	{
		if(*p>='a'&&*p<='z')
		{
			lowercase++;
		}
		else if(*p>='A'&&*p<='Z')
		{
			capital++;
		}
	}
	
	printf("大写%d 小写%d",capital,lowercase); 
	return 0;
 } 
