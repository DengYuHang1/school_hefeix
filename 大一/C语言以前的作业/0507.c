//*********************************************************
//File name :0507.c 
//Author   :µÀ”Ó∫Ω 
//Date    :2024ƒÍ4‘¬13»’ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	float a,x,b=1,cos=1;
	scanf("%f",&x);
	for(a=1;b>1e-6||b<-1e-6;a+=2)
	{
		b=-b/(a*(a+1))*x*x;
		cos+=b;
	}
	printf("cos(%.3f)=%.3f",x,cos);
	return 0;
}
