#pragma once
#include <assert.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include <string>

namespace mv
{
	template<class T>
	class vector
	{
	public:

		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin()const
		{
			return _start;
		}

		const_iterator end()const
		{
			return _finish;
		}


		vector()//构造函数说明，vector出来一个对象之后，第一件就是给它开空间
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storge(nullptr)
		{}

		template<class InputIterator>//模板函数
		vector(InputIterator first, InputIterator last)
			: _start(nullptr),
			_finish(nullptr),
			_end_of_storge(nullptr)
		{
			reserve(last - first);//开辟空间
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		void swap(vector<T> &x)
		{
			std::swap(_start, x._start);
			std::swap(_finish, x._finish);
			std::swap(_end_of_storge, x._end_of_storge);
		}

		vector(const vector<T> &x)
			:_start(nullptr),
			_finish(nullptr),
			_end_of_storge(nullptr)
		{
			vector<T> temp(x.begin(), x.end());
			swap(temp);
		}

		vector<T> &operator =(vector<T> x)
		{
			swap(x);
			return *this;
		}

		T &operator[](size_t index)
		{
			assert(index<size());
			return _start[index];
		}

		T &operator[](size_t index)const//const类型调用const
		{
			assert(index<size());
			return _start[index];
		}

		~vector()
		{
			delete[]_start;
			_start = _finish = _end_of_storge = nullptr;
		}

		size_t capacity()const
		{
			return _end_of_storge - _start;
		}
		size_t size()const
		{
			return _finish - _start;
		}

		//void reserve(size_t n) //浅拷贝，只适用于内置
		//{
		//	if (n>capacity())
		//	{
		//						
		//		T *temp = new T[n];
		//		size_t old_size = size();//临时保存一份，避免失效

		//		memcpy(temp, _start, size()*sizeof(T));

		//		//delete[] _start;
		//		_start = temp;
		//		_finish = _start + old_size;
		//		_end_of_storge = _start + n;
		//		temp = nullptr;
		//	}

		//}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				iterator temp = new T[n];
				size_t old_size = size();//大小临时记录一下

				iterator begin_start = _start;
				iterator begin_temp = temp;

				while (begin_start != _finish)
				{
					*begin_temp = *begin_start;//深拷贝一份
					//往后挪动
					begin_start++;
					begin_temp++;
				}

				delete[] _start;//释放原来的空间
				_start = temp;//指向新的空间
				temp = nullptr;//防止析构自定义类型

				_finish = _start + old_size;//不直接使用size是因为防止迭代器失效
				_end_of_storge = _start + n;

			}
		}

		void check_capacity()
		{
			if (_finish >= _end_of_storge)
			{
				size_t newsize = capacity() == 0 ? 4 : 2 * capacity();//如果为0，则扩容4个，否则扩容2倍
				reserve(newsize);
			}
		}

		void  push_back(const T &x)
		{
			check_capacity();
			*_finish = x;
			_finish++;
		}

		void pop_back()
		{
			assert(_finish>_start);
			_finish--;
		}

		void resize(size_t newsize, const T &x = T())//调用匿名对象，具有常性，需要加上const
		{
			if (newsize>capacity())
			{
				reserve(newsize);//扩容
			}

			if (newsize<size())
				_finish = _start + newsize;

			else
			{
				while (_finish != _start + newsize)
				{
					*_finish = x;
					_finish++;
				}
			}
		}

		iterator insert(iterator  pos, const T&x)
		{
			assert(pos <= _finish&&pos >= _start);

			size_t inpos = pos - _start;//保存一份相对位置，防止迭代器失效
			check_capacity();

			pos = _start + inpos;
			iterator last = _finish;

			while (last != pos)//往后挪动
			{
				*last = *(last - 1);
				last--;
			}
			*pos = x;
			_finish++;

			return pos;//结局和迭代器失效问题
		}

		void Print()
		{
			iterator start = _start;
			while (start != _finish)
			{
				cout << *start << " ";
				start++;
			}
			cout << endl;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start&&pos < _finish);

			iterator temp_pos = pos;

			while (pos < _finish - 1)
			{
				*pos = *(pos + 1);
				pos++;
			}
			_finish--;

			return temp_pos;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storge;

	};
}
