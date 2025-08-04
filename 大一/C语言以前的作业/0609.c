//*********************************************************
//File name :0609.c 
//Author   :µÀ”Ó∫Ω 
//Date    :2024ƒÍ4‘¬17»’ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	int a[10],b,c,dmax,temp;
	
	for(b=0;b<10;b++)
	{
		scanf("%d",&a[b]);
	 } 
	 
	 for(b=0;b<9;b++)
	 {
	 	dmax=b;
	 	for(c=b+1;c<10;c++)
	 	{
	 		if(a[dmax]>a[c])
	 		{
	 			dmax=c;
			 }
		 }
		if(dmax!=b)
		{
			temp=a[b];
			a[b]=a[dmax];
			a[dmax]=temp;
		}
	 }
	 
	 for(b=0;b<10;b++)
	{
		printf("%d ",a[b]);
	 } 
	return 0;
}
