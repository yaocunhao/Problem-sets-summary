#pragma once
#include "rbt.hpp"

namespace my
{
	template<class K>
	class set
	{
		struct setKofT//仿函数
		{
			const K& operator ()(const K &k)
			{
				return k;
			}
		};

	public:

		//typename告诉编译器实例化之后再去找
		//如果不加，这里对Iterator进行类型重定义,但是RBTree没有实例化，因此是找不到的
		typedef typename RBTree<K, K, setKofT>::Iterator iterator;

		iterator begin()//实际上调用的是红黑树的begin
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}


		pair<RBTreeNode<K>*, bool> insert(const K &k )
		{
			return _t.Insert(k);
		}


	private:
		RBTree<K, K, setKofT> _t;//红黑树对象

	};

};