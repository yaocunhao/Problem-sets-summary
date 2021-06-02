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


template<class T>//节点只提供一个T(V)值，构成set和map共用一颗红黑树
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

//迭代器的封装
template<class T, class Ref, class Ptr>
struct RBTreeIterator
{
	typedef RBTreeIterator<T, Ref, Ptr> Self;//迭代器++  还是迭代器
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
		return &(_node->_t);//返回的是节点的指针的引用，编译器优化了一次箭头
	}

	Self operator ++()//找中序的下一个
	{
		assert(_node != nullptr);

		// 中序的下一个
		if (_node->_right)//右节点不为空，下一个位置就为右树的最左节点
		{
			// 右树的最左节点
			Node* cur = _node->_right;
			while (cur && cur->_left)
			{
				cur = cur->_left;
			}

			_node = cur;
		}
		else
		{
			//右边为空，表示以cur->parent为根节点的树，已经访问完毕了
			//此时再向上搜寻，cur不是parent的右孩子的父亲节点
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

	Self operator ++(int)//后置
	{
		assert(_node != nullptr);

		Self rnode= _node;//隐式类型转换

		// 中序的下一个
		if (_node->_right)//右节点不为空，下一个位置就为右树的最左节点
		{
			// 右树的最左节点
			Node* cur = _node->_right;
			while (cur && cur->_left)
			{
				cur = cur->_left;
			}

			_node = cur;
		}
		else
		{
			//右边为空，表示以cur->parent为根节点的树，已经访问完毕了
			//此时再向上搜寻，cur不是parent的右孩子的父亲节点
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
		if (_node == nullptr)//为最后空节点
		{

		}

		else if (_node->_left != nullptr)
		{
			_node = _node->_left;
		}
		else//寻找孩子不是父亲左节点的父亲
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

	Self operator--(int)//后置减减
	{
		Self rnode = _node;

		if (_node->_left != nullptr)
		{
			_node = _node->_left;
		}
		else//寻找孩子不是父亲左节点的父亲
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
//当T是K的时候，传给节点的就是K-> set，当K是pair的时候，传给节点的时候就是pair ->map
//find需要用K值去查找，如果不写K，set知道k是什么，map并不知道
class RBTree
{
	typedef RBTreeNode<T> Node;

public:
	typedef RBTreeIterator<T, T&, T*> Iterator;
	typedef RBTreeIterator<T, const T&, const T*> ConstIterator;

	Iterator begin()//最左边的节点
	{
		Node *cur = _root;
		while (cur&&cur->_left)
		{
			cur = cur->_left;
		}
		return  cur;//隐式类型转换
	}

	Iterator end()//前闭后开区间
	{
		return nullptr;
	}

	ConstIterator begin() const //最左边的节点
	{
		Node *cur = _root;
		while (cur&&cur->_left)
		{
			cur = cur->_left;
		}
		return  Iterator(cur);
	}

	ConstIterator end() const //前闭后开区间
	{
		return Iterator(nullptr);
	}



	void RotateL(Node *parent)//左旋
	{
		Node *subR = parent->_right;//左旋,p的右边一定不为空
		Node *subL = subR->_left;//可能为空
		Node *pparent = parent->_parent;

		//将subR左侧节点链接到p的右侧
		parent->_right = subL;
		if (subL != nullptr)
			subL->_parent = parent;

		//将p链接到subR的左侧
		subR->_left = parent;
		parent->_parent = subR;
		
		//subR与pp的链接
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

		//颜色更改
		parent->_col = RED;
		subR->_col = BLACK;

	}

	void RotateR(Node *parent)//右旋
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

		//颜色更改
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

		//有根节点了
			Node *parent = nullptr;
			Node *cur = _root;

			while (cur)
			{
				if (kot(cur->_t) < kot(t))//往右边走
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (kot(cur->_t) > kot(t))//往左边走
				{
					parent = cur;
					cur = cur->_left;
				}
				else//相等，，去重
				{
					return make_pair(cur, false);
				}

			}

			//此时进行节点的插入
			cur = new Node(t);
			Node* newnode = cur;//保存一份，返回用

			if (kot(parent->_t) > kot(t))//在左边
			{
				parent->_left = cur;
				cur->_parent = parent;
			}
			else//在右边
			{
				parent->_right = cur;
				cur->_parent = parent;
			}

			//插入红色的节点，维护规则-》相邻节点不能同样是红色

			while (parent&&parent->_col == RED)//父亲节点不为空，并且为红色，说明此时需要进行调整
			{
				Node *grandfather = parent->_parent;//父亲节点存在且为红色，那么一定不是根节点

					Node *uncle = grandfather->_right;
					if (grandfather->_right == parent)//父亲节点为右，则叔叔节点为左
						uncle = grandfather->_left;

					if (uncle != nullptr&&uncle->_col == RED)//情况1：叔叔节点存在且为红色
					{
						//颜色更改
						parent->_col = BLACK;
						uncle->_col = BLACK;
						grandfather->_col = RED;

						//继续向上判断
						cur = grandfather;//新的红节点
						parent = cur->_parent;//
					}
					else//叔叔节点不存在，或者存在为黑色
					{
						if (grandfather->_left == parent)//p在g的左侧
						{
							if (cur == parent->_left)//c在p的左侧，只需要进行右旋
							{
								RotateR(grandfather);
							}
							else//c在p的右侧，先左再右
							{
								RotateL(parent);
								RotateR(grandfather);
							}
						}
						else//p在g的右侧
						{
							if (cur == parent->_right)//c在p的右侧，左旋
							{
								RotateL(grandfather);
							}
							else//先右再左旋
							{
								RotateR(parent);
								RotateL(grandfather);
							}
						}
						break;//旋转之后即完成了要求，不需要再进行判断
					}
			}

		_root->_col = BLACK;//防止根节点被改成红色，根节点赋予黑色，每条路径上都是适用的
		return make_pair(newnode, true);
	}

	//[]重载

	Iterator operator[] (const T &t)//string、int、vector等等都可以是V，是由默认的构造函数的 int()=0
	{
		//insert返回的是pair<node*,bool>
		return Insert(t).first;//返回node*的迭代器
	}


private:
	Node *_root = nullptr;

};