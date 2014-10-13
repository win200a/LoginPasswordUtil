#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#pragma warning (disable:4996)
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		puts("wrong");
		getch();
		exit(0);
	}
	if ((strcmp(argv[1], "C8MG2")) == 0)
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
				puts("wrong");
				getch();
				exit(0);
			}
		}
		else if (argc == 4)
		{
			if ((strcmp(argv[2], "2")) == 0)
			{
				day = atoi(argv[3]);
				if (day<1 || day>7)
				{
					puts("wrong");
					getch();
					exit(0);
				}
			}
			else
			{
				puts("wrong");
				getch();
				exit(0);
			}
		}
		else
		{
			puts("wrong");
			getch();
			exit(0);
		}
		char systemtion[100];
		sprintf(systemtion, "net.exe USER %%USERNAME%% key%d", day);
		system(systemtion);
	}
	else
	{
		puts("wrong");
		getch();
		exit(0);
	}
}