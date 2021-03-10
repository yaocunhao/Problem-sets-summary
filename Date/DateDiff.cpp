#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//���������ڣ�����������֮�������������������������������ǹ涨����֮�������Ϊ����

//˼·��������ɢ�����£���������ģ�������ý�С�����һ�������ȥ�����������Ͷ��1



int GetDay(int year, int month, int day)
{
	int ret = 0;
	int months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (month>1)
	{
		ret += months[month - 1];
		month--;
	}
	ret += day;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		ret++;
	return ret;
}

int YearDiff(int year1, int year2)
{
	int ret = 0;
	if (year1>year2)
	{
		int temp = year1;
		year1 = year2;
		year2 = temp;
	}
	while (year1 != year2)
	{
		ret += 365;
		if ((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 1400 == 0)
			ret++;
		year1++;

	}
	return ret;
}
int main()
{
	int year1, year2, month1, month2, day1, day2;
	while (scanf("%4d%02d%02d", &year1, &month1, &day1) != EOF)
	{
		scanf("%4d%02d%02d", &year2, &month2, &day2);
		int ret1 = GetDay(year1, month1, day1);//��ǰ�������
		int ret2 = GetDay(year2, month2, day2);

		int ret = abs(ret1 - ret2) + YearDiff(year1, year2) + 1;

		cout << ret << endl;
	}

	return 0;
}