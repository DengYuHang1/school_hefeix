//*********************************************************
//File name :0801.c 
//Author   :µÀ”Ó∫Ω 
//Date    :2024ƒÍ5‘¬10»’ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	int a,b,temp;
	int *p1,*p2;
	
	p1=&a;
	p2=&b;
	
	scanf("%d%d",p1,p2);
	
	temp=*p1;
	*p1=*p2;
	*p2=temp;
	
	printf("%d %d",*p1,*p2);
	 
	return 0;
 } 
