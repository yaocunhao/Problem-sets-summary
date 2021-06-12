#pragma once
#include "hash.hpp"


namespace YCH_MAP
{
	//内置哈希转换函数 <-> 常用int 和 string 
	//如果K类型不支持取模，就需要配上一个仿函数来进行使用
	template<class K>
	struct Hash
	{
		size_t operator() (const K&key)
		{
			return key;
		}
	};

	//string类型常用，进行特化
	template<>
	struct Hash<string>
	{
		size_t operator() (const string &key)
		{
			size_t count = 0;
			for (auto&e : key)
			{
				count = count * 131 + e;// 字符串转整形求哈希地址常用值131，可以减少冲突
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