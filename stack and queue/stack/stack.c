#include"stack.h"

void StackInit(stack *ps)//��ʼ��
{
	assert(ps);
	STDataType *node = (STDataType*)malloc(sizeof(STDataType)* 2);
	assert(node);
	ps->arr = node;
	ps->_top = 0;
	ps->_capacite = 2;
}

void StackDestory(stack *ps)//����
{
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
	ps->_top = ps->_capacite = 0;
}
void StackPush(stack *ps,STDataType data)//��ջ
{
	assert(ps);

	if (ps->_top == ps->_capacite)
	{
		ps->_capacite *= 2;
		ps->arr = (STDataType*)realloc(ps->arr, sizeof(STDataType)*ps->_capacite);
	}
	ps->arr[ps->_top++] = data;

}
STDataType StackTop(stack *ps)//��ȡջ��Ԫ��
{
	assert(ps);
	assert(ps->_top != 0);
	return ps->arr[ps->_top-1];
}
void StackPop(stack *ps)//��ջ
{
	assert(ps);
	assert(ps->_top != 0);
	ps->_top--;
}
int StackSize(stack *ps)//��ȡջ��Ԫ�ظ���
{
	assert(ps);
	return ps->_top;
}
int StackEmpty(stack *ps)//�ж��Ƿ�Ϊ��
{
	assert(ps);
	if (ps->_top == 0)
		return 1;
	else
		return 0;
}