#ifndef _BINART_H_
#define _BINART_H_

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType  _data;
	struct BinaryTreeNode *_left;
	struct BinaryTreeNode *_right;
}BTNode;

BTNode *BinaryTreeCreate(BTDataType *root,int *pi);//构建二叉树
void BinaryTreeDestory(BTNode **root);//二叉树的销毁
int BinaryTreeSize(BTNode *root);//二叉树节点个数
int BinaryTreeLeafSize(BTNode *root);//二叉树叶子节点个数
int BinaryTreeLevelKSize(BTNode *root, int k);//第K层节点个数
BTNode *BinaryTreeFind(BTNode *root, BTDataType x);//二叉树查找值为x的节点
void *BinaryTreePrveOrder(BTNode *root);//二叉树前序遍历
void *BinaryTreeInOrder(BTNode *root);//二叉树中序遍历
void *BinaryTreePostOrder(BTNode *root);//二叉树后序遍历
void BinaryTreeLevelOrder(BTNode *root);//层序遍历
int  BinaryTreeComplete(BTNode *root);//判断二叉树是否完全二叉树

#endif
