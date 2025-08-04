//*********************************************************
//File name :0901.c 
//Author   :µÀ”Ó∫Ω 
//Date    :2024ƒÍ5‘¬17»’ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

void replace(int*,int*);

int main(void)
{
	int a,b;
	scanf("%d%d",&a,&b);
	replace(&a,&b);
	printf("%d %d",a,b);
	
	return 0;
 } 
 
void replace(int*p1,int*p2)
{
	int temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
}

