#include "statck.h"

void stackInit(statck *ps)//ջ�ĳ�ʼ��
{
	ps->arr = (DataType *)malloc(sizeof(DataType)* 2);
	if (ps->arr == NULL)
		return;
	ps->top = 0;
	ps->capacity = 2;
}

void stackpush(statck *ps, DataType data)//��ջ
{
	if (ps->top == ps->capacity)//����
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

void stackPop(statck *ps)//��ջ
{
	if (ps->top == 0)//��ջ
		return;
	ps->top--;
}

DataType stackTop(statck *ps)//��ȡջ��Ԫ��
{
	if (ps->top == 0)
		exit(-1);
	return ps->arr[ps->top-1];
}

DataType stackSize(statck *ps)//��ȡԪ����Ч����
{
	return ps->top;
}

int stackEmpty(statck *ps)//����Ƿ�Ϊ��
{
	if (ps->top == 0)
		return 1;
	else
		return 0;
}

void stackDestroy(statck *ps)//����
{
	free(ps->arr);
	ps->top = ps->capacity = 0;
}
