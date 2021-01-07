#include "binary.h"
#include "stack.h"
#include "queue.h"



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
		*root = NULL;//���ﲻ����cur��curֻ��root��һ�ݿ���������ı����������
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
	return BinaryTreeFind(root->_right, x);
}
void BinaryTreePrveOrder(BTNode *root)//������ǰ�����
{
	BTNode *cur = root;
	stack st;
	StackInit(&st);

	while (cur || !StackEmpty(&st))//��ǰ���ڵ㲻Ϊ�ջ���ջ��Ϊ��
	{
		while (cur)
		{
			printf("%c ", cur->_data);
			StackPush(&st, cur);//��ջ
			cur = cur->_left;
		}

		cur = StackTop(&st);
		cur = cur->_right;
		StackPop(&st);
	}
}
void BinaryTreeInOrder(BTNode *root)//�������������
{
	//�󣬸����ң�����ջ�����ջ��ӡ
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
void BinaryTreePostOrder(BTNode *root)//�������������
{
	BTNode *cur = root;
	BTNode *prev = NULL;//����Ƿ������������
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
		if (cur->_right == NULL || cur->_right == prev)//������Ϊ�գ������Ѿ����ʹ���
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
void BinaryTreeLevelOrder(BTNode *root)//�������
{
	Queue q;
	QueueInit(&q);

	BTNode *cur = root;
	if (cur)
		QueuePush(&q, cur);//���
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
int  BinaryTreeComplete(BTNode *root)//�ж϶������Ƿ���ȫ������
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
		if (front)//�����ͷ��Ϊ�� 
		{
			QueuePush(&q, front->_left);
			QueuePush(&q, front->_right);
		}
		else//�����ն�ͷ��ֹͣѭ��
		{
			break;
		}
	}
	while (!QueueEmpty(&q))//�ж�ʣ��Ķ���Ԫ���Ƿ�ȫ�ǿ�
	{
		BTNode *front = QueueFront(&q);
		if (QueueEmpty != NULL)
			return 0;
	}
	return 1;
}
