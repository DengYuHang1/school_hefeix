//*********************************************************
//File name :0908.c 
//Author   :µËÓîº½ 
//Date    :2024Äê5ÔÂ18ÈÕ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int symmetry (int n,int Matrix[n][n]);
 
int main(void)
{
	int a[4][4]={
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,16},
	};
	int i,j;
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
	
	if(symmetry(4,a))
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	return 0;
}

int symmetry (int n,int Matrix[n][n])
{
	int i,j,flag;
	flag=1;
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(Matrix[i][j]!=Matrix[j][i])
			{
				flag=0;
				break;
			}
		}
		if(flag)break;
	}
	
	return flag;
}
