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
void Print(Heap *hp, int size);//打印函数
void heapCreate(Heap *hp, HPDataType *arr, int size);//堆的构建
void ShiftDown(HPDataType *arr, int size, int parent);//堆向下调整
void ShiftUp(HPDataType *arr, int child);//向上调整
void HeapPush(Heap *hp, HPDataType data);//堆的插入
void HeapPop(Heap *hp);//堆的删除
HPDataType HeapTop(Heap *hp);//取堆顶数据
HPDataType heapSize(Heap *hp);//堆的数据个数
int HeapEmpty(Heap *hp);//堆的判空
void HeapDestory(Heap *hp);//堆的销毁
void HeapSort(int *arr, int n);//对数组进行排序



#endif