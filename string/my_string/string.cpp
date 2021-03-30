#include "string.h"


ms::string::string(const char* str = "")//构造函数
{
	_size = strlen(str);//size是有效字符个数

		_capacity = _size;//空间容量不包括\0
		if (_capacity == 0)
			_capacity = 15;//如果一开始为0，后续扩容2*_capacity就会出问题
	
	_str = new char[_capacity+1];//开辟空间,要加上\0

	strcpy(_str, str);//拷贝内容

}
ms::string::string(const string& s)
:_str(nullptr)//不能释放随机值
, _size(0)
, _capacity(0)
{
	string temp(s._str);//构造一个对象
	swap(temp);//this->swap
}

//(传统写法)ms::string::string(const string& s)//需要深拷贝，浅拷贝析构的时候会发生问题
//{
//	_size = s._size;
//
//	_capacity = _size;
//
//	_str = new char[_capacity+1];
//
//	strcpy(_str, s._str);
//}
ms::string& ms::string::operator=( string s)//传参就是拷贝构造
{
	swap(s);//直接交换
	return *this;
}
//ms::string& ms::string::operator=(const string &s)//传统写法
//{
//	if (this != &s)//不是自己赋值自己
//	{
//		char *temp = new char[strlen(s._str) + 1];//不确定空间大小，直接开辟一个
//		
//		delete[]_str;
//		
//		_str = temp;
//
//		strcpy(_str, s._str);
//
//		_size = s._size;
//		_capacity = _size;
//	}
//	return *this;//引用返回对象，如果简单返回会发生深拷贝
//
//}

ms::string::~string()
{
	delete[]_str;
}


//////////////////////////////////////////////////////////////

// iterator

ms::string::iterator ms::string::begin()
{
	return _str;//字符串第一个元素的地址
}

ms::string::iterator ms::string::end()
{
	return (_str + _size);//'\0'的地址
}



/////////////////////////////////////////////////////////////

// modify


ms::string ms::string::operator+(const char* str)
{
	string temp(*this);//先拷贝构造一份
	
	temp.Append(str);//再插入

	return temp;//返回的时候也要拷贝构造一份
}


void ms::string::PushBack(char c)//尾插
{
	//if (_size == _capacity)
	//{
	//	reserve(2 * _capacity);//开两倍空间
	//}

	//_str[_size] = c;
	//_str[_size+1] ='\0';

	//_size++;

	insert(_size, c);//调用insert在尾部插入字符
}

ms::string& ms::string::operator+=(char c)//+=字符，其实就是尾插
{
	PushBack(c);
	return *this;
}

void ms::string::Append(const char* str)
{
	//if (_size + strlen(str) > _capacity)//空间判定
	//{
	//	reserve(_size + strlen(str));//要给字符串终止符留位置
	//}

	//strcpy(_str + _size , str);//_str+_size到达'\0'位置，然后进行拷贝

	//_size += strlen(str);//有效元素个数更新

	insert(_size, str);//在尾部插入字符串
}

ms::string& ms::string::operator+=(const char* str)//+=字符串
{
	//Append(str);//加字符串就是在尾端插入字符串

	insert(_size, str);

	return *this;
}

void ms::string::clear()
{
	_size = 0;//有效字符清空
	_str[_size] = '\0';
}

void ms::string::swap(string& s)//s.swap比swap少了3次深拷贝
{
	std::swap(_str, s._str);
	std::swap(_size, s._size);
	std::swap(_capacity, s._capacity);
}

const char* ms::string::c_str()const
{
	return _str;
}

/////////////////////////////////////////////////////////////

// capacity


size_t ms::string::size()const
{
	return _size;
}

size_t ms::string::capacity()const
{
	return _capacity;
}

bool ms::string::empty()const
{
	if (_size == 0)
		return true;
	return false;
}

void ms::string::resize(size_t newSize, char c = '\0')//有效字符个数变为newSize
{
	if (newSize<_size)//减少有效元素个数
	{
		_str[newSize] = '\0';
		_size = newSize;
	}
	else//增加有效元素个数
	{
		if (newSize>_capacity)//需要扩容
		{
			reserve(newSize);
		}

		for (size_t i = _size; i < newSize; i++)
		{
			_str[i] = 'c';
		}
		_size = newSize;
		_str[_size] = '\0';
	}
}

void ms::string::reserve(size_t newCapacity)
{
	if (newCapacity > _capacity)//大于才会改变
	{
		char *temp = new char[newCapacity+1];//有效空间扩大为newCapacity

		strcpy(temp, _str);

		delete[]_str;

		_str = temp;

		_capacity = newCapacity;
	}
}



/////////////////////////////////////////////////////////////

// access


char& ms::string::operator[](size_t index)
{
	return _str[index];//必须引用返回，如果不同返回则返回的是临时变量，是不可以被修改的
}

const char& ms::string::operator[](size_t index)const
{
	return _str[index];
}



/////////////////////////////////////////////////////////////

//relational operators


bool ms::string::operator >(const string& s) const
{
	if (strcmp(_str, s._str) > 0)
		return true;

	return false;
}

bool ms::string::operator==(const string& s) const
{
	if (strcmp(_str, s._str) == 0)
		return true;
	return false;
}

bool ms::string::operator>=(const string& s) const
{
	if (*this > s || *this == s)
		return true;
	return false;

	/*if (strcmp(_str, s._str) >= 0)
		return true;
	return false;*/
}



bool ms::string::operator!=(const string& s) const
{
	if (*this == s)
		return false;
	return true;

	/*if (strcmp(_str, s._str) != 0)
		return true;
	return false;*/
}

bool ms::string::operator<(const string& s) const
{
	if (*this >= s)
		return false;
	return true;

	/*if (strcmp(_str, s._str)<0)
		return true;
	return false;*/
}

bool ms::string::operator<=(const string& s) const
{
	if (*this > s)
		return false;
	return true;

	/*if (strcmp(_str, s._str) <= 0)
		return true;
	return false;*/
}

// 返回c在string中第一次出现的位置

size_t ms::string::find(char c, size_t pos = 0) const
{
	assert(pos >= 0 && pos <= _size);

	for (size_t i = pos; i < _size; i++)
	{
		if (_str[i] == c)
			return i;
	}
	return npos;
}

 //返回子串s在string中第一次出现的位置

size_t ms::string::find(const char* s, size_t pos = 0) const
{
	const char* ret = strstr(_str + pos, s);	
	
	if (ret == NULL)
		return npos;
	else
	{
		return ret - _str;//指针-指针=元素个数
	}
}

 //在pos位置上插入字符c/字符串str

ms::string& ms::string::insert(size_t pos, char c)
{
	assert(pos <= _size);

	if (_size >= _capacity)//判定空间容量大小
		reserve(2 * _capacity);

	size_t end = _size+1;

	while (end > pos)
	{
		_str[end] = _str[end - 1];
		end--;
	}

	_str[pos] = c;
	_size++;

	//while (end >= pos)//end会发生类型提升为_size，pos为0时，会死循环
	//{
	//	_str[end + 1] = _str[end];//往后挪动
	//	end--;
	//}
	return *this;
}

ms::string& ms::string::insert(size_t pos, const char* str)
{
	assert(pos <= _size);

	size_t len = strlen(str);

	if (len == 0)//防止陷入死循环
		return *this;

	if (_size + len > _capacity)//扩容
	{
		reserve(_size+len);
	}

	size_t end= _size + len;

	while (end>= pos+len)
	{
		_str[end] = _str[end-len];
		end--;
	}
	
	strncpy(_str + pos, str,len);
	_size += len;

	return *this;

}



// 从pos位置开始，删除len个元素
ms::string& ms::string::erase(size_t pos, size_t len=npos)
{
	assert(pos < _size);

	if (len>strlen(_str + pos))//全部删除
	{
		_size = pos;
		_str[_size] = '\0';
		return *this;
	}
	else
	{
		strcpy(_str + pos , _str + pos + len);
		_size = _size - len;
	}
	return *this;

}


void Printf(ms::string str)
{
	ms::string::iterator it = str.begin();
	while (it != str.end())
	{
		cout << *it << endl;
		++it;
	}
	cout << endl;
}



 ostream& operator<<(ostream& _cout, const ms::string &s)//[]的存在，因此不用写成友元
{
	 
	//cout遇到/0不终止，将所有字符输出，所以不能使用c_str，_str是成员函数，也不能直接调用

	for (size_t i = 0; i < s.size(); i++)
	{
		_cout << s[i];
	}
	return _cout;
	
}

istream& operator>>(istream& _cin, ms::string& s)
{
	s.clear();
	char ch;


	while (1)
	{
		//_cin>>ch ，cin和scanf有规定空格或者换行、为下一个字符的间隔
		_cin.get(ch);
		if (ch == ' '|| ch == '\n')
			break;
		else
		s += ch;
	}

	return _cin;
}




int main()
{
	 ms::string str2;

	const ms::string str3("123456789");

	str2 = "123456";
	cout << str2 << endl;
	
	
	//str3.erase(3, 5);
	 //cout << str3 << endl;

	str2.resize(50, 'a');
	cout << str2 << endl;
	cout << str2.size() << endl;
	cout << str2.capacity() << endl;

	str2.resize(20, 'a');
	cout << str2 << endl;
	cout << str2.size() << endl;
	cout << str2.capacity() << endl<<endl<< endl;


	str2.reserve(100);
	cout << str2 << endl;
	cout << str2.size() << endl;
	cout << str2.capacity() << endl;

	cout << str2.find('c',5) << endl;


	system("pause");

	return 0;



}
