//*********************************************************
//File name :0604.c 
//Author   :邓宇航 
//Date    :2024年4月15日 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	float a[10];
	int b,c[5]={0};
	
	for(b=0;b<10;b++)
	{
		scanf("%f",&a[b]);
	}
	
	for(b=0;b<10;b++)
	{
		if(a[b]<60)
		{
			c[0]++;
		}
		else if(a[b]<70)
		{
			c[1]++;
		}
		else if(a[b]<80)
		{
			c[2]++;
		}
		else if(a[b]<90)
		{
			c[3]++;
		}
		else if(a[b]<=100)
		{
			c[4]++;
		}
	}
	printf("不及格%d 及格%d 中%d 良%d 优%d",c[0],c[1],c[2],c[3],c[4]);
	return 0;
}
