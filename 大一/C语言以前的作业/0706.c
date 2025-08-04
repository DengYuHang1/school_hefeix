//*********************************************************
//File name :0706.c 
//Author   :µÀ”Ó∫Ω 
//Date    :2024ƒÍ4‘¬25»’ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[40],b[40],d;
	int c;
	
	gets(a);
	scanf("%c",&d);
	scanf("%d",&c);
	
	strcpy(b,a+c);
	strcpy(a+c,&d);
	strcpy(a+c+1,b);
	
	puts(a);
	
	return 0;
}
