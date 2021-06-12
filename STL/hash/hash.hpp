#ifndef _HASH_HPP_
#define _HASH_HPP_

using namespace std;
#include <iostream>
#include <vector>
#include <assert.h>
#include <string> 


//��ɢ��
//set<K> -> HashTable<K,K>
//map<K,V> -> HashTable<K,pair<K,V>>
namespace YCH_CLOSE_HASH
{

	enum State
	{
		EMPTY,//��
		DELETE,//����
		EXIST//ɾ��
	};

	template<class T>
	struct HashNode//�洢�Ľڵ�
	{
		State _state = EMPTY;//�ڵ�״̬��Ĭ��Ϊ��״̬��ȱʡֵ��
		T _t;//�ڵ��ֵ

		HashNode(const T&t=T())
			:_t(t)
		{}

	};

	////���ù�ϣת������ <-> ����int �� string 
	////���K���Ͳ�֧��ȡģ������Ҫ����һ���º���������ʹ��
	//template<class K>
	//struct hash
	//{
	//	size_t operator() (const K&key)
	//	{
	//		return key;
	//	}
	//};

	////string���ͳ��ã������ػ�
	//template<>
	//struct hash<string>
	//{
	//	size_t operator() (const string &key)
	//	{
	//		size_t count = 0;
	//		for (auto&e : key)
	//		{
	//			count = count * 131 + e;// �ַ���ת�������ϣ��ַ����ֵ131�����Լ��ٳ�ͻ
	//		}
	//		return count;
	//	}
	//};

	//�������Ĺ���

	//��ǰ������ϣ��
	template <class K, class T, class KeyofT, class Hash>//�����Ͷ��岻��ͬʱ��ȱʡ����
	class HashTable;

	template<class K, class T, class KeyofT, class Hash>
	struct  HashIterator
	{
		typedef HashIterator<K, T, KeyofT, Hash> Self;
		typedef HashNode<T> Node;
		typedef HashTable<K, T, KeyofT, Hash> HashTable;

		Node *_node;
		HashTable *_pht;//���������滹��Ҫ������ϣ��


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

		Self& operator++()//Ѱ�ҵ�ǰλ�õĺ���һ����Ԫ�ص�λ��
		{
			//���ҵ���ǰ�ڵ�����λ�ã�Ȼ������Ѱ����һ���ڵ��λ��
			KeyofT kf;

			size_t begin = _pht->HashFunc(kf(_node->_t));//�õ�ӳ��Ĺ�ϣλ��
			//������Ƿ�����ͻ��˻�Ҫ�ٴ�Ѱ��
			size_t index = begin;
			size_t i = 1;
			int flag = 1;

			while (_pht->_tables[index]._state != EMPTY)//���ڿվ�ֹͣ����Ҳ��ΪʲôҪ��HashNode��ԭ��ֱ���жϣ����ɾ���ˣ�Ҳ����ֿ�
			{
				if (_pht->_tables[index]._state == EXIST&&kf(_node->_t) == kf(_pht->_tables[index]._t))//������Kֵ��Ӧ
				{
					break;
				}
				
				index = (begin + i*i*flag) % _pht->_tables.size();//����̽��

				if (flag == -1)
				{
					i++;//����ֵ
					flag = 1;
				}
				else
				{
					flag = -1;//�任����
				}
			}

			//��ʱindex��λ�þ��ǵ�һ����ǰλ�õ����ݣ�Ȼ������������ű����Ԫ��
			for (int i = index+1; i < _pht->_tables.size(); i++)
			{
				if (_pht->_tables[i]._state == EXIST)
				{
					/*_node->_t = _pht->_tables[i]._t; //BUG,���ǽ�ԭ���ڵ������ֵҲ��������
					_node->_state = _pht->_tables[i]._state;*/
					
					_node = &(_pht->_tables[i]);
					return *this;
				}
			}

			//return _pht->End();�������У�û�н���ֵ��ֻ�Ƿ�����һ����һ��λ�õĵ�����
			_node = nullptr;
			return *this;
		}

		Self operator++(int)//����++
		{
			//���ҵ���ǰ�ڵ�����λ�ã�Ȼ������Ѱ����һ���ڵ��λ��
			KeyofT kf;

			size_t begin = _pht->HashFunc(kf(_node->_t));//�õ�ӳ��Ĺ�ϣλ��
			//������Ƿ�����ͻ��˻�Ҫ�ٴ�Ѱ��
			size_t index = begin;
			size_t i = 1;
			int flag = 1;

			while (_pht->_tables[index]._state != EMPTY)//���ڿվ�ֹͣ����Ҳ��ΪʲôҪ��HashNode��ԭ��ֱ���жϣ����ɾ���ˣ�Ҳ����ֿ�
			{
				if (_pht->_tables[index]._state == EXIST&&kf(_node->_t) == kf(_pht->_tables[index]._t))//������Kֵ��Ӧ
				{
					break;
				}

				index = (begin + i*i*flag) % _pht->_tables.size();//����̽��

				if (flag == -1)
				{
					i++;//����ֵ
					flag = 1;
				}
				else
				{
					flag = -1;//�任����
				}
			}

			//��ʱindex��λ�þ��ǵ�һ����ǰλ�õ����ݣ�Ȼ������������ű����Ԫ��

			Node *copy_node = _node;//����һ��
			for (int i = index + 1; i < _pht->_tables.size(); i++)
			{
				if (_pht->_tables[i]._state == EXIST)
				{
					/*_node->_t = _pht->_tables[i]._t; //BUG,���ǽ�ԭ���ڵ������ֵҲ��������
					_node->_state = _pht->_tables[i]._state;*/

					_node = &(_pht->_tables[i]);


					return Self(copy_node, _pht);
				}
			}

			//return _pht->End();�������У�����������û�иı䣬ֻ�Ƿ�����һ����һ��λ�õĵ�����
			_node = nullptr;
			return Self(copy_node, _pht);
		}


	};

	//��ϣ��Ĺ���


	size_t GetNextPrime(size_t prime)
	{
		static const int PRIMECOUNT = 28;//���ɾ�̬�������ظ�����
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

	template<class K, class T, class KeyofT, class Hash>//Ĭ�ϸ�int���бȽ�
	class HashTable
	{
	public:
		//���������
		typedef HashIterator<K, T, KeyofT, Hash> Iterator;
		friend  Iterator; //<=>HashIterator<K, T, KeyofT, Hash>;//������������Ϊ����ϣ�����Ԫ�࣬�����Է��ʹ�ϣ���˽�г�Ա

		Iterator Begin()
		{
			for (int i = 0; i < _tables.size(); i++)//�ҵ���һ����Ϊ�յ�ֵ
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

		//������뺯��

		size_t HashFunc(const K& key)//��ϣ����
		{
			Hash hf;
			return hf(key) % _tables.size();
		}

		pair<Iterator,bool> Insert(const T & t)
		{
			//�ж�Ҫ�����Ԫ���Ƿ��Ѿ�����
			KeyofT kf;
			Iterator ret = Find(kf(t));
			if (ret!=End())//�Ѿ�������,multiset/multimap����Ҫ
				return make_pair(ret,false);

			//�������ݼ��
			if (_size == 0 || (_size / _tables.size() * 10 > 7))//��ǰ����Ϊ0�����غ����ӳ�����,���������
			{
				//size_t newsize = _size == 0 ? 10 : 2 * _tables.size();//��ʼ����10��������������

				//ѡȡ����
				size_t newsize = GetNextPrime(_tables.size());

				//����֮����Ҫ���¼���Ԫ�ص�λ��

				HashTable<K, T, KeyofT, Hash> newtable;
				newtable._tables.resize(newsize);

				for (auto&e : _tables)
				{
					if (e._state == EXIST)
						newtable.Insert(e._t);
				}
				_tables.swap(newtable._tables);//���н���
			}


			//���Ҳ����λ��

			//KeyofT kf;//��ȡԪ������
			//Hash hf;//��Ԫ��תΪ����

			size_t begin = HashFunc(kf(t));//��ȡӳ��λ��
			size_t index = begin;
			size_t i = 1;
			int flag = 1;
			while (_tables[index]._state == EXIST)//������ͻ�������Ѱ��
			{
				index = (begin + i*i*flag) % _tables.size();//����̽��

				if (flag == -1)
				{
					i++;//����ֵ
					flag = 1;
				}
				else
				{
					flag = -1;//�任����
				}
			}

			//��ʱ�Ѿ��ҵ�λ���ˣ�����Ԫ�ص����
			
			_tables[index]._t = t;
			_tables[index]._state = EXIST;
			_size++;

			return make_pair(Iterator(&_tables[index],this),true);
		}

		Iterator Find(const K& key)//���ҵ�ʱ����Ҫע�⣬���ҵ�ֵ��һ������
		{
			if (_size == 0)//Ϊ��
				return Iterator(nullptr,this);

			//Hash hf;//ת����
			KeyofT kf;//��Kֵ

			size_t begin = HashFunc(key);//תΪ���Σ���ȡӳ��λ��.
			size_t index = begin;
			size_t i = 1;
			int flag = 1;

			while (_tables[index]._state != EMPTY)//���ڿվ�ֹͣ����Ҳ��ΪʲôҪ��HashNode��ԭ��ֱ���жϣ����ɾ���ˣ�Ҳ����ֿ�
			{
				if (_tables[index]._state == EXIST&&key == kf(_tables[index]._t))//������Kֵ��Ӧ
				{
					return Iterator(&_tables[index],this);
				}

				index = (begin + i*i*flag) % _tables.size();//����̽��

				if (flag == -1)
				{
					i++;//����ֵ
					flag = 1;
				}
				else
				{
					flag = -1;//�任����
				}
			}
			//��ǰֵ������
			return End();
		}

		bool Erase(const K& key)//���ҵ���ɾ��
		{
			HashNode<T>* node = Find(key);
			if (node)
			{
				node->_state = DELETE;//αɾ��
				_size--;
				return true;
			}
			return false;
		}


	private:
		vector<HashNode<T>> _tables;//�ײ�ṹ
		size_t _size = 0;//�洢�����ݵĸ���
	};
};



static size_t GetNextPrime(size_t prime)
{
	static const int PRIMECOUNT = 28;//���ɾ�̬�������ظ�����
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
	//�ڵ�
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

	//ǰ������
	template<class K, class T, class KeyofT, class Hash>
	class HashTable;

	//������
	template<class K, class T,class Ref,class Ptr ,class KeyofT, class Hash>
	struct HashIterator
	{
		typedef HashLink<T> Node;
		typedef HashTable<K, T, KeyofT, Hash> HashTable;
		typedef HashIterator<K, T, Ref, Ptr, KeyofT,Hash> Self;

		Node *_node;//�ڵ�
		HashTable *_pht;//��ϣ��ָ��,++��ʱ����Ҫ����λ��

		HashIterator(Node *node,HashTable* tables)//���캯����Ҫ����ڵ�ָ�룬�͹�ϣ��ָ��
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
			return &(_node->_t);//����ȥ����һ����ַ��ʹ�õ�ʱ��������Ż���������һ����ͷ
		}

		KeyofT kf;
		Self &operator++()//ǰ��
		{
			size_t pos = _pht->HashFunc(kf(_node->_t),_pht->_tables);//��ȡ��ǰλ��
			pos++;
			_node = _node->_next;
			if (_node == nullptr)//��ǰ���������ˣ�Ѱ����һ���ڵ�
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
		
		//��������Ԫ
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


		KeyofT kf;//��ȡkeyֵ

		//��ϣ����
		size_t HashFunc(const K& key,const vector<HashLink<T>*> tables)
		{
			Hash hf;
			return hf(key) % tables.size();
		}

		pair<Iterator,bool> Insert(const T& t)
		{
			//�ж��Ƿ����
			if (_tables.size())//��ֹ%0
			{
				Iterator fi = Find(kf(t));
				if (fi != End())//����
					return make_pair(fi, false);
			}

			//�ж��Ƿ���Ҫ����
			if (_size == _tables.size())//��<=1
			{
				size_t newsize = GetNextPrime(_tables.size());
				vector<Node*> newtables(newsize, nullptr);//����һ���±����

				for (int i = 0; i < _tables.size(); i++)
				{
					Node* node = _tables[i];
					while (node)//��ǰλ���нڵ�
					{
						Node *next = node->_next;//���浱ǰ�������һ��λ��

						size_t index = HashFunc(kf(node->_t),newtables);//�õ�λ��
						node->_next = newtables[index];
						newtables[index] = node;

						node = next;
					}
					_tables[i] = nullptr;//ԭ���ÿ�
				}

				//������
				newtables.swap(_tables);
			}

			//����ڵ�

			size_t index = HashFunc(kf(t),_tables);//Ѱ�Ҳ���λ��
			Node *newnode = new Node(t);//����һ���ڵ�
			newnode->_next = _tables[index];//ͷ��
			_tables[index] = newnode;
			_size++;

			return make_pair(Iterator(_tables[index], this), true);
		}

		//����
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

		////ɾ��
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
			if (cur == nullptr)//û�ҵ�
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


