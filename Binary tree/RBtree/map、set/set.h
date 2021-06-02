#pragma once
#include "rbt.hpp"

namespace my
{
	template<class K>
	class set
	{
		struct setKofT//�º���
		{
			const K& operator ()(const K &k)
			{
				return k;
			}
		};

	public:

		//typename���߱�����ʵ����֮����ȥ��
		//������ӣ������Iterator���������ض���,����RBTreeû��ʵ������������Ҳ�����
		typedef typename RBTree<K, K, setKofT>::Iterator iterator;

		iterator begin()//ʵ���ϵ��õ��Ǻ������begin
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
		RBTree<K, K, setKofT> _t;//���������

	};

};