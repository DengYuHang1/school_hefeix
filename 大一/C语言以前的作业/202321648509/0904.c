//*********************************************************
//File name :0904.c 
//Author   :µÀ”Ó∫Ω 
//Date    :2024ƒÍ5‘¬17»’ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

void descend(int*,int);

int main(void)
{
	int a[10],i;
	
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	
	descend(a,10);
	
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	
	return 0;
}

void descend(int*p,int a)
{
	int b,c,max,temp;
	
	for(b=0;b<9;b++)
	{
		max=b;
		for(c=b+1;c<10;c++)
		{
			if(p[max]>p[c])
			{
				max=c;
			}
		}
		if(max!=b)
		{
			temp=p[max];
			p[max]=p[b];
			p[b]=temp;
		}
	}
	
}
