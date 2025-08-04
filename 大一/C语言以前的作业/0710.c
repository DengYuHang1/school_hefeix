//*********************************************************
//File name :0710.c 
//Author   :邓宇航 
//Date    :2024年4月26日 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>
#include <string.h>
int main(void)
{
	char name[5][40],id[5][15],temp_char[40];
	int grade[5][4],sum[5],temp_grade[4];
	int row,col;
	int a,b,imax,temp;
	float avg[5],temp_avg;
	
	printf("姓名   学号       语文 数学 物理 英语\n");
	
	for(row=0;row<5;row++)
	{
		scanf("%s",&name[row][0]);
		scanf("%s",&id[row][0]);
		for(col=0;col<4;col++)
		{
			scanf("%d",&grade[row][col]);
		}		
	 } 

	
	for(row=0;row<5;row++)
	{
		sum[row]=0;
		for(col=0;col<4;col++)
		{
			sum[row]+=grade[row][col];
		}
		avg[row]=sum[row]/5.f;
	 } 
	 
	 for(a=0;a<4;a++)
	 {
	 	imax=a;
	 	for(b=a+1;b<5;b++)
	 	{
	 		if(sum[b]>sum[imax])
	 		{
	 			imax=b;
			 }
		 }
		
		if(imax!=a)
		{
			//交换名字 
			strcpy(temp_char,&name[a][0]);
			strcpy(&name[a][0],&name[imax][0]);
			strcpy(&name[imax][0],&name[a][0]);
			//交换学号
			strcpy(temp_char,&id[a][0]);
			strcpy(&id[a][0],&id[imax][0]);
			strcpy(&id[imax][0],&id[a][0]);
			//交换各科成绩
			for(row=0;row<4;row++)
			{
				temp_grade[row]=grade[a][row];
				grade[a][row]=grade[imax][row];
				grade[imax][row]=temp_grade[row];
			 } 
			//交换总成绩
			temp=sum[a];
			sum[a]=sum[imax];
			sum[imax]=temp;
			//交换平均成绩
			temp_avg=avg[a];
			avg[a]=avg[imax];
			avg[imax]=temp_avg; 
		}
	 }
	 
	 printf("姓名   学号     语文 数学 物理 英语 总分 均分\n");
	  
	for(row=0;row<5;row++)
	{
		printf("%-5s",name[row]);
		printf("%5s  ",id[row]);
		for(col=0;col<4;col++)
		{
			printf("%-5d",grade[row][col]);
		}
		printf("%-5d",sum[row]);
		printf("%-5.3f",avg[row]);
		printf("\n");		
	 } 
	return 0;
}
