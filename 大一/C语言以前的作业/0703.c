//*********************************************************
//File name :0703.c 
//Author   :��� 
//Date    :2024��4��25�� 
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
		printf("���ǻ���"); 
	}
	else
	{
		printf("�ǻ��ģ�"); 
	 } 
	return 0; 
} 
