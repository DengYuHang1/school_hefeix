//*********************************************************
//File name :0909.c 
//Author   :µÀ”Ó∫Ω 
//Date    :2024ƒÍ5‘¬18»’ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>
#define PI 3.1415926

float SIN (float);
float COS (float); 
int main(void)
{
	float sinx,cosx;
	sinx=SIN(30.);
	cosx=COS(60.);
	printf("%.3f",sinx+cosx);
	return 0;
}

float SIN (float ox)
{
	float sinx=0,x,i,a;
	
	x=ox/180.*PI;
	a=2;
	i=x;
	
	while(i<-1e-6||i>1e-6)
	{
		sinx+=i;
		i=-i/(a*(a+1))*x*x;
		a+=2;
	}
	
	return sinx;
}

float COS (float ox)
{
	float cosx=0,x,i,a;
	
	x=ox/180.*PI;
	a=1;
	i=1;
	
	while(i<-1e-6||i>1e-6)
	{
		cosx+=i;
		i=-i/(a*(a+1))*x*x;
		a+=2;
	}
	
	return cosx;
}

