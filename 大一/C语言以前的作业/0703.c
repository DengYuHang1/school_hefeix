//*********************************************************
//File name :0703.c 
//Author   :邓宇航 
//Date    :2024年4月25日 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[40];
	int b,c,flag;
	gets(a);
	b=strlen(a);
	flag=0;
	for(c=0;c<b/2-1;c++)
	{
		if(a[c]!=a[b-1-c])
		{
			flag=1;
		}
	}
	if(flag)
	{
		printf("不是回文"); 
	}
	else
	{
		printf("是回文！"); 
	 } 
	return 0; 
} 
