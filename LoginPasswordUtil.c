/*
Copyright (C) 2014 Frank_feng, Inc. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
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
		char systemtion[100];
		sprintf(systemtion, "net.exe USER %%USERNAME%% keys%d", weekday);
		system(systemtion);
	}
	else if ((argc == 2) && ((strcmp(argv[1], "?")) == 0))
	{
		puts("命令行参数解释:");
		puts("无参数:");
		puts("	改为今天登录密码");
		puts("	eg:LoginPasswordUtil.exe");
		puts("1:");
		puts("	改为明天登录密码");
		puts("	eg:LoginPasswordUtil.exe 1");
		puts("2:");
		puts("	后加星期即改为指定星期登录密码");
		puts("	eg:LoginPasswordUtil.exe 2 1");
		puts("3:");
		puts("	后加指定日期即改为指定日期登录密码");
		puts("	eg:LoginPasswordUtil.exe 3 2001 1 1");
		puts("9:");
		puts("	消除密码");
		puts("	eg:LoginPasswordUtil.exe 9");
		puts("?:");
		puts("	查看帮助");
		puts("	eg:LoginPasswordUtil.exe ?");
		getch();
	}
	else if ((argc == 2) && ((strcmp(argv[1], "9")) == 0))
	{
		system("net.exe USER %USERNAME% \"\"");
	}
	else if ((argc == 2) && ((strcmp(argv[1], "1")) == 0))
	{
		time_t nowtime;
		time(&nowtime);
		struct tm * timeinfo = localtime(&nowtime);
		weekday = timeinfo->tm_wday;
		weekday++;
		char systemtion[100];
		sprintf(systemtion, "net.exe USER %%USERNAME%% keys%d", weekday);
		system(systemtion);
	}
	else if ((argc == 3) && (((strcmp(argv[1], "2")) == 0)) && ((atoi(argv[2]) >= 1) && (atoi(argv[2]) <= 7)))
	{
		weekday = atoi(argv[2]);
		char systemtion[100];
		sprintf(systemtion, "net.exe USER %%USERNAME%% keys%d", weekday);
		system(systemtion);
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
		//  year / 100 * 100   即获取年份前两位
		if (weekday == 0)
		{
			weekday = 7;
		}
		char systemtion[100];
		sprintf(systemtion, "net.exe USER %%USERNAME%% keys%d", weekday);
		system(systemtion);
		switch (weekday)
		{
		case 1:
			puts("星期一");
			break;
		case 2:
			puts("星期二");
			break;
		case 3:
			puts("星期三");
			break;
		case 4:
			puts("星期四");
			break;
		case 5:
			puts("星期五");
			break;
		case 6:
			puts("星期六");
			break;
		case 7:
			puts("星期日");
			break;
		default:
			wrong();
		}
		getch();
	}
	else
	{
		wrong();
	}
}