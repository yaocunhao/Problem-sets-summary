#pragma once
using namespace std;
#include <iostream>
#include <map>
#include <string>
#include "assert.h"
#include <stdlib.h>
#include <vector>

template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode(const pair<K, V>& kv=pair<K,V>())
	:_left(nullptr)
	,_right(nullptr)
	, _parent(nullptr)
	, _bf(0)
	, _kv(kv)
	{}

	AVLTreeNode<K, V>*_left;
	AVLTreeNode<K, V>*_right;
	AVLTreeNode<K, V>*_parent;
	pair<K, V> _kv;
	int _bf;//ƽ������
};

template <class K,class V>
class AVLTree
{
public:
	typedef struct AVLTreeNode<K,V> Node;
private:
	//��ת������д
	void RotateR(Node *parent)
	{
		Node *subL = parent->_left;//��ʱp->bf=-2����߿϶���Ϊ��
		Node *subLR = subL->_right;
		Node *pparent = parent->_parent;//����һ��

		//���������ӵ�parent�����
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		//��parent���ӵ�subL���Ҳ�
		subL->_right = parent;
		parent->_parent = subL;

		//��subL��ppretn��������
		if (pparent == nullptr)//subL����µĸ�
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else//��Ϊ��
		{
			subL->_parent = pparent;
			if (parent == pparent->_left)//����һ���ڵ�����
			{
				pparent->_left = subL;
			}
			else
			{
				pparent->_right = subL;
			}
		}

		//ƽ�����ӵĸ���
		parent->_bf = 0;
		subL->_bf = 0;

	}

	void RotateL(Node *parent)//����
	{
		Node *subR = parent->_right;//�ұ�ߣ�������Ϊ��
		Node *subRL = subR->_left;
		Node *pprent = parent->_parent;
		
		//subL���ӵ�parent��
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		//parent���ӵ�subR����
		subR->_left = parent;
		parent->_parent = subR;

		//subR���ӵ�pprent��
		if (pprent == nullptr)//��
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else//��Ϊ��
		{
			subR->_parent = pprent;
			//�ж���������һ��
			if (pprent->_left == parent)
			{
				pprent->_left = subR;
			}
			else
			{
				pprent->_right = subR;
			}
		}

		//ƽ�����ӵĸ���
		parent->_bf = subR->_bf = 0;
	}

	void RotateLR(Node *parent)
	{
		Node *subL = parent->_left;
		Node *subLR = subL->_right;//��ʱ������Ϊ�գ���Ϊ��������

		int bf = subLR->_bf;//����һ��ƽ������

		RotateL(subL);//������
		RotateR(parent);//������

		//�����������Ὣƽ������ȫ�������0�����Ҫ��ƽ�����ӽ��и���

		if (bf == 1)//��subLR���Ҳ����
		{
			subLR->_bf = 0;
			subL->_bf = -1;
			parent->_bf = 0;
		}
		else if(bf==-1)//��subLR������
		{
			subLR->_bf = 0;
			subL->_bf = 1;
			parent->_bf = 1;
		}
		else//bf==0,������
		{
			subLR->_bf = subL->_bf = parent->_bf = 0;
		}
	}

	void RotateRL(Node *parent)
	{
		Node *subR = parent->_right;
		Node *subRL = subR->_left;

		int bf = subRL->_bf;

		RotateR(subR);//������
		RotateL(parent);//������

		//ƽ�����ӳ���

		if (bf == 1)//��subRL�Ҳ����ʱ
		{
			subRL->_bf = 0;
			parent->_bf = -1;
			subR->_bf = 0;
		}
		else if(bf==-1)//��������ʱ
		{
			subRL->_bf = 0;
			parent->_bf = 0;
			subR->_bf = 1;
		}
		else//bf==0,������
		{
			subRL->_bf = parent->_bf = subR->_bf = 0;
		}
	}

public:

//���뺯��
	pair<Node*, bool> Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return make_pair(_root,true);
		}

			//�и��ˣ�����ƽ��������ķ������в���
			Node *parent = nullptr;
			Node *cur = _root;
			while (cur)
			{
				if (kv.first<cur->_kv.first)//Kֵ�Ƚϣ�С���������
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (kv.first>cur->_kv.first)//������
				{
					parent = cur;
					cur = cur->_right;
				}
				else//���,��������Ԫ�ص�ָ��
				{
					return make_pair(cur, false);
				}
			}


			//��ʱ�Ѿ��ҵ������λ����,�жϲ�������߻��ǲ������ұ�
			cur = new Node(kv);
			if (parent->_kv.first > kv.first)//�������
			{
				parent->_left = cur;
				cur->_parent = parent;//��ָ
			}
			else//�����ұ�
			{
				parent->_right = cur;
				cur->_parent = parent;
			}

			//����ƽ������
			Node *newnode = cur;//cur�ᷢ���ı�

			while (parent)//��Ϊ��
			{
				if (parent->_left == cur)//cur��parent���
				{
					parent->_bf--;
				}
				else//�Ҳ�
				{
					parent->_bf++;
				}

				if (parent->_bf == 0)//��ǰ����ƽ���
					break;
				else if (abs(parent->_bf) == 1)//������������
				{
					cur = parent;
					parent = parent->_parent;
				}
				else if (abs(parent->_bf) == 2)//��Ҫ������ת����
				{
					if (parent->_bf == -2)//��߸�
					{
						if (cur->_bf == -1)//���ڵ�ǰ�ڵ���������˽ڵ� ->�ҵ���
						{
							RotateR(parent);
						}
						else//cur->_bf=1 ->����Ӱ��
						{
							RotateLR(parent);
						}
					}
					else//�ұ߸�
					{
						if (cur->_bf == 1)//�ڵ�ǰ�ڵ���Ҳ�����˽ڵ� ->  ����
						{
							RotateL(parent);
						}
						else//cur->_bf=-1 ����Ӱ��
						{
							RotateRL(parent);
						}
					}
					break;//��ת����ǰ��������ƽ����ˣ������˳�
				}
				else//0 1 2 -> �������ߵ���һ�����ߵ�����˵���������߼�����
				{
					assert(false);
				}
			}
			return make_pair(newnode, true);//�ŵ�����Ż�����Ϊ��Ҫ����ƽ������
	}


private:
	//������ʱ�� rootΪprivate�����޷��õ�
	//�����Ҫ��װһ��
	void _Inorder(Node *root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout << root->_kv.first << " " << root->_kv.second << endl;
		_Inorder(root->_right);
	}

public:
	//����
	void Inorder()
	{
		_Inorder(_root);
	}

	Node* Find(const K &k)
	{
		Node *cur = _root;
		while (cur)
		{
			if (cur->_kv.first > k)
				cur = cur->_left;
			else if (cur->_kv.first < k)
				cur = cur->_right;
			else
				return cur;
		}
		return false;
	}


	V &operator [] (const K &k)//string��int��vector�ȵȶ�������V������Ĭ�ϵĹ��캯���� int()=0
	{
		//���뺯�����ص���pair<node*,bool>
		return (((Insert(make_pair(k, V()))).first)->_kv).second;//���ص������ã��ǿ����޸ĵ�

	}	

	//��֤�Ƿ���ƽ����

private:
	int _Isbalance(Node* root)//���ú�������ķ�ʽ��֤
	{
		if (root == nullptr)
			return 0;

		int left = _Isbalance(root->_left);
		int right = _Isbalance(root->_right);
		cout << root->_bf << " "<<endl;

		if (abs(root->_bf)>1||left==-1||right==-1||abs(left - right) > 1)//��������������-1
			return -1;

		return (int)fmax(left, right) + 1;//�����������ص�ǰ�߶�
	}

public:

	bool Isbalance()
	{
		if (_Isbalance(_root) == -1)
			return false;
		else
			return true;
	}


private :
	Node *_root = nullptr;
};