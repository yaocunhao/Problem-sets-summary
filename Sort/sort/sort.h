#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <windows.h>
#include <time.h>
#pragma warning (disable :4996)
#include "stack.h"
#include "queue.h"

void InsertSort(int *arr, int size);//��������
void Print(int *arr, int size);
void ShellSort(int *arr, int size);
void Swap(int *num1, int *num2);
void SelectSort(int *arr, int size);

void HeadCreat(int *arr, int size);//����
void ShiftDown(int *arr, int parent, int size);
void HeapSort(int *arr, int size);//����
void BubbleSort(int *arr, int size);//ð������

int partion(int *arr, int begin, int end);//hoare
void QuickSort(int *arr, int begin, int end);//����
int partion2(int *arr, int begin, int end);//�ڿӷ�
int partion3(int *arr, int begin, int end);//˫ָ�뷨
int Getmid(int *arr, int begin, int end);//����ȡ��
void QuickSortNoRSt(int *arr, int begin, int end);//�ǵݹ飬����ջʵ�ֿ���
void QuickSortNoRQe(int *arr, int begin, int end);//�ǵݹ飬���ö���ʵ�ֿ���

void Merge(int *arr, int begin, int mid, int end, int *temp);//�ϲ�
void MergeR(int *arr, int begin, int end, int *temp);//�ݹ�
void MergeSort(int *arr, int begin, int end, int size);//�鲢����
void _Merge(int *arr, int begin1, int end1, int begin2, int end2, int *temp);//�ǵݹ�ϲ�
void MergeSortNoR(int *arr, int size);//�鲢�ǵݹ�

void CountSort(int *arr, int size);//��������
#endif 