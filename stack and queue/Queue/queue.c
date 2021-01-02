#include "queue.h"

void QueueInit(Queue *q)//初始化
{
	assert(q);
	q->_front = q->_rear = NULL;
}

void QueueDestory(Queue *q)//销毁
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
void QueuePush(Queue *q, QDataType data)//入队
{
	QNode *node = (QNode*)malloc(sizeof(QNode));
	assert(node);

	node->_data = data;
	node->_next = NULL;

	if (q->_front == NULL)//第一个
	{
		q->_front = q->_rear = node;
	}
	else
	{
		q->_rear->_next = node;
		q->_rear = node;
	}

}
void QueuePop(Queue *q)//出队
{
	assert(q);
	assert(q->_front);

	QNode *next = q->_front->_next;
	free(q->_front);
	q->_front = next;

	if (q->_front == NULL)
		q->_rear = NULL;//队为空

}
QDataType QueueFront(Queue *q)//获取队首元素
{
	assert(q);
	assert(q->_front);
	return q->_front->_data;
}
QDataType QueueBack(Queue *q)//获取队尾元素
{
	assert(q);
	assert(q->_rear);
	return q->_rear->_data;
}
int QueueSize(Queue *q)//获取元素个数
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
int QueueEmpty(Queue *q)//判断是否为空
{
	assert(q);
	if (q->_front == NULL)
		return 1;
	else
		return 0;
}