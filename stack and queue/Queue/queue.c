#include "queue.h"

void QueueInit(Queue *q)//队列的初始化
{
	q->front = q->rear = 0;//开始时，队列为空
}

QNode * CreatNode(DataType data)//开辟节点
{
	QNode *node = (QNode *)malloc(sizeof(QNode));
	if (node == NULL)//节点开辟失败
		exit(-1);

	node->data = data;
	node->next = NULL;
	return node;
}

void Queuepush(Queue *q,DataType data)//入队
{
	QNode *node = CreatNode(data);

	if (q->front == NULL)//队列为空
		q->front = q->rear = node;
	else
	{
		q->rear->next = node;
		q->rear = node;
	}
}

void QueuePop(Queue *q)//出队
{
	if (q->front == NULL)//列表为空
	{
		return;
	}
	QNode *next = q->front->next;//头节点的后一个
	free(q->front);
	q->front = next;

	if (q->front == NULL)//删除之后为空表
		q->rear = NULL;

}

DataType QueueFront(Queue *q)//获得头部元素
{
	if (q->front == NULL)
		exit(-1);

	return q->front->data;
}

DataType QueueBack(Queue *q)//获得队列尾部元素
{
	if (q->front == NULL)
		exit(-1);
	
	return q->rear->data;
}

DataType QueueSize(Queue *q)//获取队列中的元素的个数
{
	int size = 0;
	QNode *cur = q->front;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}

int QueueEmpty(Queue *q)//判断链表是否为空
{
	if (q->front == NULL)
		return 1;
	return 0;
}

void QueueDestry(Queue *q)//销毁列表
{
	if (q->front == NULL);
	return;

	free(q->front);
	q->front = q->rear = NULL;
}