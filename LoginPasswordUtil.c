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
	int weekday;
	if (argc == 1)
	{
		time_t nowtime;
		time(&nowtime);
		struct tm * timeinfo = localtime(&nowtime);
		weekday = timeinfo->tm_wday;
		if (weekday == 0)
		{
			weekday = 7;
		}
	}
	else if ((argc == 2) && ((strcmp(argv[1], "1")) == 0))
	{
		time_t nowtime;
		time(&nowtime);
		struct tm * timeinfo = localtime(&nowtime);
		weekday = timeinfo->tm_wday;
		weekday++;
	}
	else if ((argc == 3) && (((strcmp(argv[1], "2")) == 0)) && ((atoi(argv[2]) >= 1) && (atoi(argv[2]) <= 7)))
	{
		weekday = atoi(argv[2]);
	}
	else if ((argc == 5) && ((strcmp(argv[1], "3")) == 0))
	{
		int year = atoi(argv[2]);
		int month = atoi(argv[3]);
		int day = atoi(argv[4]);
		if (((month<1) || (month>12)) || ((day<1) || (day>31)) || (((month == 4) || (month == 6) || (month == 9) || (month == 11)) && (day > 30)))
		{
			wrong();
		}
		if (((year % 4 == 0) && (year % 100 != 0)) || ((year % 400 == 0)))
		{
			if ((month == 2) && (day > 29))
			{
				wrong();
			}
		}
		else
		{
			if ((month == 2) && (day > 28))
			{
				wrong();
			}
		}
		if (month == 1 || month == 2)
		{
			month += 12;
			year--;
		}

		weekday = (year / 400 - year / 50 + year - year / 100 * 100 + (year - year / 100 * 100) / 4 + (13 * (month + 1) / 5) + day - 1) % 7;

	}
	else
	{
		wrong();
	}
	char systemtion[100];
	sprintf(systemtion, "net.exe USER %%USERNAME%% keys%d", weekday);
	system(systemtion);
}