#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#pragma warning (disable:4996)
void loginpassword(int argc, char*argv[]);
void wrong(void);
void multiply(void);
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		multiply();
	}
	else if ((strcmp(argv[1], "LPU")) == 0)
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
void loginpassword(int argc, char*argv[])
{
	if ((strcmp(argv[2], "C8MG2")) == 0)
	{
		int day;
		if (argc == 3)
		{
			time_t nowtime;
			time(&nowtime);
			struct tm * timeinfo = localtime(&nowtime);
			day = timeinfo->tm_wday;
			if (day == 0)
				day = 7;
		}
		else if (argc == 4)
		{
			if ((strcmp(argv[3], "1")) == 0)
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
		else if (argc == 5)
		{
			if ((strcmp(argv[3], "2")) == 0)
			{
				day = atoi(argv[4]);
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
}
void multiply(void)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	srand((unsigned)time(NULL));
	while (1)
	{
		a = rand() % 90 + 11;
		b = rand() % 90 + 11;
		d = a * b;
		printf("%d¡Á%d=", a, b);
		scanf("%d", &c);
		(c == d) ? puts("Correct!") : puts("Wrong!");
		getch();
		fflush(stdin);
	}
}