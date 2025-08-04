//*********************************************************
//File name :0702.c 
//Author   :邓宇航 
//Date    :2024年4月24日 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	int a[10],b,i,c,min,temp;
	int middle,flag;
	
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(c=0;c<9;c++)
	{
		min=c;
		for(i=c+1;i<10;i++)
		{
			if(a[i]<a[min])
			{
				min=i;
			}
		}
		if(min!=c)
		{
			temp=a[c];
			a[c]=a[min];
			a[min]=temp;
		}
	}
	
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	
	scanf("%d",&b);
	
	i=0;
	c=9;
	flag=0;
	while(i<=c&&flag==0)
	{
		middle=(i+c)/2;
		if(b==a[middle])
		{
			printf("%d",middle+1);
			flag=1;
		}
		else if(b>a[middle])
		{
			i=middle+1;
		}
		else
		{
			c=middle-1; 
		} 
	}
	
	if(!flag)
	{
		printf("不存在"); 
	}
	return 0; 
} 
