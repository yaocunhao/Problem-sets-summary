#include"binary.h"


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
		*root = NULL;
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
		return BinaryTreeFind(root->_right,x);
}
void *BinaryTreePrveOrder(BTNode *root)//二叉树前序遍历
{


}
//void *BinaryTreeInOrder(BTNode *root);//二叉树中序遍历
//void *BinaryTreePostOrder(BTNode *root);//二叉树后序遍历
//void BinaryTreeLevelOrder(BTNode *root);//层序遍历
//int  BinaryTreeComplete(BTNode *root);//判断二叉树是否完全二叉树
