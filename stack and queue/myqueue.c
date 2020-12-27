��ջģ����е�ʵ��

////����1��
//���ʱ��浽ջ1�����ӵ�ʱ��ȫ������ջ2��Ȼ���ٽ��в������������ٵ��뵽ջ1
//
//### ����
//
//```c
//typedef int DataType;
//typedef struct Statck
//{
//	DataType *arr;
//	int top;//ջ��
//	int capacity;//����
//
//}statck;
//void stackInit(statck *ps)//ջ�ĳ�ʼ��
//{
//	ps->arr = (DataType *)malloc(sizeof(DataType)* 2);
//	if (ps->arr == NULL)
//		return;
//	ps->top = 0;
//	ps->capacity = 2;
//}
//
//void stackpush(statck *ps, DataType data)//��ջ
//{
//	if (ps->top == ps->capacity)//����
//	{
//		DataType *newarr = (DataType *)realloc(ps->arr, sizeof(DataType)* 2 * ps->capacity);
//		if (newarr == NULL)
//			return;
//		ps->arr = newarr;
//		ps->capacity = 2 * ps->capacity;
//	}
//
//	ps->arr[ps->top] = data;
//	ps->top++;
//}
//
//void stackPop(statck *ps)//��ջ
//{
//	if (ps->top == 0)//��ջ
//		exit(-1);
//	ps->top--;
//}
//
//DataType stackTop(statck *ps)//��ȡջ��Ԫ��
//{
//	if (ps->top == 0)
//		exit(-1);
//	return ps->arr[ps->top - 1];
//}
//
//DataType stackSize(statck *ps)//��ȡԪ����Ч����
//{
//	return ps->top;
//}
//
//int stackEmpty(statck *ps)//����Ƿ�Ϊ��
//{
//	if (ps->top == 0)
//		return 1;
//	else
//		return 0;
//}
//
//void stackDestroy(statck *ps)//����
//{
//	free(ps->arr);
//	ps->top = ps->capacity = 0;
//}
//
//typedef struct {
//	statck first_s;
//	statck second_s;
//
//} MyQueue;
//
///** Initialize your data structure here. */
//
//MyQueue* myQueueCreate() {
//	MyQueue *q = (MyQueue*)malloc(sizeof(MyQueue));
//	//��ʼ������ջ
//	stackInit(&q->first_s);
//	stackInit(&q->second_s);
//	return q;
//}
//
///** Push element x to the back of queue. */
//void myQueuePush(MyQueue* obj, int x) {
//	stackpush(&obj->first_s, x);//���뵽ջ1֮��
//}
//
///** Removes the element from in front of queue and returns that element. */
//int myQueuePop(MyQueue* obj) {
//	int size = stackSize(&obj->first_s);//��ȡԪ�ظ���
//	while (size)//������ȫ��ת�Ƶ�ջ2֮��
//	{
//		int top = stackTop(&obj->first_s);
//		stackpush(&obj->second_s, top);
//		stackPop(&obj->first_s);
//		size--;
//	}
//
//	int ret = stackTop(&obj->second_s);
//	stackPop(&obj->second_s);
//
//	size = stackSize(&obj->second_s);
//	while (size)//�ٴηŻص�ջ1֮��
//	{
//		int top = stackTop(&obj->second_s);
//		stackpush(&obj->first_s, top);
//		stackPop(&obj->second_s);
//		size--;
//	}
//	return ret;
//}
//
///** Get the front element. */
//int myQueuePeek(MyQueue* obj) {
//	int size = stackSize(&obj->first_s);//��ȡԪ�ظ���
//	while (size)//������ȫ��ת�Ƶ�ջ2֮��
//	{
//		int top = stackTop(&obj->first_s);
//		stackpush(&obj->second_s, top);
//		stackPop(&obj->first_s);
//		size--;
//	}
//
//	int ret = stackTop(&obj->second_s);
//
//	size = stackSize(&obj->second_s);
//	while (size)//�ٴηŻص�ջ1֮��
//	{
//		int top = stackTop(&obj->second_s);
//		stackpush(&obj->first_s, top);
//		stackPop(&obj->second_s);
//		size--;
//	}
//	return ret;
//}
//
///** Returns whether the queue is empty. */
//bool myQueueEmpty(MyQueue* obj) {
//	if (stackEmpty(&obj->first_s))
//		return true;
//	else
//		return false;
//
//}
//
//void myQueueFree(MyQueue* obj) {
//	stackDestroy(&obj->first_s);
//	free(obj);
//}
//

//����2��
ѹ���Ԫ��ȫ��ѹ�뵽ջ1֮�У��������ջ2�е��������ջ2λ�գ���ջ1��Ԫ��ȫ��ѹ��ջ2֮�У�
ʱ�临�Ӷȣ�����Ϊջ2Ϊ��ʱ��ʱ�临�Ӷ�ΪO(2N), ƽʱΪO(1)��
MyQueue* myQueueCreate() {
	MyQueue *q = (MyQueue*)malloc(sizeof(MyQueue));
	//��ʼ������ջ
	stackInit(&q->first_s);
	stackInit(&q->second_s);
	return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	stackpush(&obj->first_s, x);//���뵽ջ1֮��
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	int size = stackSize(&obj->second_s);//��ȡջ2Ԫ�ظ���
	if (size == 0)//��ջ2λ�գ����ջ1����Ԫ��ѹ��ջ2
	{
		int size1 = stackSize(&obj->first_s);
		while (size1) //������ȫ��ת�Ƶ�ջ2֮��
		{
			int top = stackTop(&obj->first_s);
			stackpush(&obj->second_s, top);
			stackPop(&obj->first_s);
			size1--;
		}
	}
	//��ջ2����
	int ret = stackTop(&obj->second_s);
	stackPop(&obj->second_s);

	return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	int size = stackSize(&obj->second_s);//��ȡջ2Ԫ�ظ���
	if (size == 0)//��ջ2λ�գ����ջ1����Ԫ��ѹ��ջ2
	{
		int size1 = stackSize(&obj->first_s);
		while (size1)//������ȫ��ת�Ƶ�ջ2֮��
		{
			int top = stackTop(&obj->first_s);
			stackpush(&obj->second_s, top);
			stackPop(&obj->first_s);
			size1--;
		}
	}
	return stackTop(&obj->second_s);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	if (stackEmpty(&obj->first_s) && stackEmpty(&obj->second_s))//������Ϊ��
		return true;
	else
		return false;
}

void myQueueFree(MyQueue* obj) {
	stackDestroy(&obj->first_s);
	stackDestroy(&obj->second_s);
	free(obj);
}
