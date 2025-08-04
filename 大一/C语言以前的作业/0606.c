//*********************************************************
//File name :0606.c 
//Author   :µËÓîº½ 
//Date    :2024Äê4ÔÂ15ÈÕ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	float a[10],temp;
	int b;
	
	for(b=0;b<10;b++)
	{
		scanf("%f",&a[b]);
	}
	
	for(b=0;b<=5;b++)
	{
		temp=a[b];
		a[b]=a[9-b];
		a[9-b]=temp;
	}
	
	for(b=0;b<10;b++)
	{
		printf("%.3f ",a[b]);
	}
	return 0;
}
