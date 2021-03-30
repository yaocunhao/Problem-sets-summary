#pragma once

#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
#pragma warning (disable :4996)
#include <algorithm>
#include <string>
#include <assert.h>


namespace ms

{

	class string

	{

	public:

		typedef char* iterator;//����Ϳ���֤����string��ĵ���������ָ��

	public:

		string(const char* str);

		string(const string& s);

		//string& operator=(const string &s);
		string&operator=(string s);//�ִ�д��

		~string();



			//////////////////////////////////////////////////////////////

			// iterator

		iterator begin();

		iterator end();



			/////////////////////////////////////////////////////////////

			// modify

			void PushBack(char c);

		string& operator+=(char c);

		void Append(const char* str);

		string& operator+=(const char* str);

		string operator+(const char* str);


		void clear();

		void swap(string& s);

		const char* c_str()const;



		/////////////////////////////////////////////////////////////

		// capacity

		size_t size()const;

		size_t capacity()const;

		bool empty()const;

		void resize(size_t newSize, char c);

		void reserve(size_t newCapacity);



		/////////////////////////////////////////////////////////////

		// access

		char& operator[](size_t index);

		const char& operator[](size_t index)const;



		/////////////////////////////////////////////////////////////

		//relational operators

		bool operator<(const string& s)const;

		bool operator<=(const string& s) const;

		bool operator>(const string& s)const;

		bool operator>=(const string& s) const;

		bool operator==(const string& s) const;

		bool operator!=(const string& s)const;



		// ����c��string�е�һ�γ��ֵ�λ��

		size_t find(char c, size_t pos ) const;

		// �����Ӵ�s��string�е�һ�γ��ֵ�λ��

		size_t find(const char* s, size_t pos ) const;

		// ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��

		string& insert(size_t pos, char c);

		string& insert(size_t pos, const char* str);



		// ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��

		string& erase(size_t pos, size_t len);

	private:

		char* _str;

		size_t _capacity;

		size_t _size;

		static const size_t npos;
	};

	const size_t string::npos = -1;

}