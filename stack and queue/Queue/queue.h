#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <windows.h>

typedef int DataType;


typedef struct QListNode//队列节点
{
	struct QListNode *next;
	DataType data;

} QNode;

typedef struct Queue//队列指针
{
	QNode *front;
	QNode *rear;
}Queue;

void QueueInit(Queue *q);//初始化队列
QNode *CreatNode(DataType data);
void Queuepush(Queue *q, DataType data);//入队
void QueuePop(Queue *q);//出队
DataType QueueFront(Queue *q);//获得队列头部元素
DataType QueueBack(Queue *q);//获取队列尾部元素
int QueueSize(Queue *q);//获取队列中有效元素的个数
int QueueEmpty(Queue *q);//判断队列是否为空
void QueueDestroy(Queue *q);//销毁队列




#endif