//*********************************************************
//File name :0709.c 
//Author   :��� 
//Date    :2024��4��26�� 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	float a[2][3],b[2][3],c[2][3];
	int i,j;
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%f",&a[i][j]);
		}
	}
	printf("------------\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%f",&b[i][j]);
		}
	}
	printf("------------\n");
	printf("��:\n"); 
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%.3f ",a[i][j]+b[i][j]);
		}
		printf("\n");
	}
	printf("------------\n");
	printf("��:\n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%.3f ",a[i][j]-b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
