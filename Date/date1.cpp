//设计一个程序能计算一个日期加上若干天后是什么日期。
//输入第一行表示样例个数m，接下来m行每行四个整数分别表示年月日和累加的天数。
//输出m行，每行按yyyy - mm - dd的个数输出。


#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year = 2008, int month = 2, int day = 3)
		:_year(year)
		, _month(month)
		, _day(day)
	{}

	int GetMonthDay(int year, int month)//获取某年某月的天数
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month != 2)
		{
			return days[month];
		}
		else
		{
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)//4年一润且百年不润，400再润
			{
				return 29;//闰年2月有29日
			}
			return 28;
		}
	}

	void Print()
	{
		char *month[] = { "", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12" };
		char *day_t = nullptr;
		if (_day<10)
		{
			day_t = month[_day];
			cout << _year << "-" << month[_month] << "-" << day_t << endl;
		}
		else
			cout << _year << "-" << month[_month] << "-" << _day << endl;
	}

	Date & operator +=(int day)
	{
		_day += day;
		while (_day>GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);//减少一个月的天数
			_month++;//月份+1；

			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;
	}


private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int m = 0;
	int year = 0;
	int month = 0;
	int day = 0;
	int count = 0;

	cin >> m;
	while (m--)
	{
		cin >> year;
		cin >> month;
		cin >> day;
		cin >> count;
		Date d(year, month, day);
		d += count;
		d.Print();
	}

}

