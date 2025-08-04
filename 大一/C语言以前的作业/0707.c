//*********************************************************
//File name :0707.c 
//Author   :µÀ”Ó∫Ω 
//Date    :2024ƒÍ4‘¬26»’ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	char a[40],b[40];
	int c,lena,lenb;
	
	gets(a);
	gets(b);
	for(lena=0;a[lena]!='\0';lena++)
	{
		;
	}
	for(lenb=0;b[lenb]!='\0';lenb++)
	{
		;
	}
	
	for(c=lena;c<lena+lenb;c++)
	{
		a[c]=b[c-lena];
	}
	a[c]='\0';
	puts(a);
	return 0;
}
