//*********************************************************
//File name :0902.c 
//Author   :µÀ”Ó∫Ω 
//Date    :2024ƒÍ5‘¬17»’ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int divisor(int,int);
 
int main(void)
{
	int a,b,maxdiv;
	scanf("%d%d",&a,&b);
	maxdiv=divisor(a,b);
	printf("%d",maxdiv);
	return 0;
}

int divisor(int a,int b)
{
	int div,i;
	i=0;
	if(a%2==0&&b%2==0)
	{
		a/=2;
		b/=2;
		i++;
	}
	while(a!=b)
	{
		if(a>b)a-=b;
		else b-=a;
	}
	div=a;
	while(i)
	{
		div*=2;
		i--;
	}
	return div;
}
