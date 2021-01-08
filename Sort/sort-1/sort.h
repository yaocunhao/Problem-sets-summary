#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <windows.h>
#include <time.h>


void InsertSort(int *arr,int size);//≤Â»Î≈≈–Ú
void Print(int *arr, int size);
void ShellSort(int *arr, int size);
void Swap(int *arr, int sub1, int sub2);
void SelectSort(int *arr, int size);

void ShiftDown(int *arr, int parent, int size);
void HeadSort(int *arr, int size);



#endif 