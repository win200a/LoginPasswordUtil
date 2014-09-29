#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#pragma warning (disable:4996)
int main(int argc)
{
	char instruction[100];
	int a;
	if (argc == 1)
	{
		time_t nowtime;
		time(&nowtime);
		struct tm * timeinfo = localtime(&nowtime);
		a = timeinfo->tm_wday;
		if (a == 0)
			a = 7;
	}
	else if (argc==2)
	{
		time_t nowtime;
		time(&nowtime);
		struct tm * timeinfo = localtime(&nowtime);
		a = timeinfo->tm_wday;
		a++;
	}
	else 
	{
		while (scanf("%d", &a) != 1 || (a<1 || a>7 ))
		{
			fflush(stdin);
			printf("Input a letter and the letter must be a number and the number must >=1 and <=7.\n");
		}
	}
	sprintf(instruction, "net.exe USER %%USERNAME%% key%d", a);
	system(instruction);
}
