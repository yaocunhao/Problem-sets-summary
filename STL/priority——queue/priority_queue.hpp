#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <assert.h>
#include <functional>

template<class T>
class Greater//�º���
{
public:
	bool operator ()(const T &x, const T &y)
	{
		return x > y;
	}

};
template<class T>
class Less//�º���
{
public:
	bool operator ()(const T &x, const T &y)
	{
		return x < y;
	}

};
namespace my
{
	template<class T, class Container = vector<T>,class Compare=Greater<T>>
	class priority_queue
	{
	public:
		void ShiftDown(size_t parent)
		{
			Compare com;

			size_t child = parent * 2 + 1;

			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child+1] , _con[child]))
					child++;
				if (com(_con[child] ,_con[parent]))
					swap(_con[child], _con[parent]);
				else
					break;
				parent = child;
				child = 2 * parent + 1;
			}
		}

		void ShiftUp(size_t child)
		{
			Compare com;//�º���

			size_t parent = (child - 1) / 2;
			while (child > 0)//�к���һ���и���
			{
				if (com(_con[child] , _con[parent]))
					swap(_con[child], _con[parent]);
				else
					break;
				child = parent;
				parent = (child - 1) / 2;
			}
		}

		priority_queue() = default;//��priority_queue()�ȼۣ�����ǿ�Ʊ���������һ��Ĭ�ϵĹ��캯����������ʼ����Ա

		template<class InputIterator>

		priority_queue(InputIterator first, InputIterator last)
			:_con(first, last)//�����ﴫ���������г�ʼ��
		{
			for (int i = (_con.size() - 2) / 2; i >= 0; i--)//���µ�������
			{
				ShiftDown(i);
			}

			//for (size_t i = 1; i <_con.size(); i++)
			//{
			//	ShiftUp(i);//���ϵ�������
			//}
		}

		bool empty()const
		{
			return _con.empty();
		}

		const size_t size()const
		{
			return _con.size();
		}

		const T& top()const
		{
			return _con.front();
		}

		void push(const T &x)
		{
			_con.push_back(x);
			ShiftUp(_con.size()-1);//���ϵ���
		}

		void pop()
		{
			assert(!_con.empty());
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			ShiftDown(0);//���µ���
		}

	private:
		Container _con;
	};
}