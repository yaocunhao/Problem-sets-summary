用栈模拟队列的实现

////方法1：
//存的时候存到栈1，出队的时候全部倒到栈2，然后再进行操作，操作完再倒入到栈1
//
//### 代码
//
//```c
//typedef int DataType;
//typedef struct Statck
//{
//	DataType *arr;
//	int top;//栈顶
//	int capacity;//容量
//
//}statck;
//void stackInit(statck *ps)//栈的初始化
//{
//	ps->arr = (DataType *)malloc(sizeof(DataType)* 2);
//	if (ps->arr == NULL)
//		return;
//	ps->top = 0;
//	ps->capacity = 2;
//}
//
//void stackpush(statck *ps, DataType data)//入栈
//{
//	if (ps->top == ps->capacity)//满了
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
//void stackPop(statck *ps)//出栈
//{
//	if (ps->top == 0)//空栈
//		exit(-1);
//	ps->top--;
//}
//
//DataType stackTop(statck *ps)//获取栈顶元素
//{
//	if (ps->top == 0)
//		exit(-1);
//	return ps->arr[ps->top - 1];
//}
//
//DataType stackSize(statck *ps)//获取元素有效个数
//{
//	return ps->top;
//}
//
//int stackEmpty(statck *ps)//检查是否为空
//{
//	if (ps->top == 0)
//		return 1;
//	else
//		return 0;
//}
//
//void stackDestroy(statck *ps)//销毁
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
//	//初始化两个栈
//	stackInit(&q->first_s);
//	stackInit(&q->second_s);
//	return q;
//}
//
///** Push element x to the back of queue. */
//void myQueuePush(MyQueue* obj, int x) {
//	stackpush(&obj->first_s, x);//存入到栈1之中
//}
//
///** Removes the element from in front of queue and returns that element. */
//int myQueuePop(MyQueue* obj) {
//	int size = stackSize(&obj->first_s);//获取元素个数
//	while (size)//将数据全部转移到栈2之中
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
//	while (size)//再次放回到栈1之中
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
//	int size = stackSize(&obj->first_s);//获取元素个数
//	while (size)//将数据全部转移到栈2之中
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
//	while (size)//再次放回到栈1之中
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

//方法2：
压入的元素全部压入到栈1之中，弹出则从栈2中弹出，如果栈2位空，则将栈1的元素全部压到栈2之中；
时间复杂度：最坏情况为栈2为空时，时间复杂度为O(2N), 平时为O(1)；
MyQueue* myQueueCreate() {
	MyQueue *q = (MyQueue*)malloc(sizeof(MyQueue));
	//初始化两个栈
	stackInit(&q->first_s);
	stackInit(&q->second_s);
	return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	stackpush(&obj->first_s, x);//存入到栈1之中
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	int size = stackSize(&obj->second_s);//获取栈2元素个数
	if (size == 0)//若栈2位空，则从栈1弹出元素压入栈2
	{
		int size1 = stackSize(&obj->first_s);
		while (size1) //将数据全部转移到栈2之中
		{
			int top = stackTop(&obj->first_s);
			stackpush(&obj->second_s, top);
			stackPop(&obj->first_s);
			size1--;
		}
	}
	//从栈2弹出
	int ret = stackTop(&obj->second_s);
	stackPop(&obj->second_s);

	return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	int size = stackSize(&obj->second_s);//获取栈2元素个数
	if (size == 0)//若栈2位空，则从栈1弹出元素压入栈2
	{
		int size1 = stackSize(&obj->first_s);
		while (size1)//将数据全部转移到栈2之中
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
	if (stackEmpty(&obj->first_s) && stackEmpty(&obj->second_s))//两个都为空
		return true;
	else
		return false;
}

void myQueueFree(MyQueue* obj) {
	stackDestroy(&obj->first_s);
	stackDestroy(&obj->second_s);
	free(obj);
}
