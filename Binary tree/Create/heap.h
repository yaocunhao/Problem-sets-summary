#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdio.h>
#include <windows.h>
#include <assert.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType *arr;
	int size;
	int capacity;
}Heap;
void Print(Heap *hp, int size);//��ӡ����
void heapCreate(Heap *hp, HPDataType *arr, int size);//�ѵĹ���
void ShiftDown(HPDataType *arr, int size, int parent);//�����µ���
void ShiftUp(HPDataType *arr, int child);//���ϵ���
void HeapPush(Heap *hp, HPDataType data);//�ѵĲ���
void HeapPop(Heap *hp);//�ѵ�ɾ��
HPDataType HeapTop(Heap *hp);//ȡ�Ѷ�����
HPDataType heapSize(Heap *hp);//�ѵ����ݸ���
int HeapEmpty(Heap *hp);//�ѵ��п�
void HeapDestory(Heap *hp);//�ѵ�����
void HeapSort(int *arr, int n);//�������������



#endif