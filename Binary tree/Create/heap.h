#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdio.h>
#include <windows.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType *arr;
	int size;
	int capacity;
}Heap;

void heapCreate(Heap *hp, HPDataType *arr, int size);//�ѵĹ���
void ShiftDown(HPDataType *arr, int size, int parent);//�����µ���
void ShiftUp(HPDataType *arr, int size, int parent);//�����½��е���,����Ϊ���



//void HeapDestory(Heap *hp);//�ѵ�����
//void HeapPush(Heap *hp, HPDataType);//�ѵĲ���
//void HeapPop(Heap *hp);//�ѵ�ɾ��
//HPDataType HeapTop(Heap *hp);//ȡ�Ѷ�����
//HPDataType HeapSize(Heap *hp);//�ѵ����ݸ���
//int HeapEmpty(Heap *hp);//�ѵ��п�
//void HeapSort(int *arr, int n);//�������������



#endif