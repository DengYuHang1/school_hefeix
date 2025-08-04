//*********************************************************
//File name :0803.c 
//Author   :µÀ”Ó∫Ω 
//Date    :2024ƒÍ5‘¬10»’ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	float a[10],*p,*p1,*min,temp;
	
	for(p=a;p-a<10;p++)
	{
		scanf("%f",p);
	 } 
	 
	 for(p=a;p-a<10;p++)
	 {
	 	min=p;
	 	for(p1=p+1;p1-a<10;p1++)
	 	{
	 		if(*min>*p1)
	 		{
	 			min=p1;
			 }
		 }
		
		if(min!=p)
		{
			temp=*p;
			*p=*min;
			*min=temp;
		}
	 }
	 
	 for(p=a;p-a<10;p++)
	{
		printf("%.3f ",*p);
	 } 
	return 0;
 } 
