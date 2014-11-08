#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#pragma warning (disable:4996)
void loginpassword(int argc, char*argv[]);
void wrong(void);
int main(int argc, char *argv[])
{
	loginpassword(argc, argv);
}
void wrong(void)
{
	puts("wrong");
	getch();
	exit(0);
}
void loginpassword(int argc, char*argv[])
{
	int day;
	if (argc == 1)
	{
		time_t nowtime;
		time(&nowtime);
		struct tm * timeinfo = localtime(&nowtime);
		day = timeinfo->tm_wday;
		if (day == 0)
		{
			day = 7;
		}
	}
	else if ((argc == 2) && ((strcmp(argv[1], "1")) == 0))
	{
		time_t nowtime;
		time(&nowtime);
		struct tm * timeinfo = localtime(&nowtime);
		day = timeinfo->tm_wday;
		day++;
	}
	else if ((argc == 3) && (((strcmp(argv[1], "2")) == 0)) && ((atoi(argv[2]) >= 1) && (atoi(argv[2]) <= 7)))
	{
		day = atoi(argv[2]);
	}
	else
	{
		wrong();
	}
	char systemtion[100];
	sprintf(systemtion, "net.exe USER %%USERNAME%% keys%d", day);
	system(systemtion);
}