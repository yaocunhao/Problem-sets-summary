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

void heapCreate(Heap *hp, HPDataType *arr, int size);//堆的构建
void ShiftDown(HPDataType *arr, int size, int parent);//堆向下调整
void ShiftUp(HPDataType *arr, int size, int parent);//堆向下进行调整,调整为大堆



//void HeapDestory(Heap *hp);//堆的销毁
//void HeapPush(Heap *hp, HPDataType);//堆的插入
//void HeapPop(Heap *hp);//堆的删除
//HPDataType HeapTop(Heap *hp);//取堆顶数据
//HPDataType HeapSize(Heap *hp);//堆的数据个数
//int HeapEmpty(Heap *hp);//堆的判空
//void HeapSort(int *arr, int n);//对数组进行排序



#endif