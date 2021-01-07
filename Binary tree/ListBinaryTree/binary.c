#include "binary.h"
#include "stack.h"
#include "queue.h"



//通过前序遍历的数组 ABD##E#H##CF##G##
BTNode *BinaryTreeCreate(BTDataType *a, int *idx)//前序构建二叉树
{
	if (a[*idx] == '#')
	{
		return NULL;
	}

	BTNode *root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = a[*idx];//根，左，右节点
	(*idx)++;
	root->_left = BinaryTreeCreate(a, idx);
	(*idx)++;
	root->_right = BinaryTreeCreate(a, idx);

	return root;
}
void BinaryTreeDestory(BTNode **root)//二叉树的销毁
{
	BTNode *cur = *root;
	if (cur)
	{
		BinaryTreeDestory(&cur->_left);
		BinaryTreeDestory(&cur->_right);
		free(cur);
		*root = NULL;//这里不能用cur，cur只是root的一份拷贝，不会改变外面的内容
	}
}
int BinaryTreeSize(BTNode *root)//二叉树节点个数
{
	if (root == NULL)
		return 0;
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}
int BinaryTreeLeafSize(BTNode *root)//二叉树叶子节点个数
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL&&root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
int BinaryTreeLevelKSize(BTNode *root, int k)//第K层节点个数
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
BTNode *BinaryTreeFind(BTNode *root, BTDataType x)//二叉树查找值为x的节点
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}

	BTNode *temp = BinaryTreeFind(root->_left, x);
	if (temp != NULL)
	{
		return temp;
	}
	return BinaryTreeFind(root->_right, x);
}
void BinaryTreePrveOrder(BTNode *root)//二叉树前序遍历
{
	BTNode *cur = root;
	stack st;
	StackInit(&st);

	while (cur || !StackEmpty(&st))//当前根节点不为空或者栈不为空
	{
		while (cur)
		{
			printf("%c ", cur->_data);
			StackPush(&st, cur);//入栈
			cur = cur->_left;
		}

		cur = StackTop(&st);
		cur = cur->_right;
		StackPop(&st);
	}
}
void BinaryTreeInOrder(BTNode *root)//二叉树中序遍历
{
	//左，根，右，先入栈，后出栈打印
	BTNode *cur = root;
	stack st;
	StackInit(&st);

	while (cur || !StackEmpty(&st))
	{
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		cur = StackTop(&st);
		StackPop(&st);
		printf("%c ", cur->_data);
		cur = cur->_right;
	}
}
void BinaryTreePostOrder(BTNode *root)//二叉树后序遍历
{
	BTNode *cur = root;
	BTNode *prev = NULL;//标记是否访问了右子树
	stack st;
	StackInit(&st);
	while (cur || !StackEmpty(&st))
	{
		while (cur)
		{
			StackPush(&st, cur);
			cur = cur->_left;
		}
		cur = StackTop(&st);
		if (cur->_right == NULL || cur->_right == prev)//右子树为空，或者已经访问过了
		{
			StackPop(&st);
			printf("%c ", cur->_data);
			prev = cur;
			cur = NULL;
		}
		else
		{
			cur = cur->_right;
		}
	}
}
void BinaryTreeLevelOrder(BTNode *root)//层序遍历
{
	Queue q;
	QueueInit(&q);

	BTNode *cur = root;
	if (cur)
		QueuePush(&q, cur);//入队
	while (!QueueEmpty(&q))
	{
		BTNode *front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->_data);

		if (front->_left)
			QueuePush(&q, front->_left);
		if (front->_right)
			QueuePush(&q, front->_right);
	}
}
int  BinaryTreeComplete(BTNode *root)//判断二叉树是否完全二叉树
{
	BTNode *cur = root;
	Queue q;
	QueueInit(&q);
	if (cur)
		QueuePush(&q, cur);
	while (!QueueEmpty(&q))
	{
		BTNode *front = QueueFront(&q);
		QueuePop(&q);
		if (front)//如果队头不为空 
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		else//遇到空队头则停止循环
		{
			break;
		}
	}
	while (!QueueEmpty(&q))//判断剩余的队列元素是否全是空
	{
		BTNode *front = QueueFront(&q);
		if (QueueEmpty != NULL)
			return 0;
	}
	return 1;
}
