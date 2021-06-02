#pragma once
#include <iostream>
#include <assert.h>
#include <windows.h>
using namespace std;

enum Color
{
	RED,
	BLACK
};


template<class T>//�ڵ�ֻ�ṩһ��T(V)ֵ������set��map����һ�ź����
struct RBTreeNode
{
	RBTreeNode(const T &t)
	:_left(nullptr)
	, _right(nullptr)
	, _parent(nullptr)
	, _t(t)
	, _col(RED)
	{}

	RBTreeNode<T> *_left;
	RBTreeNode<T> *_right;
	RBTreeNode<T> *_parent;
	T _t;
	enum  Color _col;
};

//�������ķ�װ
template<class T, class Ref, class Ptr>
struct RBTreeIterator
{
	typedef RBTreeIterator<T, Ref, Ptr> Self;//������++  ���ǵ�����
	typedef RBTreeNode<T> Node;
	Node *_node;

	RBTreeIterator(Node *node)
		:_node(node)
	{}

	Ref operator *()
	{
		assert(_node != nullptr);
		return _node->_t;
	}

	Ptr operator ->()
	{
		assert(_node != nullptr);
		return &(_node->_t);//���ص��ǽڵ��ָ������ã��������Ż���һ�μ�ͷ
	}

	Self operator ++()//���������һ��
	{
		assert(_node != nullptr);

		// �������һ��
		if (_node->_right)//�ҽڵ㲻Ϊ�գ���һ��λ�þ�Ϊ����������ڵ�
		{
			// ����������ڵ�
			Node* cur = _node->_right;
			while (cur && cur->_left)
			{
				cur = cur->_left;
			}

			_node = cur;
		}
		else
		{
			//�ұ�Ϊ�գ���ʾ��cur->parentΪ���ڵ�������Ѿ����������
			//��ʱ��������Ѱ��cur����parent���Һ��ӵĸ��׽ڵ�
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_right == cur)
			{
				cur = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}

		return *this;
	}

	Self operator ++(int)//����
	{
		assert(_node != nullptr);

		Self rnode= _node;//��ʽ����ת��

		// �������һ��
		if (_node->_right)//�ҽڵ㲻Ϊ�գ���һ��λ�þ�Ϊ����������ڵ�
		{
			// ����������ڵ�
			Node* cur = _node->_right;
			while (cur && cur->_left)
			{
				cur = cur->_left;
			}

			_node = cur;
		}
		else
		{
			//�ұ�Ϊ�գ���ʾ��cur->parentΪ���ڵ�������Ѿ����������
			//��ʱ��������Ѱ��cur����parent���Һ��ӵĸ��׽ڵ�
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && parent->_right == cur)
			{
				cur = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}

		return rnode;
	}

	Self operator--()
	{
		if (_node == nullptr)//Ϊ���սڵ�
		{

		}

		else if (_node->_left != nullptr)
		{
			_node = _node->_left;
		}
		else//Ѱ�Һ��Ӳ��Ǹ�����ڵ�ĸ���
		{
			Node *cur = _node;
			Node *parent = cur->_parent;
			while (parent&&parent->_left == cur)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}

	Self operator--(int)//���ü���
	{
		Self rnode = _node;

		if (_node->_left != nullptr)
		{
			_node = _node->_left;
		}
		else//Ѱ�Һ��Ӳ��Ǹ�����ڵ�ĸ���
		{
			Node *cur = _node;
			Node *parent = cur->_parent;
			while (parent&&parent->_left == cur)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}

		return rnode;
	}

	bool operator!=(const Self &s)const 
	{
		return _node != s._node;
	}

	bool operator==(const Self &s)const 
	{
		return _node == s._node;
	}
};



//set<K> -> RVTree<K,K>
//map<K,V> -> RBTree<K,pair<const K,V>>

template<class K,class T,class KeyofT>  
//��T��K��ʱ�򣬴����ڵ�ľ���K-> set����K��pair��ʱ�򣬴����ڵ��ʱ�����pair ->map
//find��Ҫ��Kֵȥ���ң������дK��set֪��k��ʲô��map����֪��
class RBTree
{
	typedef RBTreeNode<T> Node;

public:
	typedef RBTreeIterator<T, T&, T*> Iterator;
	typedef RBTreeIterator<T, const T&, const T*> ConstIterator;

	Iterator begin()//����ߵĽڵ�
	{
		Node *cur = _root;
		while (cur&&cur->_left)
		{
			cur = cur->_left;
		}
		return  cur;//��ʽ����ת��
	}

	Iterator end()//ǰ�պ�����
	{
		return nullptr;
	}

	ConstIterator begin() const //����ߵĽڵ�
	{
		Node *cur = _root;
		while (cur&&cur->_left)
		{
			cur = cur->_left;
		}
		return  Iterator(cur);
	}

	ConstIterator end() const //ǰ�պ�����
	{
		return Iterator(nullptr);
	}



	void RotateL(Node *parent)//����
	{
		Node *subR = parent->_right;//����,p���ұ�һ����Ϊ��
		Node *subL = subR->_left;//����Ϊ��
		Node *pparent = parent->_parent;

		//��subR���ڵ����ӵ�p���Ҳ�
		parent->_right = subL;
		if (subL != nullptr)
			subL->_parent = parent;

		//��p���ӵ�subR�����
		subR->_left = parent;
		parent->_parent = subR;
		
		//subR��pp������
		subR->_parent = pparent;
		if (pparent == nullptr)
			_root = subR;
		else
		{
			if (pparent->_left == parent)
				pparent->_left = subR;
			else
				pparent->_right = subR;
		}

		//��ɫ����
		parent->_col = RED;
		subR->_col = BLACK;

	}

	void RotateR(Node *parent)//����
	{
		Node *subL = parent->_left;
		Node *subR = subL->_right;
		Node *pparent = parent->_parent;

		parent->_left = subR;
		if (subR != nullptr)
			subR->_parent = parent;

		subL->_right = parent;
		parent->_parent = subL;

		subL->_parent = pparent;
		if (pparent == nullptr)
			_root = subL;
		else
		{
			if (pparent->_left == parent)
				pparent->_left = subL;
			else
				pparent->_right = subL;
		}

		//��ɫ����
		parent->_col = RED;
		subL->_col = BLACK;

	}

	pair<Node*, bool> Insert(const T &t)
	{
		KeyofT kot;

		if (_root == nullptr)
		{
			_root = new Node(t);
			_root->_col = BLACK;
			return make_pair(_root, true);
		}

		//�и��ڵ���
			Node *parent = nullptr;
			Node *cur = _root;

			while (cur)
			{
				if (kot(cur->_t) < kot(t))//���ұ���
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (kot(cur->_t) > kot(t))//�������
				{
					parent = cur;
					cur = cur->_left;
				}
				else//��ȣ���ȥ��
				{
					return make_pair(cur, false);
				}

			}

			//��ʱ���нڵ�Ĳ���
			cur = new Node(t);
			Node* newnode = cur;//����һ�ݣ�������

			if (kot(parent->_t) > kot(t))//�����
			{
				parent->_left = cur;
				cur->_parent = parent;
			}
			else//���ұ�
			{
				parent->_right = cur;
				cur->_parent = parent;
			}

			//�����ɫ�Ľڵ㣬ά������-�����ڽڵ㲻��ͬ���Ǻ�ɫ

			while (parent&&parent->_col == RED)//���׽ڵ㲻Ϊ�գ�����Ϊ��ɫ��˵����ʱ��Ҫ���е���
			{
				Node *grandfather = parent->_parent;//���׽ڵ������Ϊ��ɫ����ôһ�����Ǹ��ڵ�

					Node *uncle = grandfather->_right;
					if (grandfather->_right == parent)//���׽ڵ�Ϊ�ң�������ڵ�Ϊ��
						uncle = grandfather->_left;

					if (uncle != nullptr&&uncle->_col == RED)//���1������ڵ������Ϊ��ɫ
					{
						//��ɫ����
						parent->_col = BLACK;
						uncle->_col = BLACK;
						grandfather->_col = RED;

						//���������ж�
						cur = grandfather;//�µĺ�ڵ�
						parent = cur->_parent;//
					}
					else//����ڵ㲻���ڣ����ߴ���Ϊ��ɫ
					{
						if (grandfather->_left == parent)//p��g�����
						{
							if (cur == parent->_left)//c��p����ֻ࣬��Ҫ��������
							{
								RotateR(grandfather);
							}
							else//c��p���Ҳ࣬��������
							{
								RotateL(parent);
								RotateR(grandfather);
							}
						}
						else//p��g���Ҳ�
						{
							if (cur == parent->_right)//c��p���Ҳ࣬����
							{
								RotateL(grandfather);
							}
							else//����������
							{
								RotateR(parent);
								RotateL(grandfather);
							}
						}
						break;//��ת֮�������Ҫ�󣬲���Ҫ�ٽ����ж�
					}
			}

		_root->_col = BLACK;//��ֹ���ڵ㱻�ĳɺ�ɫ�����ڵ㸳���ɫ��ÿ��·���϶������õ�
		return make_pair(newnode, true);
	}

	//[]����

	Iterator operator[] (const T &t)//string��int��vector�ȵȶ�������V������Ĭ�ϵĹ��캯���� int()=0
	{
		//insert���ص���pair<node*,bool>
		return Insert(t).first;//����node*�ĵ�����
	}


private:
	Node *_root = nullptr;

};