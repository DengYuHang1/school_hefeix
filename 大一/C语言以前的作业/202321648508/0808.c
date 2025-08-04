//*********************************************************
//File name :0808.c 
//Author   :µËÓîº½ 
//Date    :2024Äê5ÔÂ10ÈÕ 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	char str[80],a,*p1,*p2;
	
	gets(str);
	a=getchar();
	
	for(p1=str;*p1!='\0';p1++)
	{
		if(*p1==a)
		{
			for(p2=p1;*p2!='\0';p2++)
			{
				*p2=*(p2+1);
			}
		}
	}
	
	puts(str);
	return 0;
}
