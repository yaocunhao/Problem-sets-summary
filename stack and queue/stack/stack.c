#include"stack.h"

void StackInit(stack *ps)//初始化
{
	assert(ps);
	STDataType *node = (STDataType*)malloc(sizeof(STDataType)* 2);
	assert(node);
	ps->arr = node;
	ps->_top = 0;
	ps->_capacite = 2;
}

void StackDestory(stack *ps)//销毁
{
	assert(ps);
	free(ps->arr);
	ps->arr = NULL;
	ps->_top = ps->_capacite = 0;
}
void StackPush(stack *ps,STDataType data)//入栈
{
	assert(ps);

	if (ps->_top == ps->_capacite)
	{
		ps->_capacite *= 2;
		ps->arr = (STDataType*)realloc(ps->arr, sizeof(STDataType)*ps->_capacite);
	}
	ps->arr[ps->_top++] = data;

}
STDataType StackTop(stack *ps)//获取栈顶元素
{
	assert(ps);
	assert(ps->_top != 0);
	return ps->arr[ps->_top-1];
}
void StackPop(stack *ps)//出栈
{
	assert(ps);
	assert(ps->_top != 0);
	ps->_top--;
}
int StackSize(stack *ps)//获取栈内元素个数
{
	assert(ps);
	return ps->_top;
}
int StackEmpty(stack *ps)//判断是否为空
{
	assert(ps);
	if (ps->_top == 0)
		return 1;
	else
		return 0;
}