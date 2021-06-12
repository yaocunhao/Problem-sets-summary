
#pragma once
#include "hash.hpp"


namespace YCH_MAP
{
	
	template<class K, class hash = Hash<K>>
	class ych_unordered_set
	{

	private:
		struct set_KeyofT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};

	public:
		//typedef typename YCH_CLOSE_HASH::HashTable<K, K, set_KeyofT, hash>::Iterator iterator;±ÕÉ¢ÁÐ
		typedef typename YCH_OPEN_HASH::HashTable<K, K, set_KeyofT, hash>::Iterator iterator;//¿ªÉ¢ÁÐ


		iterator begin()
		{
			return _ht.Begin();
		}

		iterator end()
		{
			return _ht.End();
		}

		pair<iterator, bool> insert(const K& k)
		{
			return _ht.Insert(k);
		}

		iterator find(const K &k)
		{
			return _ht.Find(k);
		}


	private:
		//YCH_CLOSE_HASH::HashTable<K, K, set_KeyofT, hash> _ht;
		YCH_OPEN_HASH::HashTable<K, K, set_KeyofT, hash> _ht;


	};
};

