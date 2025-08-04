//*********************************************************
//File name :0401.c 
//Author   :邓宇航 
//Date    :2024年4月6日 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	float a,b,c,max,middle,min;
	
	scanf("%f%f%f",&a,&b,&c);
	 
	if(a>=b&&a>=c)
	{
		max=a;
	}
	else if(b>=a&&b>=c)
	{
		max=b;
	}
	else if(c>=a&&c>=b)
	{
		max=c;
	}
	
	if(a<=b&&a<=c)
	{
		min=a;
	}
	else if(b<=a&&b<=c)
	{
		min=b;
	}
	else if(c<=a&&c<=b)
	{
		min=c;
	}
	middle=a+b+c-min-max;
	
	if(min+middle>max)
	{
		if(max==middle||max==middle||middle==min)
		{
			if(max==middle&&middle==min)
			{
				printf("等边三角形");
			}
			else
			{
				printf("等腰三角形");
			} 
		}
		else if((min*min+middle*middle-max*max)<1e-5&&(min*min+middle*middle-max*max)>-1e-5)
		{
			printf("直角三角形");
		} 
		else
		{
			printf("一般三角形");
		} 
	}
	else
	{
		printf("不能组成三角形");
	 } 
		
	return 0;
 } 
