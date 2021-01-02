#ifndef _STACK_H_
#define _STACK_H_

#include <windows.h>
#include <stdio.h>
#include <assert.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType *arr;
	int _top;
	int _capacite;
}stack;


void StackInit(stack *ps);//初始化
void StackDestory(stack *ps);//销毁
void StackPush(stack *ps,STDataType data);//入栈
STDataType StackTop(stack *ps);//获取栈顶元素
void StackPop(stack *ps);//出栈
int StackSize(stack *ps);//获取栈内元素个数
int StackEmpty(stack *ps);//判断是否为空







#endif