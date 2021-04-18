#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string.h>

//typedef struct Goods
//{
//	int _price;//价格
//	int _sales;//销量
//
//	//如果重载>或<，那么只能进行价格或者销量的比较
//}Goods;
//
//
//struct LessPrice
//{
//	bool operator()(const Goods& x, const Goods &y)
//	{
//		return x._price >y._price;
//	}
//};

////N是非类型模板参数
//template<class T,size_t N = 100>
//class Array
//{
//private:
//	T_arr[N];
//};


template<class T1, class T2>//正常模板
class Date
{
public:

	Date()
	{
		cout << "template<class T1, class T2>" << endl;
	}
private:
	T1 _year;
	T2 _month;
};

template<>//类模板全特化
class Date<float,float>
{
public:

	Date()
	{
		cout << "class Date<float,float>" << endl;
	}
private:
	float _year;
	float _month;
};

template<class T1>//类模板偏特化
class Date<T1, float>
{
public:

	Date()
	{
		cout << "class Date<T1, float>" << endl;
	}
private:
	T1 _year;
	float _month;
};

template<class T1,class T2>//更进一步限制
class Date<T1*, T2*>
{
public:

	Date()
	{
		cout << "class Date<T1*, T2*>" << endl;
	}
private:
	T1 _year;
	T2 _month;
};

template<class T1, class T2>
class Date<T1&, T2&>
{
public:
	Date()
	{
		cout << "class Date<T1&, T2&>" << endl;
	}
private:
	T1 _year;
	T2 _month;
};




template<class T>
bool Compare(const T &dst,  const T &scr)//引用的是一个字符数组
{
	cout << "template<class T>" << endl;
	return dst == scr;
}

//函数模板的特化 (针对某些特殊类型的特殊化处理)
//严谨的函数模板化
template<>
bool  Compare < const char* const>(const char* const  &dst, const char* const   &scr)
//优先推导上面？
{
	cout << "Compare <const char* const >" << endl;
	return strcmp(dst, scr) == 0;
}


int main()
{
	char arr1[] = "hello";
	char arr2[] = "hello";
	cout<<Compare(arr1, arr2) << endl;



	//Date<int, float> d1;
	//Date <float,float> d2;
	//Date <double, float> d3;
	//Date <double*, float*> d4;
	//Date <int &, int &>d5;



	//Array<int, 1000> arr1;
	//Array<int, 500> arr2;

	////int n = 100;
	////Array<int, n>;
	//
	////不行因为C/C++大部分需要编译时就开好空间，运行时开空间的为(malloc/new)
	////如果这个n变成 cin>>n； 这样是无法提前确定大小的


	system("pause");
	return 0;
}