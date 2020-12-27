实现栈的基本功能

MyStack* myStackCreate() {
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
	obj->size = 0;
	obj->capacity = 2;
	obj->arr = (int *)malloc(sizeof(int)*(obj->capacity));
	return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	if (obj->size == obj->capacity)//满了
	{
		obj->arr = (int *)realloc(obj->arr, sizeof(int)*(obj->capacity) * 2);
		obj->capacity = obj->capacity * 2;
	}
	(obj->arr)[obj->size] = x;
	obj->size++;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	if (obj->size == 0)
		return false;//为空
	int ele = (obj->arr)[obj->size - 1];
	obj->size--;
	return ele;

}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	if (obj->size == 0)
		return false;
	return obj->arr[obj->size - 1];

}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	if (obj->size == 0)
		return true;
	else
		return false;

}

void myStackFree(MyStack* obj) {
	obj->size = 0;
	obj->capacity = 0;
	free(obj->arr);
	free(obj);
}