//用队列实现栈

//方法1 ，单队列进行实现。
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

void Queuepush(Queue *q, DataType data)//入队
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

typedef struct {
	Queue q;//创建一个队列；

} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack *ms = (MyStack *)malloc(sizeof(MyStack));
	QueueInit(&ms->q);//初始化队列
	return ms;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	Queuepush(&obj->q, x);//先入队
	int size = QueueSize(&obj->q);
	while (size>1)//有size个元素出队入队size-1次，第一个元素变为最后一个元素
	{
		int front = QueueFront(&obj->q);//获得头部元素
		QueuePop(&obj->q);//出队
		Queuepush(&obj->q, front);//再入队
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


//方法2 双队列实现
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

void Queuepush(Queue *q, DataType data)//入队
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
	while (q->front)
	{
		QNode *temp = q->front->next;
		free(q->front);
		q->front = temp;
	}
	q->front = q->rear = NULL;
}

typedef struct {
	Queue first_q;//创建队列；
	Queue second_q;

} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack *ms = (MyStack *)malloc(sizeof(MyStack));
	QueueInit(&ms->first_q);//初始化队列
	QueueInit(&ms->second_q);
	return ms;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	//先将队列1的元素全部入队到队列2之中
	int size = QueueSize(&obj->first_q);
	while (size)
	{
		int front = QueueFront(&obj->first_q);//获得一个元素
		QueuePop(&obj->first_q);//出队
		Queuepush(&obj->second_q, front);//入队列2
		size--;
	}
	Queuepush(&obj->first_q, x);//入队列2
	size = QueueSize(&obj->second_q);
	while (size)//再队列2的元素回到队列1
	{
		int front = QueueFront(&obj->second_q);//获得一个元素
		QueuePop(&obj->second_q);//出队
		Queuepush(&obj->first_q, front);//入队列1
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