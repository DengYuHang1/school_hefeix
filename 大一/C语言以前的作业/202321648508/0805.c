//*********************************************************
//File name :0805.c 
//Author   :邓宇航 
//Date    :2024年5月10日 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>
#include <string.h>


int main(void)
{
	char a[10][40],*p1,*p2,*min,temp[40];
	//张伟 王伟 李娜 王芳 李伟 王静 李静 张敏 刘伟 张静
	
	for(p1=a[0];p1-a[0]<400;p1+=40)
	{
		gets(p1);
	} 
	
	printf("-----------------");
	for(p1=a[0];p1-a[0]<400;p1+=40)
	{
		min=p1;
		for(p2=p1+40;p2-a[0]<400;p2+=40)
		{
			if(strcoll(min,p2)>0)
			{
				min=p2;
			}
		}
		
		if(min!=p1)
		{
			strcpy(temp,min);
			strcpy(min,p1);
			strcpy(p1,temp);
		}
	} 
	
	for(p1=a[0];p1-a[0]<400;p1+=40)
	{
		puts(p1); 
	} 
	return 0;
 } 
