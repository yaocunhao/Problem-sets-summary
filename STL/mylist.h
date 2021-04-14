#pragma once
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <assert.h>

namespace my
{
	//类节点
	template<class T>
	struct __list_node//用struct是因为全都是公有成员
	{
		__list_node(const T& data=T())//匿名对象,自动调用构造函数,构造一个节点
		:_prev(nullptr)
		, _next(nullptr)
		, _data(data)
		{}
	
		__list_node<T> *_prev;
		__list_node<T> *_next;
		T _data;
		
	};

	//类迭代器 <T,T&,T*>
	template<class T,class Ref,class  Ptr>
	struct __list_iterator//不是原生指针，所以要封装成类，重载运算符模拟原生指针的用法
	{
		typedef __list_node<T> node;
		typedef struct __list_iterator<T,Ref,Ptr> self;//类型重定义

		node *_node;//成员变量

		//不需要拷贝，赋值，析构等等，编译器默认生成的就能用
		__list_iterator(node *node)
			:_node(node)
		{
		}

		bool operator !=(const self &s)const 
		{
			return (_node != s._node);
		}

		bool operator ==(const self &s)const 
		{
			return (_node == s._node);
		}

		Ref operator *() const//返回的是引用的值，所以是Ref，是否返回const由模板决定
		{
			return _node->_data;
		}

		self &operator --()//对象还在，应用返回
		{
			_node = _node->_prev;
			return *this;
		}

		self &operator ++()
		{
			_node = _node->_next;
			return *this;
		}

		self operator --(int)//新构造的迭代器，因此不能引用
		{
			self rnode = _node;//隐式类型转换
			_node = _node->_prev;
			return rnode;
		}

		self operator ++(int)
		{
			self rnode = _node;//隐式类型转换
			_node = _node->_next;
			return rnode;
		}

		Ptr operator ->()const //当T是结构体类型的时候，->->被编译器优化成->
		{
			return &_node->_data;
		}

	};


	template<class T>
	class list
	{
	public:
		typedef __list_node<T> node;
		typedef struct __list_iterator<T,T&,T*> iterator;
		typedef struct  __list_iterator<T, const T&, const T*> const_iterator;

	public:
		list()//初始化，双向循环链表头指向自己
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		template <class inputleterator>
		
		list(inputleterator first, inputleterator last)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;

			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(const list<T>&ls)
		{
			_head = new node;//防止temp析构时崩掉
			_head->_next = _head;
			_head->_prev = _head;

			/*const_iterator it = ls.begin();
			while (it != ls.end())
			{
				push_back(*it);
				++it;
			}*/

			list<T> temp(ls.begin(), ls.end());//构造一个临时对象
			std::swap(_head, temp._head);//交换头节点
		}

		list<T> operator =(list<T> ls)//拷贝构造一份过来
		{
			std::swap(_head, ls._head);//直接交换两个头节点
			return *this;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		//list iterator

		iterator begin() 
		{
			return _head->_next;//节点指针，隐式类型转换成迭代器

			//等价于 return(_head->_next)//构造一下
			//或者	iterator it(_head->_next),return it;
		}

		iterator end() 
		{
			return _head;
		}


		const_iterator begin()const
		{
			return _head->_next;//节点指针，隐式类型转换成迭代器
			//等价于 return(_head->_next)//构造一下
			//或者	iterator it(_head->_next),return it;
		}

		const_iterator end()const
		{
			return _head;
		}

		//list capacity

		bool empty()const 
		{
			if (_head->_next == _head)
				return true;
			else
				return false;
		}
		
		size_t size()const 
		{
			const_iterator it = begin();
			size_t count=0;

			while (it != end())
			{
				count++;
				it++;
			}
			return count;
		}

		// list element access

		const T& front()const 
		{
			assert(!empty());
			return _head->_next->_data;
		}

		const T &back()const 
		{
			assert(!empty());
			return _head->_prev->_data;
		}

		T& front()
		{
			assert(!empty());
			return _head->_next->_data;
		}

		T &back()
		{
			assert(!empty());
			return _head->_prev->_data;
		}

		//list modifiers

		void push_back(const T&x)
		{
			insert(end(), x);

			//node *newnode = new node(x);//构造一个新节点

			//node *tail = _head->_prev;
			//tail->_next = newnode;
			//newnode->_prev = tail;
			//newnode->_next = _head;
			//_head->_prev = newnode;
		}



		void push_front(const T&x)
		{
			insert(++begin(), x);

			//node *newnode = new node(x);//构造一个新节点
			//
			//node *next = _head->_next;
			//_head->_next = newnode;
			//newnode->_prev=_head;
			//newnode->_next = next;
			//next->_prev = newnode;
		}

		void pop_front()
		{
			erase(begin());

			//assert(!empty());

			//node *del = _head->_next;

			////重新连接头结点

			//node *next = del->_next;
			//_head->_next = next;
			//next-> _prev = _head;

			//delete del;
		}

		void pop_back()
		{
			erase(--end());

			/*assert(!empty());
			node *del = _head->_prev;

			node *prev = del->_prev;
			_head->_prev = prev;
			prev->_next = _head;*/
		}

		iterator insert(iterator pos,const T &x)
		{
			//因为循环链表，迭代器位置不管怎么自增自减都在链表中
			//不需要判断
			node *newnode = new node(x);//构造一个新节点

			node *cur = pos._node;
			node *prev = cur->_prev;

			newnode->_next = cur;
			newnode->_prev = prev;

			cur->_prev = newnode;
			prev->_next = newnode;

			return newnode;
		}

		iterator erase(iterator pos)
		{
			assert(pos!= end());//头不能删了

			node *cur = pos._node;
			node *prev = cur->_prev;
			node *next = cur->_next;

			prev->_next = next;
			next->_prev = prev;

			delete cur;
			return next;
		}


		void clear()
		{
			
			iterator it = begin();
			while (it != end())
			{
				erase(it++);
			}

		}

	private:
		node *_head;//双向带头循环链表
	};
}



#include"list.hpp"




void test2()
{
	struct Test
	{
		int x;
		int y;
	};



	my::list<Test> ls;

	ls.push_back({ 10, 200 });
	ls.push_back({ 20, 300 });
	ls.push_back({ 30, 400 });


	auto it = ls.begin();

	while (it != ls.end())
	{
		cout << (*it).x<<" "<<(*it).y<< endl;
		it++;
	}


}


void test1()
{
	my::list<int> ls;
	ls.push_back(1);
	ls.push_back(2);
	ls.push_back(3);
	ls.push_back(4);
	ls.push_back(5);
	ls.push_back(6);

	auto it = ls.begin();

	while (it != ls.end())
	{
		cout << *it << " ";
		(*it) += 100;
		it++;
	}
	cout << endl;


	ls.push_front(1000000);
	ls.push_front(1000023200);
	ls.push_front(106462000);
	ls.push_front(100220000);

	for (const auto &e : ls)
	{
		cout << e << " ";
	}
	cout << endl;

	//cout << ls.empty() << endl;
	cout << "size" << ls.size() << endl;
	cout << "head" << ls.front() << endl;
	cout << "back" << ls.back() << endl;
	ls.back() = 1000;
	cout << "back" << ls.back() << endl;

	ls.pop_back();
	ls.pop_back();
	ls.pop_back();
	ls.pop_back();
	ls.pop_back();


	//it前面已经用过了，因此需要注意迭代器失效的问题
	it = ls.begin();

	while (it != ls.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	cout << ls.size() << endl;

	ls.pop_front();
	ls.pop_front();
	ls.pop_front();



	//it前面已经用过了，因此需要注意迭代器失效的问题
	it = ls.begin();

	while (it != ls.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	cout << ls.size() << endl;




	ls.insert(ls.begin(), 1222);
	auto q=ls.insert(--ls.end(), 13432);
	ls.insert(q, 1888);



	//it前面已经用过了，因此需要注意迭代器失效的问题
	it = ls.begin();

	while (it != ls.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	cout << ls.size() << endl;


	
	it = ls.begin();
	it=ls.erase(it);
	it=ls.erase(it);
	ls.erase(--ls.end());

	it = ls.begin();
	while (it != ls.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	cout << ls.size() << endl;

	cout << "__________________" << endl;

	my::list<int> ls2(ls.begin(), ls.end());

	it = ls2.begin();
	while (it != ls2.end())
	{
		cout << *it << endl;
		it++;
	}
	cout << ls2.size() << endl;


	cout << "__________________" << endl;

	my::list<int> ls3(ls2);

	it = ls3.begin();
	while (it != ls3.end())
	{
		cout << *it << endl;
		it++;
	}
	cout <<"ls3" <<ls3.size() << endl;


	my::list<int> l5;
	l5.push_back(1);
	l5.push_back(2);
	l5.push_back(3);
	l5.push_back(4);

	ls3 = l5;
	cout << "__________________" << endl;

	
	
	it = ls3.begin();
	while (it != ls3.end())
	{
		cout << *it << endl;
		it++;
	}

	cout << "ls3" << ls3.size() << endl;
	
}


int main()
{
	test1();


	//test2();




	getchar();
	return 0;
}















