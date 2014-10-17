#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#pragma warning (disable:4996)
void poweronlogger(void);
void loginpassword(int argc, char*argv[]);
void wrong(void);
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		poweronlogger();
	}
	else if ((strcmp(argv[1], "C8MG2")) == 0)
	{
		loginpassword(argc, argv);
	}
	else
	{
		wrong();
	}
}
void wrong(void)
{
	puts("wrong");
	getch();
	exit(0);
}
void poweronlogger(void)
{
	time_t rawtime;
	time(&rawtime);
	struct tm* nowtime = localtime(&rawtime);
	FILE*fp;
	fp = fopen("log", "a+");
	fprintf(fp, "%d-%d-%d %d:%d:%d\n", nowtime->tm_year + 1900, nowtime->tm_mon + 1, nowtime->tm_mday, nowtime->tm_hour, nowtime->tm_min, nowtime->tm_sec);
	fclose(fp);
	system("attrib log +s +h +a");
}
void loginpassword(int argc, char*argv[])
{
	int day;
	if (argc == 2)
	{
		time_t nowtime;
		time(&nowtime);
		struct tm * timeinfo = localtime(&nowtime);
		day = timeinfo->tm_wday;
		if (day == 0)
			day = 7;
	}
	else if (argc == 3)
	{
		if ((strcmp(argv[2], "1")) == 0)
		{
			time_t nowtime;
			time(&nowtime);
			struct tm * timeinfo = localtime(&nowtime);
			day = timeinfo->tm_wday;
			day++;
		}
		else
		{
			wrong();
		}
	}
	else if (argc == 4)
	{
		if ((strcmp(argv[2], "2")) == 0)
		{
			day = atoi(argv[3]);
			if (day<1 || day>7)
			{
				wrong();
			}
		}
		else
		{
			wrong();
		}
	}
	else
	{
		wrong();
	}
	char systemtion[100];
	sprintf(systemtion, "net.exe USER %%USERNAME%% key%d", day);
	system(systemtion);
}