//*********************************************************
//File name :0805.c 
//Author   :��� 
//Date    :2024��5��10�� 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>
#include <string.h>


int main(void)
{
	char a[10][40],*p1,*p2,*min,temp[40];
	//��ΰ ��ΰ ���� ���� ��ΰ ���� � ���� ��ΰ �ž�
	
	for(p1=a[0];p1-a[0]<400;p1+=40)
	{
		gets(p1);
	} 
	
	printf("-----------------");
	for(p1=a[0];p1-a[0]<400;p1+=40)
	{
		min=p1;
		for(p2=p1+40;p2-a[0]<400;p2+=40)
		{
			if(strcoll(min,p2)>0)
			{
				min=p2;
			}
		}
		
		if(min!=p1)
		{
			strcpy(temp,min);
			strcpy(min,p1);
			strcpy(p1,temp);
		}
	} 
	
	for(p1=a[0];p1-a[0]<400;p1+=40)
	{
		puts(p1); 
	} 
	return 0;
 } 
