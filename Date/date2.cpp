//根据输入的日期，计算是这一年的第几天。。
//测试用例有多组，注意循环输入

#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	int GetMonthDay(int year, int month)
	{
		int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2)
		{
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
				return 29;
		}
		return days[month];
	}

	int  GetDay()
	{
		int ret = 0;
		ret += _day;//将日先加起来
		_month--;//当前月的日子就是day
		while (_month)
		{
			ret += GetMonthDay(_year, _month);
			_month--;
		}
		return ret;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int ret2 = 0;

	int year, month, day;
	while (cin >> year >> month >> day)
	{
		cout << Date(year, month, day).GetDay() << endl;
	}

	return 0;
}