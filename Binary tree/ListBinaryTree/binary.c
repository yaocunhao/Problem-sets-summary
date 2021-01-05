#include"binary.h"


//ͨ��ǰ����������� ABD##E#H##CF##G##


BTNode *BinaryTreeCreate(BTDataType *a, int *idx)//ǰ�򹹽�������
{
	if (a[*idx] == '#')
	{
		return NULL;
	}

	BTNode *root = (BTNode*)malloc(sizeof(BTNode));
	root->_data = a[*idx];//�������ҽڵ�
	(*idx)++;
	root->_left = BinaryTreeCreate(a, idx);
	(*idx)++;
	root->_right = BinaryTreeCreate(a, idx);

	return root;
}
void BinaryTreeDestory(BTNode **root)//������������
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
int BinaryTreeSize(BTNode *root)//�������ڵ����
{
	if (root == NULL)
		return 0;
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}
int BinaryTreeLeafSize(BTNode *root)//������Ҷ�ӽڵ����
{
	if (root == NULL)
		return 0;
	if (root->_left == NULL&&root->_right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
int BinaryTreeLevelKSize(BTNode *root, int k)//��K��ڵ����
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
BTNode *BinaryTreeFind(BTNode *root, BTDataType x)//����������ֵΪx�Ľڵ�
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
void *BinaryTreePrveOrder(BTNode *root)//������ǰ�����
{


}
//void *BinaryTreeInOrder(BTNode *root);//�������������
//void *BinaryTreePostOrder(BTNode *root);//�������������
//void BinaryTreeLevelOrder(BTNode *root);//�������
//int  BinaryTreeComplete(BTNode *root);//�ж϶������Ƿ���ȫ������
