#include "queue.h"

void QueueInit(Queue *q)//���еĳ�ʼ��
{
	q->front = q->rear = 0;//��ʼʱ������Ϊ��
}

QNode * CreatNode(DataType data)//���ٽڵ�
{
	QNode *node = (QNode *)malloc(sizeof(QNode));
	if (node == NULL)//�ڵ㿪��ʧ��
		exit(-1);

	node->data = data;
	node->next = NULL;
	return node;
}

void Queuepush(Queue *q,DataType data)//���
{
	QNode *node = CreatNode(data);

	if (q->front == NULL)//����Ϊ��
		q->front = q->rear = node;
	else
	{
		q->rear->next = node;
		q->rear = node;
	}
}

void QueuePop(Queue *q)//����
{
	if (q->front == NULL)//�б�Ϊ��
	{
		return;
	}
	QNode *next = q->front->next;//ͷ�ڵ�ĺ�һ��
	free(q->front);
	q->front = next;

	if (q->front == NULL)//ɾ��֮��Ϊ�ձ�
		q->rear = NULL;

}

DataType QueueFront(Queue *q)//���ͷ��Ԫ��
{
	if (q->front == NULL)
		exit(-1);

	return q->front->data;
}

DataType QueueBack(Queue *q)//��ö���β��Ԫ��
{
	if (q->front == NULL)
		exit(-1);
	
	return q->rear->data;
}

DataType QueueSize(Queue *q)//��ȡ�����е�Ԫ�صĸ���
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

int QueueEmpty(Queue *q)//�ж������Ƿ�Ϊ��
{
	if (q->front == NULL)
		return 1;
	return 0;
}

void QueueDestry(Queue *q)//�����б�
{
	if (q->front == NULL);
	return;

	free(q->front);
	q->front = q->rear = NULL;
}