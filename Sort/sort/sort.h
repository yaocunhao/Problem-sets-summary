#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <windows.h>
#include <time.h>
#pragma warning (disable :4996)
#include "stack.h"
#include "queue.h"

void InsertSort(int *arr, int size);//插入排序
void Print(int *arr, int size);
void ShellSort(int *arr, int size);
void Swap(int *num1, int *num2);
void SelectSort(int *arr, int size);

void HeadCreat(int *arr, int size);//建堆
void ShiftDown(int *arr, int parent, int size);
void HeapSort(int *arr, int size);//堆排
void BubbleSort(int *arr, int size);//冒泡排序

int partion(int *arr, int begin, int end);//hoare
void QuickSort(int *arr, int begin, int end);//快排
int partion2(int *arr, int begin, int end);//挖坑法
int partion3(int *arr, int begin, int end);//双指针法
int Getmid(int *arr, int begin, int end);//三数取中
void QuickSortNoRSt(int *arr, int begin, int end);//非递归，利用栈实现快排
void QuickSortNoRQe(int *arr, int begin, int end);//非递归，利用队列实现快排

void Merge(int *arr, int begin, int mid, int end, int *temp);//合并
void MergeR(int *arr, int begin, int end, int *temp);//递归
void MergeSort(int *arr, int begin, int end, int size);//归并排序
void _Merge(int *arr, int begin1, int end1, int begin2, int end2, int *temp);//非递归合并
void MergeSortNoR(int *arr, int size);//归并非递归

void CountSort(int *arr, int size);//计数排序
#endif 