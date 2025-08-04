//*********************************************************
//File name :0907.c 
//Author   :µËÓîº½ 
//Date    :2024Äê5ÔÂ18ÈÕ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

void Transpose(int n,int a[n][n]);

int main(void)
{
	int a[4][4]={
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,16},
	};
	int i,j;
	
	Transpose(4,a);
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

void Transpose(int n,int a[n][n])
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			temp=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=temp;
		}
	}
}
