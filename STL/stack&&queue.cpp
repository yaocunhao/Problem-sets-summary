#pragma once

#include <list>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

namespace my
{
	template <class T , class Container=deque<T> >
	class stack
	{

	public:
		stack()
		{}

		bool empty()
		{
			return _con.empty();
		}

		size_t size()const
		{
			return _con.size();
		}

		const T& top()
		{
			return _con.back();
		}

		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}


	private:

		Container _con;		
	};

	template <class T, class Container=deque<T> >
	class queue
	{

	public:
		queue()
		{}

		bool empty()
		{
			return _con.empty();
		}

		size_t size()const
		{
			return _con.size();
		}

		const T& front()
		{
			return _con.front();
		}

		const T& back()
		{
			return _con._back();
		}

		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front();
		}


	private:

		Container _con;
	};
}