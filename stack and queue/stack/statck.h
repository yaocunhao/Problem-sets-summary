#ifndef _STATCK_H_
#define _STATCK_H_

#include <stdio.h>
#include <windows.h>
typedef int DataType;
typedef struct Statck
{
	DataType *arr;
	int top;//栈顶
	int capacity;//容量

}statck;

void stackInit(statck *ps);//栈的初始化
void stackpush(statck *ps, DataType data);//入栈
void stackPop(statck *ps);//出栈
DataType stackTop(statck *ps);//获取栈顶元素
int stackSize(statck *ps);//获得有效元素个数
int stackEmpty(statck *ps);//检查是否为空，为空返回非零
void stackDestroy(statck *ps);






#endif