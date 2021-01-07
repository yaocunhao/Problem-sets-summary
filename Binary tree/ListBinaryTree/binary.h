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

BTNode *BinaryTreeCreate(BTDataType *root,int *pi);//����������
void BinaryTreeDestory(BTNode **root);//������������
int BinaryTreeSize(BTNode *root);//�������ڵ����
int BinaryTreeLeafSize(BTNode *root);//������Ҷ�ӽڵ����
int BinaryTreeLevelKSize(BTNode *root, int k);//��K��ڵ����
BTNode *BinaryTreeFind(BTNode *root, BTDataType x);//����������ֵΪx�Ľڵ�
void *BinaryTreePrveOrder(BTNode *root);//������ǰ�����
void *BinaryTreeInOrder(BTNode *root);//�������������
void *BinaryTreePostOrder(BTNode *root);//�������������
void BinaryTreeLevelOrder(BTNode *root);//�������
int  BinaryTreeComplete(BTNode *root);//�ж϶������Ƿ���ȫ������

#endif
