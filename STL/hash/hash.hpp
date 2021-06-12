#ifndef _HASH_HPP_
#define _HASH_HPP_

using namespace std;
#include <iostream>
#include <vector>
#include <assert.h>
#include <string> 


//闭散列
//set<K> -> HashTable<K,K>
//map<K,V> -> HashTable<K,pair<K,V>>
namespace YCH_CLOSE_HASH
{

	enum State
	{
		EMPTY,//空
		DELETE,//存在
		EXIST//删除
	};

	template<class T>
	struct HashNode//存储的节点
	{
		State _state = EMPTY;//节点状态，默认为空状态（缺省值）
		T _t;//节点的值

		HashNode(const T&t=T())
			:_t(t)
		{}

	};

	////内置哈希转换函数 <-> 常用int 和 string 
	////如果K类型不支持取模，就需要配上一个仿函数来进行使用
	//template<class K>
	//struct hash
	//{
	//	size_t operator() (const K&key)
	//	{
	//		return key;
	//	}
	//};

	////string类型常用，进行特化
	//template<>
	//struct hash<string>
	//{
	//	size_t operator() (const string &key)
	//	{
	//		size_t count = 0;
	//		for (auto&e : key)
	//		{
	//			count = count * 131 + e;// 字符串转整形求哈希地址常用值131，可以减少冲突
	//		}
	//		return count;
	//	}
	//};

	//迭代器的构造

	//提前声明哈希表
	template <class K, class T, class KeyofT, class Hash>//声明和定义不能同时候缺省参数
	class HashTable;

	template<class K, class T, class KeyofT, class Hash>
	struct  HashIterator
	{
		typedef HashIterator<K, T, KeyofT, Hash> Self;
		typedef HashNode<T> Node;
		typedef HashTable<K, T, KeyofT, Hash> HashTable;

		Node *_node;
		HashTable *_pht;//迭代器里面还需要包括哈希表


		HashIterator(Node* node, HashTable *pth)
			:_node(node)
			, _pht(pth)
		{}

		T& operator*()
		{
			assert(_node != nullptr);
			return _node->_t;
		}

		T* operator ->()
		{
			assert(_node != nullptr);
			return &(_node->_t);
		}

		bool operator == (const Self &s)const
		{
			return _node == s._node;
		}

		bool operator != (const Self &s)const
		{
			return _node != s._node;
		}

		Self& operator++()//寻找当前位置的后面一个有元素的位置
		{
			//先找到当前节点所在位置，然后往后寻找下一个节点的位置
			KeyofT kf;

			size_t begin = _pht->HashFunc(kf(_node->_t));//得到映射的哈希位置
			//不清楚是否发生冲突因此还要再次寻找
			size_t index = begin;
			size_t i = 1;
			int flag = 1;

			while (_pht->_tables[index]._state != EMPTY)//等于空就停止，这也是为什么要用HashNode的原因，直接判断，如果删除了，也会出现空
			{
				if (_pht->_tables[index]._state == EXIST&&kf(_node->_t) == kf(_pht->_tables[index]._t))//存在且K值对应
				{
					break;
				}
				
				index = (begin + i*i*flag) % _pht->_tables.size();//二次探测

				if (flag == -1)
				{
					i++;//增大值
					flag = 1;
				}
				else
				{
					flag = -1;//变换方向
				}
			}

			//此时index的位置就是第一个当前位置的数据，然后往后遍历整张表，输出元素
			for (int i = index+1; i < _pht->_tables.size(); i++)
			{
				if (_pht->_tables[i]._state == EXIST)
				{
					/*_node->_t = _pht->_tables[i]._t; //BUG,这是将原来节点里面的值也给更改了
					_node->_state = _pht->_tables[i]._state;*/
					
					_node = &(_pht->_tables[i]);
					return *this;
				}
			}

			//return _pht->End();这样不行，没有接受值，只是返回了一个下一个位置的迭代器
			_node = nullptr;
			return *this;
		}

		Self operator++(int)//后置++
		{
			//先找到当前节点所在位置，然后往后寻找下一个节点的位置
			KeyofT kf;

			size_t begin = _pht->HashFunc(kf(_node->_t));//得到映射的哈希位置
			//不清楚是否发生冲突因此还要再次寻找
			size_t index = begin;
			size_t i = 1;
			int flag = 1;

			while (_pht->_tables[index]._state != EMPTY)//等于空就停止，这也是为什么要用HashNode的原因，直接判断，如果删除了，也会出现空
			{
				if (_pht->_tables[index]._state == EXIST&&kf(_node->_t) == kf(_pht->_tables[index]._t))//存在且K值对应
				{
					break;
				}

				index = (begin + i*i*flag) % _pht->_tables.size();//二次探测

				if (flag == -1)
				{
					i++;//增大值
					flag = 1;
				}
				else
				{
					flag = -1;//变换方向
				}
			}

			//此时index的位置就是第一个当前位置的数据，然后往后遍历整张表，输出元素

			Node *copy_node = _node;//保存一份
			for (int i = index + 1; i < _pht->_tables.size(); i++)
			{
				if (_pht->_tables[i]._state == EXIST)
				{
					/*_node->_t = _pht->_tables[i]._t; //BUG,这是将原来节点里面的值也给更改了
					_node->_state = _pht->_tables[i]._state;*/

					_node = &(_pht->_tables[i]);


					return Self(copy_node, _pht);
				}
			}

			//return _pht->End();这样不行，迭代器本身没有改变，只是返回了一个下一个位置的迭代器
			_node = nullptr;
			return Self(copy_node, _pht);
		}


	};

	//哈希表的构造


	size_t GetNextPrime(size_t prime)
	{
		static const int PRIMECOUNT = 28;//给成静态，不用重复生成
		static const size_t primeList[PRIMECOUNT] =
		{
			53ul, 97ul, 193ul, 389ul, 769ul,
			1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
			49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
			1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
			50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
			1610612741ul, 3221225473ul, 429496729ul
		};

		size_t i = 0;
		for (; i <PRIMECOUNT; ++i){
			if (primeList[i] > prime)
				return primeList[i];
		}

		return primeList[i];
	}

	template<class K, class T, class KeyofT, class Hash>//默认给int进行比较
	class HashTable
	{
	public:
		//构造迭代器
		typedef HashIterator<K, T, KeyofT, Hash> Iterator;
		friend  Iterator; //<=>HashIterator<K, T, KeyofT, Hash>;//将迭代器声明为，哈希表的友元类，即可以访问哈希表的私有成员

		Iterator Begin()
		{
			for (int i = 0; i < _tables.size(); i++)//找到第一个不为空的值
			{
				if (_tables[i]._state == EXIST)
					return Iterator(&_tables[i], this);
			}
			return End();
		}

		Iterator End()
		{
			return Iterator(nullptr, this);
		}

		//构造插入函数

		size_t HashFunc(const K& key)//哈希函数
		{
			Hash hf;
			return hf(key) % _tables.size();
		}

		pair<Iterator,bool> Insert(const T & t)
		{
			//判断要插入的元素是否已经存在
			KeyofT kf;
			Iterator ret = Find(kf(t));
			if (ret!=End())//已经存在了,multiset/multimap则不需要
				return make_pair(ret,false);

			//进行扩容检测
			if (_size == 0 || (_size / _tables.size() * 10 > 7))//当前个数为0或者载荷因子超过了,则进行扩容
			{
				//size_t newsize = _size == 0 ? 10 : 2 * _tables.size();//初始化给10，后续扩容两倍

				//选取素数
				size_t newsize = GetNextPrime(_tables.size());

				//扩容之后，需要重新计算元素的位置

				HashTable<K, T, KeyofT, Hash> newtable;
				newtable._tables.resize(newsize);

				for (auto&e : _tables)
				{
					if (e._state == EXIST)
						newtable.Insert(e._t);
				}
				_tables.swap(newtable._tables);//进行交换
			}


			//查找插入的位置

			//KeyofT kf;//获取元素类型
			//Hash hf;//将元素转为整形

			size_t begin = HashFunc(kf(t));//获取映射位置
			size_t index = begin;
			size_t i = 1;
			int flag = 1;
			while (_tables[index]._state == EXIST)//发生冲突，则继续寻找
			{
				index = (begin + i*i*flag) % _tables.size();//二次探测

				if (flag == -1)
				{
					i++;//增大值
					flag = 1;
				}
				else
				{
					flag = -1;//变换方向
				}
			}

			//此时已经找到位置了，进行元素的添加
			
			_tables[index]._t = t;
			_tables[index]._state = EXIST;
			_size++;

			return make_pair(Iterator(&_tables[index],this),true);
		}

		Iterator Find(const K& key)//查找的时候需要注意，查找的值不一定存在
		{
			if (_size == 0)//为空
				return Iterator(nullptr,this);

			//Hash hf;//转整形
			KeyofT kf;//拿K值

			size_t begin = HashFunc(key);//转为整形，获取映射位置.
			size_t index = begin;
			size_t i = 1;
			int flag = 1;

			while (_tables[index]._state != EMPTY)//等于空就停止，这也是为什么要用HashNode的原因，直接判断，如果删除了，也会出现空
			{
				if (_tables[index]._state == EXIST&&key == kf(_tables[index]._t))//存在且K值对应
				{
					return Iterator(&_tables[index],this);
				}

				index = (begin + i*i*flag) % _tables.size();//二次探测

				if (flag == -1)
				{
					i++;//增大值
					flag = 1;
				}
				else
				{
					flag = -1;//变换方向
				}
			}
			//当前值不存在
			return End();
		}

		bool Erase(const K& key)//先找到再删除
		{
			HashNode<T>* node = Find(key);
			if (node)
			{
				node->_state = DELETE;//伪删除
				_size--;
				return true;
			}
			return false;
		}


	private:
		vector<HashNode<T>> _tables;//底层结构
		size_t _size = 0;//存储的数据的个数
	};
};



static size_t GetNextPrime(size_t prime)
{
	static const int PRIMECOUNT = 28;//给成静态，不用重复生成
	static const size_t primeList[PRIMECOUNT] =
	{
		53ul, 97ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
		1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
		50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
		1610612741ul, 3221225473ul, 429496729ul
	};

	size_t i = 0;
	for (; i <PRIMECOUNT; ++i){
		if (primeList[i] > prime)
			return primeList[i];
	}

	return primeList[i];
}

namespace YCH_OPEN_HASH
{
	//节点
	template<class T>
	struct HashLink
	{
		HashLink<T> *_next;
		T _t;

		HashLink(const T& t)
			:_t(t)
			,_next(nullptr)
		{}
	};

	//前置声明
	template<class K, class T, class KeyofT, class Hash>
	class HashTable;

	//迭代器
	template<class K, class T,class Ref,class Ptr ,class KeyofT, class Hash>
	struct HashIterator
	{
		typedef HashLink<T> Node;
		typedef HashTable<K, T, KeyofT, Hash> HashTable;
		typedef HashIterator<K, T, Ref, Ptr, KeyofT,Hash> Self;

		Node *_node;//节点
		HashTable *_pht;//哈希表指针,++的时候需要计算位置

		HashIterator(Node *node,HashTable* tables)//构造函数需要传入节点指针，和哈希表指针
			:_node(node)
			, _pht(tables)
		{}

		Ref operator*()
		{
			assert(_node);
			return _node->_t;
		}

		Ptr operator->()
		{
			assert(_node);
			return &(_node->_t);//返回去的是一个地址，使用的时候编译器优化，减少了一个箭头
		}

		KeyofT kf;
		Self &operator++()//前置
		{
			size_t pos = _pht->HashFunc(kf(_node->_t),_pht->_tables);//获取当前位置
			pos++;
			_node = _node->_next;
			if (_node == nullptr)//当前链表走完了，寻找下一个节点
			{
				for (int i = pos; i < _pht->_tables.size(); i++)
				{
					if (_pht->_tables[i] != nullptr)
					{
						_node = _pht->_tables[i];
						break;
					}
				}
			}
			return *this;
		}

		bool operator!=(Self &s)
		{
			return _node != s._node;
		}

	};



	template<class K, class T, class KeyofT,class Hash>
	class HashTable
	{
	public:
		typedef HashLink<T> Node;
		typedef HashIterator<K, T, T&, T*, KeyofT, Hash> Iterator;
		typedef HashIterator<K, T, const T&, const T*, KeyofT, Hash> Const_Iterator;
		
		//迭代器友元
		friend HashIterator<K, T, T&, T*, KeyofT, Hash>;
		friend Const_Iterator;


		Iterator Begin()
		{
			for (int i = 0; i < _tables.size(); i++)
			{
				if (_tables[i] != nullptr)
					return Iterator(_tables[i], this);
			}
			return Iterator(nullptr, this);
		}

		Iterator End()
		{
			return Iterator(nullptr, this);
		}


		KeyofT kf;//提取key值

		//哈希函数
		size_t HashFunc(const K& key,const vector<HashLink<T>*> tables)
		{
			Hash hf;
			return hf(key) % tables.size();
		}

		pair<Iterator,bool> Insert(const T& t)
		{
			//判断是否存在
			if (_tables.size())//防止%0
			{
				Iterator fi = Find(kf(t));
				if (fi != End())//存在
					return make_pair(fi, false);
			}

			//判断是否需要扩容
			if (_size == _tables.size())//α<=1
			{
				size_t newsize = GetNextPrime(_tables.size());
				vector<Node*> newtables(newsize, nullptr);//构造一个新表出来

				for (int i = 0; i < _tables.size(); i++)
				{
					Node* node = _tables[i];
					while (node)//当前位置有节点
					{
						Node *next = node->_next;//保存当前链表的下一个位置

						size_t index = HashFunc(kf(node->_t),newtables);//得到位置
						node->_next = newtables[index];
						newtables[index] = node;

						node = next;
					}
					_tables[i] = nullptr;//原表置空
				}

				//两表交换
				newtables.swap(_tables);
			}

			//插入节点

			size_t index = HashFunc(kf(t),_tables);//寻找插入位置
			Node *newnode = new Node(t);//构造一个节点
			newnode->_next = _tables[index];//头插
			_tables[index] = newnode;
			_size++;

			return make_pair(Iterator(_tables[index], this), true);
		}

		//查找
		Iterator Find(const K& k)
		{
			size_t index=HashFunc(k, _tables);

			Node *cur = _tables[index];
			while (cur&&(kf(cur->_t) !=k))
			{
				cur = cur->_next;
			}
			return Iterator(cur, this);
		}

		////删除
		bool Erase(const K& k)
		{
			size_t intdex = HashFunc(k, _tables);
			Node* cur = _tables[index];
			Node *prev = nullptr;
			while (cur&&kf(cur->_t) != k)
			{
				prev = cur;
				cur = cur->_next;
			}
			if (cur == nullptr)//没找到
				return false;

			prev->_next = cur->_next;
			delete cur;
			_size--;
			return true;
		}

	private:
		vector<Node*> _tables;
		size_t _size;
	};
};



#endif


