#include "statck.h"

void stackInit(statck *ps)//栈的初始化
{
	ps->arr = (DataType *)malloc(sizeof(DataType)* 2);
	if (ps->arr == NULL)
		return;
	ps->top = 0;
	ps->capacity = 2;
}

void stackpush(statck *ps, DataType data)//入栈
{
	if (ps->top == ps->capacity)//满了
	{
		DataType *newarr = (DataType *)realloc(ps->arr, sizeof(DataType)* 2 * ps->capacity);
		if (newarr == NULL)
			return;
		ps->arr = newarr;
		ps->capacity = 2 * ps->capacity;
	}

	ps->arr[ps->top] = data;
	ps->top++;
}

void stackPop(statck *ps)//出栈
{
	if (ps->top == 0)//空栈
		return;
	ps->top--;
}

DataType stackTop(statck *ps)//获取栈顶元素
{
	if (ps->top == 0)
		exit(-1);
	return ps->arr[ps->top-1];
}

DataType stackSize(statck *ps)//获取元素有效个数
{
	return ps->top;
}

int stackEmpty(statck *ps)//检查是否为空
{
	if (ps->top == 0)
		return 1;
	else
		return 0;
}

void stackDestroy(statck *ps)//销毁
{
	free(ps->arr);
	ps->top = ps->capacity = 0;
}
