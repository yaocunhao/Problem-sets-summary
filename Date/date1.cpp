//���һ�������ܼ���һ�����ڼ������������ʲô���ڡ�
//�����һ�б�ʾ��������m��������m��ÿ���ĸ������ֱ��ʾ�����պ��ۼӵ�������
//���m�У�ÿ�а�yyyy - mm - dd�ĸ��������


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

	int GetMonthDay(int year, int month)//��ȡĳ��ĳ�µ�����
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month != 2)
		{
			return days[month];
		}
		else
		{
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)//4��һ���Ұ��겻��400����
			{
				return 29;//����2����29��
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
			_day -= GetMonthDay(_year, _month);//����һ���µ�����
			_month++;//�·�+1��

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

