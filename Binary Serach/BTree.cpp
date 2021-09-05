template<class K,class V, size_t M>//K/V值，和阶数M

struct BTreeNode //定义节点
{
	//孩子数量比关键字多1
	//pait<K, V> _kvl[M - 1];//关键字
	//BTreeNode<K, V, M> *_child[M]; //孩子

	//多给一个空间，可以先插入，再分裂
	pair<K, V> _kvl[M];//关键字
	BTreeNode<K, V, M> *_child[M+1]; //孩子数组

	BTreeNode<K, V, M> *_parent;//父指针
	size_t _kvsize;//记录存储了多少个关键字

	BTreeNode()
		:_parent(nullptr)
		, _kvsize (0)
	{
		for (int i = 0; i < M + 1; i++)
		{
			_child[i] = nullptr;//创建一个新节点，孩子节点全部置为空
		}
	}
};

template<class K, class  V,  size_t M>
class BTree
{
	typedef BTreeNode<K, V, M> Node;

public:

	//第i个key的左孩子是child[i]
	//右孩子是child[i+1]
	pair<Node*, int> Find(const K& key)
	{
		Node *parent = nullptr;
		Node *cur = _root; //从根节点开始搜索
		while (cur)
		{
			size_t i = 0;
			//寻找当前节点当中的关键字
			while (i < cur->_kvsize) //如果M比较大，换成二分查找
			{
				if (cur->_kvl[i].first < key)//key大于当前位置，往右边找
					i++;
				else if (cur->_kvl[i].first>key)//key小于当前位置，往左孩子找
					break;
				else
					return make_pair(cur, i);//找到了，返回即可
			}
			//来到这里，要么当前节点的所有关键字都小于key，要么当前节点中有大于key的关键字
			//即需要继续往孩子节点中进行搜索

			parent = cur;//往下一层走之前，记录父亲
			//假设key小于所有的关键字，那么去右孩子中进行寻找,此时i++已经来到下一位置 -> child[i]
			//假设key大于某个关键字，那么需要去该关键字的左孩子寻找 ,此时直接退出循环，因此正是i位置-> child[i]
			cur = cur->_child[i];
		}
		//没有找到
		return make_pair(parent, -1);//返父亲指针
	}


	//在cur节点之中，插入kv,和孩子节点
	void InsertKv(Node* cur,const pair<K, V> &kv,Node* brother)
	{
		//从后往前寻找
		size_t i = cur->_kvsize;
		for (i; i > 0; i--)
		{
			if (kv.first > cur->_kvl[i-1].first)//插入的关键字，大于前面的关键字，说明是插在此位置
			{
				break;
			}
			//插入关键字小于前面的位置，则将前面的位置往后挪，同时孩子节点也需要挪动
			cur->_kvl[i] = cur->_kvl[i - 1];
			cur->_child[i+1] = cur->_child[i];//孩子的下标比关键字大1
		}
		//填入关键字，和孩子节点
		cur->_kvl[i] = kv;
		cur->_child[i+1] = brother;
		cur->_kvsize++;//关键字数量自增
	}

	//插入一个关键字
	//先找到对应的位置，然后插入
	//如果当前key值已经存在则不能插入
	//key不存在，插入到叶子节点之中，因此在插入的时候，需要找到叶子节点
	bool Insert(const pair<K, V> &kv)
	{
		if (_root == nullptr)//根节点为空
		{
			_root = new Node;
			_root->_kvl[0] = kv;//填入当前关键字
			_root->_kvsize = 1;//关键字++
			return true;
		}

		//根不为空
		//根不为空时，先查找，如果找到了，则不被允许插入
		pair<Node*, int> ret = Find(kv.first);

		if (ret.second >= 0)//表示当前已经存在,不可插入
		{
			return false;
		}

		//没有找到，可以进行插入
		//此时的ret.first表示可以插入的节点

		Node* cur = ret.first;//获取插入的位置
		//在cur中，插入值kv,此时不需要填入兄弟节点
		InsertKv(cur, kv,nullptr);

		//有可能需要进行分裂处理
		while (1)
		{
			if (cur->_kvsize < M)//当前节点没有满，直接返回成功即可
			{
				return true;
			}
			else//当前节点满了
			{
				//分裂出一个兄弟节点
				Node *brother = new Node;

				//[0,mid-1]位置的关键字留给原来的节点
				//[mid+1,M-1]位置的关键字拷贝给兄弟节点
				int mid = cur->_kvsize / 2;

				//拷贝一半的数据给兄弟节点
				size_t sub = 0;
				for (int i = mid + 1; i < cur->_kvsize; i++)
				{
					brother->_kvl[sub++] = cur->_kvl[i];//拷贝关键字
					brother->_kvsize++;//关键字总数++
				}

				//在向上分裂的过程之中，如果有孩子节点，则需要拷贝孩子节点
				//原来的保留[0,mid]的孩子
				//兄弟节点拷贝[mid+1,size]的孩子
				sub = 0;
				for (int i = mid + 1; i <= cur->_kvsize; i++)
				{
					if (cur->_child[i] == nullptr)//没有孩子了
						break;

					brother->_child[sub++] = cur->_child[i];
					cur->_child[i]->_parent = brother;//更新父节点
					cur->_child[i] = nullptr;
				}

				//原来节点留下的关键字数量=原来的-兄弟中的-交付给根节点的
				cur->_kvsize = cur->_kvsize - brother->_kvsize - 1;

				//将mid处位置的值，放入父节点之中
				//1.如果没有父节点，则需要创建根节点
				//2.如果有父节点，往父节点中插入mid位置的关键字

				if (cur->_parent == nullptr)//没有父节点
				{
					//创建父节点，并且将关键字填入
					_root = new Node;
					_root->_kvl[0] = cur->_kvl[mid];
					_root->_kvsize++;

					//填入孩子节点
					_root->_child[0] = cur;
					_root->_child[1] = brother;

					//填入父节点指针
					cur->_parent = _root;
					brother->_parent = _root;

					return true;
				}
				else//有父亲节点，再次调用插入即可
				{
					pair<K, V> kv = cur->_kvl[mid];//获取需要插入的值
					cur = cur->_parent;//cur变为父节点
					InsertKv(cur, kv,brother);//往父节点中插入kv和孩子节点(当前的brother节点)
					brother->_parent = cur;//填入父指针
				}
			}
		}
	}

	//中序遍历，输出的数是升序的
	void _Inorder(Node *root)
	{
		if (root == nullptr)
			return;

		size_t i = 0;
		while (i < root->_kvsize)
		{
			_Inorder(root->_child[i]);//先输出左边
			cout << root->_kvl[i].first << " ";//再输出当前位置
			i++;
		}
		_Inorder(root->_child[i]);//输出右边
	}

	void Inorder()
	{
		_Inorder(_root);
	}

private:
	Node *_root = nullptr;
};