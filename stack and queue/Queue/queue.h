#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <windows.h>
#include <assert.h>

typedef int QDataType;

typedef struct QListNode
{
	QDataType _data;
	struct QListNode* _next;
}QNode;

typedef struct Queue
{
	QNode *_front;
	QNode *_rear;
}Queue;

void QueueInit(Queue *q);//初始化
void QueueDestory(Queue *q);//销毁
void QueuePush(Queue *q,QDataType data);//入队
void QueuePop(Queue *q);//出队
QDataType QueueFront(Queue *q);//获取队首元素
QDataType QueueBack(Queue *q);//获取队尾元素
int QueueSize(Queue *q);//获取元素个数
int QueueEmpty(Queue *q);//判断是否为空







#endif