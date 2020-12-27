循环队列的实现

//方法1：利用size进行判断
typedef struct {
	int front;
	int rear;
	int k;
	int *arr;
	int size;

} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
	//开空间
	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	obj->arr = (int *)malloc(sizeof(int)*k);

	obj->front = 0;
	obj->rear = 0;
	obj->k = k;
	obj->size = 0;
	return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (obj->size == obj->k)
		return false;

	obj->arr[obj->rear] = value;
	obj->rear++;
	obj->size++;

	if (obj->rear == obj->k)//到达末端
		obj->rear = 0;

	return true;

}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {//删除元素
	if (obj->size == 0)
		return false;

	obj->front++;

	if (obj->front == obj->k)
		obj->front = 0;
	obj->size--;

	return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {//队首获取元素
	if (obj->size == 0)
		return -1;
	return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {//队尾获取元素
	if (obj->size == 0)
		return -1;

	if (obj->rear == 0)
		return obj->arr[obj->k - 1];

	return obj->arr[obj->rear - 1];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {//判空
	if (obj->size == 0)
		return true;
	return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {//判定满
	if (obj->size == obj->k)
		return true;
	return false;

}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->arr);
	free(obj);
}

//方法2：不带size

typedef struct {
	int k;
	int *arr;
	int front;
	int rear;

} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {//初始化
	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	obj->arr = (int *)malloc(sizeof(int)*(k + 1));
	obj->k = k;
	obj->front = obj->rear = 0;
	return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {//插入
	if ((obj->rear + 1) % (obj->k + 1) == obj->front)//满了
		return false;

	obj->arr[obj->rear] = value;
	obj->rear++;

	if (obj->rear == obj->k + 1)//越界了
		obj->rear = 0;

	return true;

}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {//删除
	if (obj->rear == obj->front)//为空
		return false;

	obj->front++;
	if (obj->front == obj->k + 1)
		obj->front = 0;
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {//返回队首元素
	if (obj->rear == obj->front)//为空
		return -1;

	return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {//队尾元素返回

	if (obj->front == obj->rear)//为空
		return -1;

	if (obj->rear == 0)
		return obj->arr[obj->k];

	return obj->arr[obj->rear - 1];

}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {//空？
	if (obj->rear == obj->front)//为空
		return true;
	return false;

}

bool myCircularQueueIsFull(MyCircularQueue* obj) {//满？
	if ((obj->rear + 1) % (obj->k + 1) == obj->front)
		return true;
	else
		return false;

}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->arr);
	free(obj);
}

