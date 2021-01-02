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


void StackInit(stack *ps);//��ʼ��
void StackDestory(stack *ps);//����
void StackPush(stack *ps,STDataType data);//��ջ
STDataType StackTop(stack *ps);//��ȡջ��Ԫ��
void StackPop(stack *ps);//��ջ
int StackSize(stack *ps);//��ȡջ��Ԫ�ظ���
int StackEmpty(stack *ps);//�ж��Ƿ�Ϊ��







#endif