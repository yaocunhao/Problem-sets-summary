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

void QueueInit(Queue *q);//��ʼ��
void QueueDestory(Queue *q);//����
void QueuePush(Queue *q,QDataType data);//���
void QueuePop(Queue *q);//����
QDataType QueueFront(Queue *q);//��ȡ����Ԫ��
QDataType QueueBack(Queue *q);//��ȡ��βԪ��
int QueueSize(Queue *q);//��ȡԪ�ظ���
int QueueEmpty(Queue *q);//�ж��Ƿ�Ϊ��







#endif