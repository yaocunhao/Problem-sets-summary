#include <iostream>
using namespace std;


void GetDay(int year, int day)
{
	int months[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };//到每个月有多少天

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)//是闰年,每月加1天
	{
		for (int i = 2; i<13; i++)
		{
			months[i] += 1;
		}
	}

	int month = 0;
	for (int i = 0; i<12; i++)
	{
		if (day>months[i] && day <= months[i + 1])//先确定月份
		{
			month = i + 1;
			break;
		}
	}

	int days = day - months[month - 1];//获得当前月份天数

	if (days<10 && month<10)
		cout << year << "-" << "0" << month << "-" << "0" << days << endl;

	else if (days<10 && month>9)
		cout << year << "-" << month << "-" << "0" << days << endl;

	else if (days>9 && month<10)
		cout << year << "-" << "0" << month << "-" << days << endl;
	else
		cout << year << "-" << month << "-" << days << endl;
}

int main()
{
	int year, day;

	while (cin >> year >> day)
	{
		GetDay(year, day);
	}

	return 0;
}