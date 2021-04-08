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

		typedef char* iterator;//这里就可以证明，string类的迭代器就是指针

	public:

		string(const char* str);

		string(const string& s);

		//string& operator=(const string &s);
		string&operator=(string s);//现代写法

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



		// 返回c在string中第一次出现的位置

		size_t find(char c, size_t pos ) const;

		// 返回子串s在string中第一次出现的位置

		size_t find(const char* s, size_t pos ) const;

		// 在pos位置上插入字符c/字符串str，并返回该字符的位置

		string& insert(size_t pos, char c);

		string& insert(size_t pos, const char* str);



		// 删除pos位置上的元素，并返回该元素的下一个位置

		string& erase(size_t pos, size_t len);

	private:

		char* _str;

		size_t _capacity;

		size_t _size;

		static const size_t npos;
	};

	const size_t string::npos = -1;

}