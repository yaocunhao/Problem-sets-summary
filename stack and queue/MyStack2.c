//�ö���ʵ��ջ

//����1 �������н���ʵ�֡�
typedef int DataType;
typedef struct QListNode
{
	DataType data;
	struct QListNode *next;

}QNode;

typedef struct Queue
{
	QNode *front;
	QNode *rear;
}Queue;


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

void Queuepush(Queue *q, DataType data)//���
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

typedef struct {
	Queue q;//����һ�����У�

} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack *ms = (MyStack *)malloc(sizeof(MyStack));
	QueueInit(&ms->q);//��ʼ������
	return ms;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	Queuepush(&obj->q, x);//�����
	int size = QueueSize(&obj->q);
	while (size>1)//��size��Ԫ�س������size-1�Σ���һ��Ԫ�ر�Ϊ���һ��Ԫ��
	{
		int front = QueueFront(&obj->q);//���ͷ��Ԫ��
		QueuePop(&obj->q);//����
		Queuepush(&obj->q, front);//�����
		size--;
	}

}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	int ret = QueueFront(&obj->q);
	QueuePop(&obj->q);
	return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	return QueueFront(&obj->q);

}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q);
}

void myStackFree(MyStack* obj) {
	QueueDestry(&obj->q);
}


//����2 ˫����ʵ��
typedef int DataType;
typedef struct QListNode
{
	DataType data;
	struct QListNode *next;

}QNode;

typedef struct Queue
{
	QNode *front;
	QNode *rear;
}Queue;


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

void Queuepush(Queue *q, DataType data)//���
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
	while (q->front)
	{
		QNode *temp = q->front->next;
		free(q->front);
		q->front = temp;
	}
	q->front = q->rear = NULL;
}

typedef struct {
	Queue first_q;//�������У�
	Queue second_q;

} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack *ms = (MyStack *)malloc(sizeof(MyStack));
	QueueInit(&ms->first_q);//��ʼ������
	QueueInit(&ms->second_q);
	return ms;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	//�Ƚ�����1��Ԫ��ȫ����ӵ�����2֮��
	int size = QueueSize(&obj->first_q);
	while (size)
	{
		int front = QueueFront(&obj->first_q);//���һ��Ԫ��
		QueuePop(&obj->first_q);//����
		Queuepush(&obj->second_q, front);//�����2
		size--;
	}
	Queuepush(&obj->first_q, x);//�����2
	size = QueueSize(&obj->second_q);
	while (size)//�ٶ���2��Ԫ�ػص�����1
	{
		int front = QueueFront(&obj->second_q);//���һ��Ԫ��
		QueuePop(&obj->second_q);//����
		Queuepush(&obj->first_q, front);//�����1
		size--;
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	int ret = QueueFront(&obj->first_q);
	QueuePop(&obj->first_q);
	return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	return QueueFront(&obj->first_q);

}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->first_q);
}

void myStackFree(MyStack* obj) {
	QueueDestry(&obj->first_q);
	free(obj);
}