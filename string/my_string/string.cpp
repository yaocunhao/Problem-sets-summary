#include "string.h"


ms::string::string(const char* str = "")//���캯��
{
	_size = strlen(str);//size����Ч�ַ�����

		_capacity = _size;//�ռ�����������\0
		if (_capacity == 0)
			_capacity = 15;//���һ��ʼΪ0����������2*_capacity�ͻ������
	
	_str = new char[_capacity+1];//���ٿռ�,Ҫ����\0

	strcpy(_str, str);//��������

}
ms::string::string(const string& s)
:_str(nullptr)//�����ͷ����ֵ
, _size(0)
, _capacity(0)
{
	string temp(s._str);//����һ������
	swap(temp);//this->swap
}

//(��ͳд��)ms::string::string(const string& s)//��Ҫ�����ǳ����������ʱ��ᷢ������
//{
//	_size = s._size;
//
//	_capacity = _size;
//
//	_str = new char[_capacity+1];
//
//	strcpy(_str, s._str);
//}
ms::string& ms::string::operator=( string s)//���ξ��ǿ�������
{
	swap(s);//ֱ�ӽ���
	return *this;
}
//ms::string& ms::string::operator=(const string &s)//��ͳд��
//{
//	if (this != &s)//�����Լ���ֵ�Լ�
//	{
//		char *temp = new char[strlen(s._str) + 1];//��ȷ���ռ��С��ֱ�ӿ���һ��
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
//	return *this;//���÷��ض�������򵥷��ػᷢ�����
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
	return _str;//�ַ�����һ��Ԫ�صĵ�ַ
}

ms::string::iterator ms::string::end()
{
	return (_str + _size);//'\0'�ĵ�ַ
}



/////////////////////////////////////////////////////////////

// modify


ms::string ms::string::operator+(const char* str)
{
	string temp(*this);//�ȿ�������һ��
	
	temp.Append(str);//�ٲ���

	return temp;//���ص�ʱ��ҲҪ��������һ��
}


void ms::string::PushBack(char c)//β��
{
	//if (_size == _capacity)
	//{
	//	reserve(2 * _capacity);//�������ռ�
	//}

	//_str[_size] = c;
	//_str[_size+1] ='\0';

	//_size++;

	insert(_size, c);//����insert��β�������ַ�
}

ms::string& ms::string::operator+=(char c)//+=�ַ�����ʵ����β��
{
	PushBack(c);
	return *this;
}

void ms::string::Append(const char* str)
{
	//if (_size + strlen(str) > _capacity)//�ռ��ж�
	//{
	//	reserve(_size + strlen(str));//Ҫ���ַ�����ֹ����λ��
	//}

	//strcpy(_str + _size , str);//_str+_size����'\0'λ�ã�Ȼ����п���

	//_size += strlen(str);//��ЧԪ�ظ�������

	insert(_size, str);//��β�������ַ���
}

ms::string& ms::string::operator+=(const char* str)//+=�ַ���
{
	//Append(str);//���ַ���������β�˲����ַ���

	insert(_size, str);

	return *this;
}

void ms::string::clear()
{
	_size = 0;//��Ч�ַ����
	_str[_size] = '\0';
}

void ms::string::swap(string& s)//s.swap��swap����3�����
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

void ms::string::resize(size_t newSize, char c = '\0')//��Ч�ַ�������ΪnewSize
{
	if (newSize<_size)//������ЧԪ�ظ���
	{
		_str[newSize] = '\0';
		_size = newSize;
	}
	else//������ЧԪ�ظ���
	{
		if (newSize>_capacity)//��Ҫ����
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
	if (newCapacity > _capacity)//���ڲŻ�ı�
	{
		char *temp = new char[newCapacity+1];//��Ч�ռ�����ΪnewCapacity

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
	return _str[index];//�������÷��أ������ͬ�����򷵻ص�����ʱ�������ǲ����Ա��޸ĵ�
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

// ����c��string�е�һ�γ��ֵ�λ��

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

 //�����Ӵ�s��string�е�һ�γ��ֵ�λ��

size_t ms::string::find(const char* s, size_t pos = 0) const
{
	const char* ret = strstr(_str + pos, s);	
	
	if (ret == NULL)
		return npos;
	else
	{
		return ret - _str;//ָ��-ָ��=Ԫ�ظ���
	}
}

 //��posλ���ϲ����ַ�c/�ַ���str

ms::string& ms::string::insert(size_t pos, char c)
{
	assert(pos <= _size);

	if (_size >= _capacity)//�ж��ռ�������С
		reserve(2 * _capacity);

	size_t end = _size+1;

	while (end > pos)
	{
		_str[end] = _str[end - 1];
		end--;
	}

	_str[pos] = c;
	_size++;

	//while (end >= pos)//end�ᷢ����������Ϊ_size��posΪ0ʱ������ѭ��
	//{
	//	_str[end + 1] = _str[end];//����Ų��
	//	end--;
	//}
	return *this;
}

ms::string& ms::string::insert(size_t pos, const char* str)
{
	assert(pos <= _size);

	size_t len = strlen(str);

	if (len == 0)//��ֹ������ѭ��
		return *this;

	if (_size + len > _capacity)//����
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



// ��posλ�ÿ�ʼ��ɾ��len��Ԫ��
ms::string& ms::string::erase(size_t pos, size_t len=npos)
{
	assert(pos < _size);

	if (len>strlen(_str + pos))//ȫ��ɾ��
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



 ostream& operator<<(ostream& _cout, const ms::string &s)//[]�Ĵ��ڣ���˲���д����Ԫ
{
	 
	//cout����/0����ֹ���������ַ���������Բ���ʹ��c_str��_str�ǳ�Ա������Ҳ����ֱ�ӵ���

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
		//_cin>>ch ��cin��scanf�й涨�ո���߻��С�Ϊ��һ���ַ��ļ��
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
