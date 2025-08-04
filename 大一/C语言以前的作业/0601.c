//*********************************************************
//File name :0601.c 
//Author   :µÀ”Ó∫Ω 
//Date    :2024ƒÍ4‘¬15»’ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	long int a[10],c=0;
	int b,d=0;
	for(b=0;b<10;b++)
	{
		scanf("%ld",&a[b]);
	}
	for(b=0;b<10;b++)
	{
	
		if(c<a[b])
		{
			c=a[b];
			d=b+1;
		}
	}
	printf("%ld %d",c,d);
	return 0;
 } 
