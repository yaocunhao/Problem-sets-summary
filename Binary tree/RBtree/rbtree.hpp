#pragma once
#include <iostream>
using namespace std;

enum Color
{
	RED,
	BLACK
};


template<class K,class V>
struct RBTreeNode
{
	RBTreeNode(const pair<K, V>&kv)
	:_left(nullptr)
	, _right(nullptr)
	, _parent(nullptr)
	, _kv(kv)
	, _col(RED)
	{}

	RBTreeNode<K, V> *_left;
	RBTreeNode<K, V> *_right;
	RBTreeNode<K, V> *_parent;
	pair<K, V> _kv;
	enum  Color _col;
};

template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K,V> Node;

public:

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

	pair<Node*, bool> Insert(pair<K, V>&kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return make_pair(_root, true);
		}

		//有根节点了
			Node *parent = nullptr;
			Node *cur = _root;

			while (cur)
			{
				if (kv.first > cur->_kv.first)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (kv.first < cur->_kv.first)
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
			cur = new Node(kv);
			Node* newnode = cur;//保存一份，返回用

			if (parent->_kv.first > kv.first)//在左边
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

	V &operator [](const K &k)//string、int、vector等等都可以是V，是由默认的构造函数的 int()=0
	{
		//insert返回的是pair<node*,bool>

		return  ((Insert(make_pair(k, V())).first)->_kv).second;
	}


	//检测相关

	//遍历
	void _Inorder(Node *root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);

		cout << root->_kv.first << " " << root->_kv.second <<" "<<root->_col<< endl;
		_Inorder(root->_right);

	}

	void Inorder()
	{
		_Inorder(_root);
	}



	//判断是否是红黑树 ->判断一个红色节点的左右子树是否是红色的  -> 判断一个红色节点的父亲是否是红色的

	bool CheckCol(Node* root)
	{
		if (root == nullptr)
			return true;

		if (root->_col == RED)//当前节点为红色
		{
			if (root->_parent != nullptr)
			{
				if (root->_parent->_col == RED)//红色节点的父亲也为红色，则不是红黑树
				{
					cout << root->_kv.first << " " << root->_kv.second <<"颜色判断失败 ->不是红黑树"<< endl;
					return false;
				}
			}
		}

		return CheckCol(root->_left) && CheckCol(root->_right);
	}

	bool CheckBlack(Node *root,int TrueNum,int BlackNum)//统计路径上面的黑色节点
	{
		if (root == nullptr)//表示一条路径走到底了
		{
			return TrueNum == BlackNum;//判断每条路径的黑色节点是否相等
		}
		
		
		if (root->_col == BLACK)
			BlackNum++;

		return
			CheckBlack(root->_left, TrueNum, BlackNum) &&
			CheckBlack(root->_right, TrueNum, BlackNum);
	}


	bool Check()
	{
		Node *cur = _root;
		int TrueNum = 0;
		
		if (_root&&_root->_col == RED)//根不能为红色
		{
			return false;
		}

		while (cur)//统计一条路径上面的黑色节点的个数
		{
			if (cur->_col == BLACK)
				TrueNum++;
			cur = cur->_left;
		}


		return CheckCol(_root) && CheckBlack(_root, TrueNum, 0);

	}
	
private:
	Node *_root = nullptr;

};