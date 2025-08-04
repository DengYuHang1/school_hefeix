//*********************************************************
//File name :0906.c 
//Author   :µËÓîº½ 
//Date    :2024Äê5ÔÂ18ÈÕ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>
#include <math.h>

int conversion(char*);

int main(void)
{
	char str[80];
	int a;
	
	gets(str);
	a=conversion(str);
	
	printf("%d",a); 
	return 0;
}

int conversion(char*p)
{
	int len=0,i,number=0;
	
	while(p[len])
	{
		len++;
	}
	len--;
	i=0;
	while(p[i])
	{
		number+=(p[i]-'0')*pow(8,len-i);
		i++;
	}
	
	return number;
}
