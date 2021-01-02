#include "queue.h"

void QueueInit(Queue *q)//��ʼ��
{
	assert(q);
	q->_front = q->_rear = NULL;
}

void QueueDestory(Queue *q)//����
{
	assert(q);
	QNode *cur = q->_front;
	QNode *next = NULL;
	while (cur)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}
void QueuePush(Queue *q, QDataType data)//���
{
	QNode *node = (QNode*)malloc(sizeof(QNode));
	assert(node);

	node->_data = data;
	node->_next = NULL;

	if (q->_front == NULL)//��һ��
	{
		q->_front = q->_rear = node;
	}
	else
	{
		q->_rear->_next = node;
		q->_rear = node;
	}

}
void QueuePop(Queue *q)//����
{
	assert(q);
	assert(q->_front);

	QNode *next = q->_front->_next;
	free(q->_front);
	q->_front = next;

	if (q->_front == NULL)
		q->_rear = NULL;//��Ϊ��

}
QDataType QueueFront(Queue *q)//��ȡ����Ԫ��
{
	assert(q);
	assert(q->_front);
	return q->_front->_data;
}
QDataType QueueBack(Queue *q)//��ȡ��βԪ��
{
	assert(q);
	assert(q->_rear);
	return q->_rear->_data;
}
int QueueSize(Queue *q)//��ȡԪ�ظ���
{
	assert(q);
	QNode *cur = q->_front;
	int size = 0;
	while (cur)
	{
		cur = cur->_next;
		size++;
	}
	return size;
}
int QueueEmpty(Queue *q)//�ж��Ƿ�Ϊ��
{
	assert(q);
	if (q->_front == NULL)
		return 1;
	else
		return 0;
}