//*********************************************************
//File name :0710.c 
//Author   :��� 
//Date    :2024��4��26�� 
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
	
	printf("����   ѧ��       ���� ��ѧ ���� Ӣ��\n");
	
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
			//�������� 
			strcpy(temp_char,&name[a][0]);
			strcpy(&name[a][0],&name[imax][0]);
			strcpy(&name[imax][0],&name[a][0]);
			//����ѧ��
			strcpy(temp_char,&id[a][0]);
			strcpy(&id[a][0],&id[imax][0]);
			strcpy(&id[imax][0],&id[a][0]);
			//�������Ƴɼ�
			for(row=0;row<4;row++)
			{
				temp_grade[row]=grade[a][row];
				grade[a][row]=grade[imax][row];
				grade[imax][row]=temp_grade[row];
			 } 
			//�����ܳɼ�
			temp=sum[a];
			sum[a]=sum[imax];
			sum[imax]=temp;
			//����ƽ���ɼ�
			temp_avg=avg[a];
			avg[a]=avg[imax];
			avg[imax]=temp_avg; 
		}
	 }
	 
	 printf("����   ѧ��     ���� ��ѧ ���� Ӣ�� �ܷ� ����\n");
	  
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
