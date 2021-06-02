#pragma once
#include "rbt.hpp"

namespace my
{
	
	template<class K,class V>
	class map
	{
		struct mapKofT//map��Ϊ�ϲ㣬֪��V��ʲô����
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
			//����1��
			//inser ����pair<RBTreeNode<pair<const K, V>>*, bool>
			//return ((insert(make_pair(k, V())).first)->_t).second;


			//����2��
			//_t[]����һ��������
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