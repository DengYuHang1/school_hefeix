//*********************************************************
//File name :0804.c 
//Author   :��� 
//Date    :2024��5��10�� 
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
	
	printf("��д%d Сд%d",capital,lowercase); 
	return 0;
 } 
