#ifndef _STATCK_H_
#define _STATCK_H_

#include <stdio.h>
#include <windows.h>
typedef int DataType;
typedef struct Statck
{
	DataType *arr;
	int top;//ջ��
	int capacity;//����

}statck;

void stackInit(statck *ps);//ջ�ĳ�ʼ��
void stackpush(statck *ps, DataType data);//��ջ
void stackPop(statck *ps);//��ջ
DataType stackTop(statck *ps);//��ȡջ��Ԫ��
int stackSize(statck *ps);//�����ЧԪ�ظ���
int stackEmpty(statck *ps);//����Ƿ�Ϊ�գ�Ϊ�շ��ط���
void stackDestroy(statck *ps);






#endif