//*********************************************************
//File name :0708.c 
//Author   :µÀ”Ó∫Ω 
//Date    :2024ƒÍ4‘¬26»’ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	int a[5][5]={
	{17,24,1,8,15},
	{23,5,7,14,16},
	{4,6,13,20,22},
	{10,12,19,21,3},
	{11,18,25,2,9}
	};
	int c,j;
	int sum[6]={0},flag;
	flag=0;
	
	for(j=0;j<5;j++)
	{
		sum[6]+=a[0][j];
	}
	
	for(c=1;c<5;c++)
	{
		for(j=0;j<5;j++)
		{
			sum[c]+=a[c][j];
		}
		
		if(sum[c]!=sum[6])
		{
			flag=1;
			printf("1");
			break;
		}
	}
	
	if(!flag)
	{
		for(j=0;j<5;j++)
		{
			sum[j]=0;
			for(c=0;c<5;c++)
			{
				sum[j]+=a[c][j];
			}
			if(sum[j]!=sum[6])
			{
				flag=1;
				printf("2");
				break;
			}
		}
	}
	
	if(!flag)
	{
			sum[0]=0;
			sum[1]=0;
			for(j=0;j<5;j++)
			{
				sum[0]+=a[j][j];
				sum[1]+=a[j][4-j];
			}
			if(sum[0]!=sum[6]||sum[1]!=sum[6])
			{
				flag=1;
				printf("3");
			}
	}
	
	if(flag)
	{
		printf("No!");
	}
	else 
	{
		printf("Yes!");
	}
	return 0;
}
