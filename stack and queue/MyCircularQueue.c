ѭ�����е�ʵ��

//����1������size�����ж�
typedef struct {
	int front;
	int rear;
	int k;
	int *arr;
	int size;

} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
	//���ռ�
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

	if (obj->rear == obj->k)//����ĩ��
		obj->rear = 0;

	return true;

}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {//ɾ��Ԫ��
	if (obj->size == 0)
		return false;

	obj->front++;

	if (obj->front == obj->k)
		obj->front = 0;
	obj->size--;

	return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {//���׻�ȡԪ��
	if (obj->size == 0)
		return -1;
	return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {//��β��ȡԪ��
	if (obj->size == 0)
		return -1;

	if (obj->rear == 0)
		return obj->arr[obj->k - 1];

	return obj->arr[obj->rear - 1];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {//�п�
	if (obj->size == 0)
		return true;
	return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {//�ж���
	if (obj->size == obj->k)
		return true;
	return false;

}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->arr);
	free(obj);
}

//����2������size

typedef struct {
	int k;
	int *arr;
	int front;
	int rear;

} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {//��ʼ��
	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	obj->arr = (int *)malloc(sizeof(int)*(k + 1));
	obj->k = k;
	obj->front = obj->rear = 0;
	return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {//����
	if ((obj->rear + 1) % (obj->k + 1) == obj->front)//����
		return false;

	obj->arr[obj->rear] = value;
	obj->rear++;

	if (obj->rear == obj->k + 1)//Խ����
		obj->rear = 0;

	return true;

}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {//ɾ��
	if (obj->rear == obj->front)//Ϊ��
		return false;

	obj->front++;
	if (obj->front == obj->k + 1)
		obj->front = 0;
	return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {//���ض���Ԫ��
	if (obj->rear == obj->front)//Ϊ��
		return -1;

	return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {//��βԪ�ط���

	if (obj->front == obj->rear)//Ϊ��
		return -1;

	if (obj->rear == 0)
		return obj->arr[obj->k];

	return obj->arr[obj->rear - 1];

}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {//�գ�
	if (obj->rear == obj->front)//Ϊ��
		return true;
	return false;

}

bool myCircularQueueIsFull(MyCircularQueue* obj) {//����
	if ((obj->rear + 1) % (obj->k + 1) == obj->front)
		return true;
	else
		return false;

}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->arr);
	free(obj);
}

