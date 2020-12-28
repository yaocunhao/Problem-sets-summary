#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <windows.h>

typedef int DataType;


typedef struct QListNode//���нڵ�
{
	struct QListNode *next;
	DataType data;

} QNode;

typedef struct Queue//����ָ��
{
	QNode *front;
	QNode *rear;
}Queue;

void QueueInit(Queue *q);//��ʼ������
QNode *CreatNode(DataType data);
void Queuepush(Queue *q, DataType data);//���
void QueuePop(Queue *q);//����
DataType QueueFront(Queue *q);//��ö���ͷ��Ԫ��
DataType QueueBack(Queue *q);//��ȡ����β��Ԫ��
int QueueSize(Queue *q);//��ȡ��������ЧԪ�صĸ���
int QueueEmpty(Queue *q);//�ж϶����Ƿ�Ϊ��
void QueueDestroy(Queue *q);//���ٶ���




#endif