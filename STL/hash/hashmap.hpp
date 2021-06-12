#pragma once
#include "hash.hpp"


namespace YCH_MAP
{
	//���ù�ϣת������ <-> ����int �� string 
	//���K���Ͳ�֧��ȡģ������Ҫ����һ���º���������ʹ��
	template<class K>
	struct Hash
	{
		size_t operator() (const K&key)
		{
			return key;
		}
	};

	//string���ͳ��ã������ػ�
	template<>
	struct Hash<string>
	{
		size_t operator() (const string &key)
		{
			size_t count = 0;
			for (auto&e : key)
			{
				count = count * 131 + e;// �ַ���ת�������ϣ��ַ����ֵ131�����Լ��ٳ�ͻ
			}
			return count;
		}
	};

	template<class K, class V, class hash = Hash<K>>
	class ych_unordered_map
	{

	private:
		struct map_KeyofT
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename YCH_OPEN_HASH::HashTable<K, pair<const K, V>, map_KeyofT, hash>::Iterator iterator;

		iterator begin()
		{
			return _ht.Begin();
		}

		iterator end()
		{
			return _ht.End();
		}

		pair<iterator, bool> insert(const pair<const K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		V& operator[](const K& k)
		{
			return ((insert(make_pair(k, V()))).first)->second;
		}


	private:
		YCH_OPEN_HASH::HashTable<K, pair<const K, V>, map_KeyofT, hash> _ht;

	};
};