#include <iostream>
using namespace std;
#include <windows.h>
#include <string>



template<class K,class V>
struct BSTreeNode
{
	BSTreeNode(const K&key,const V&value)
	:_key(key)
	, _value(value)
	, left(nullptr)
	, right(nullptr)
	{}

	const K _key;//KV模式、key不允许修改
	V _value;
	BSTreeNode *left;
	BSTreeNode *right;
};

template<class K,class V>
class BSTree
{
	typedef BSTreeNode<K,V> Node;

public:
	bool Insert(const K &key,const V &value)
	{
		if (_root == nullptr)
		{
			_root = new Node(key,value);//构造一个根节点
			return true;
		}
		Node *parent = nullptr;
		Node *cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->left;
			}

			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->right;
			}
			else
			{
				return false;//不允许相等
			}
		}

		Node *newnode = new Node(key,value);
		if (parent->_key > key)
			parent->left = newnode;
		else
			parent->right = newnode;
		return true;	 
	}

	void _Inorder(Node *root)
	{
		if (!root)
			return;
		_Inorder(root->left);
		cout << root->_key << ":" << root->_value << " ";
		_Inorder(root->right);
	}

	//遍历需要传入根节点
	//在外面无法拿到root(private)
	//因此需要封装一层
	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}

 Node *Find(const K&key)//KV模式、value允许修改
	{
		Node *cur = _root;
		while (cur)
		{
			if (cur->_key > key)
				cur = cur->left;
			else if (cur->_key < key)
				cur = cur->right;
			else
				return cur;
		}
		return nullptr;
	}

	bool Erase(const K&key)
	{
		Node *parent = nullptr;
		Node *cur = _root;
		while (cur)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->right;
			}
			else//找到了、准备进行删除
			{
				if (cur->left == nullptr)//左子树为空
				{
					if (cur == _root)//特殊情况：删除根
					{
						_root = cur->right; 
					}
					else
					{
						if (parent->left == cur)//为父节点的左子树
						{
							parent->left = cur->right;
						}
						else if (parent->right == cur)//为父节点的右子树
						{
							parent->right = cur->right;
						}
					}
					delete cur;
				}
				else if (cur->right == nullptr)//右子树为空
				{
					if (cur == _root)//特殊情况：删除根
						_root = cur->left;
					else
					{
						if (parent->left == cur)//为父节点的左子树
						{
							parent->left = cur->left;
						}
						else if (parent->right == cur)//为父节点的右子树
						{
							parent->right = cur->left;
						}
					}
					delete cur;
				}
				else//左右子树都不为空、替代法删除
				{
					Node *smParent = cur;//不能给空、防止Submax就是根
					Node *SubMax = cur->left;//找左树的最大值
					while (SubMax->right)//不断的往右走
					{
						smParent = SubMax;
						SubMax = SubMax->right;
					}
					//找到了左树的最大节点、挪到cur处&&submax一定是右为空的节点
					cur->_key = SubMax->_key;//替代

					if (smParent->right == SubMax)//父节点右边连接
						smParent->right = SubMax->left;
					else//父节点左边连接
						smParent->left = SubMax->left;

					delete SubMax;//释放替代节点
				}
				return true;
			}

		}
		return false;//表示没有找到
	}

private:
	Node *_root=nullptr;
};