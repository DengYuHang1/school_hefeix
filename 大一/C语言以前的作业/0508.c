//*********************************************************
//File name :0508.c 
//Author   :��� 
//Date    :2024��4��13�� 
//Student ID   :2023216485 
//*********************************************************
#include <stdio.h>

int main(void)
{
	int male,female,c;
	for(male=0;male<=9;male++)
	{
		for(female=0;female<=18;female++)
		{
			for(c=0;c<=72;c+=2)
			{
				if(4*male+2*female+c/2==36)
				{
					printf("����%d,Ů��%d��С��%d\n",male,female,c);
				}
			}
		}
	}
	return 0;
}
