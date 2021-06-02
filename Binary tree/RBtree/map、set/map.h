#pragma once
#include "rbt.hpp"

namespace my
{
	
	template<class K,class V>
	class map
	{
		struct mapKofT//map作为上层，知道V是什么类型
		{
			const K& operator ()(const pair<const K, V> &kv)
			{
				return kv.first;
			}
		};


	public:
		typedef typename RBTree<K, pair<const K, V>, mapKofT>::Iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		pair<RBTreeNode<pair<const K, V>>*, bool> insert(const pair<const K, V> &kv)
		{
			return _t.Insert(kv);
		}

		V& operator[](const K &k)
		{
			//方法1：
			//inser 返回pair<RBTreeNode<pair<const K, V>>*, bool>
			//return ((insert(make_pair(k, V())).first)->_t).second;


			//方法2：
			//_t[]返回一个迭代器
			return _t[make_pair(k,V())]->second;
		}

	

	private:
		RBTree<K, pair<const K, V>, mapKofT> _t;

	};

	void test_map()
	{
		map<int, int >m;
		m.insert(make_pair(1, 1));
		m.insert(make_pair(2, 2));
		m.insert(make_pair(3, 3));
	}
};