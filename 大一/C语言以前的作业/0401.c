//*********************************************************
//File name :0401.c 
//Author   :��� 
//Date    :2024��4��6�� 
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
				printf("�ȱ�������");
			}
			else
			{
				printf("����������");
			} 
		}
		else if((min*min+middle*middle-max*max)<1e-5&&(min*min+middle*middle-max*max)>-1e-5)
		{
			printf("ֱ��������");
		} 
		else
		{
			printf("һ��������");
		} 
	}
	else
	{
		printf("�������������");
	 } 
		
	return 0;
 } 
