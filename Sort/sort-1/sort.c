#include "sort.h"

void Print(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}

 void InsertSort(int *arr, int size)//插入排序
{
	for (int i = 0; i < size - 1; i++)//升序
	{
		int end = i;//有序数组的最后一个元素下标
		int key = arr[end + 1];//无序数组的第一个元素
		while (end >= 0 && arr[end]>key)
		{
			arr[end + 1] = arr[end];//往后挪动一个位置
			end--;
		}
		arr[end + 1] = key;
	}

	//for (int i = 0; i < size - 1; i++)//降序
	//{
	//	int end = i;
	//	int key = arr[end + 1];
	//	while (end >= 0&&arr[end] < key)
	//	{
	//		arr[end + 1] = arr[end];
	//		end--;
	//	}
	//	arr[end + 1] = key;
	//}

}

void ShellSort(int *arr, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 2;//每次的步距为gap
		for (int i = 0; i < size - gap; i++)
		{
			int end = i;//有序的最后一个元素的下标
			int key = arr[end + gap];
			while (end >= 0 && arr[end]>key)
			{
				arr[end + gap] = arr[end];
				end -= gap;
			}
			arr[end + gap] = key;
		}
	}
}

void Swap(int *arr, int sub1, int sub2)
{
	int temp = arr[sub1];
	arr[sub1] = arr[sub2];
	arr[sub2] = temp;
}

void SelectSort(int *arr, int size)
{
	int begin = 0;
	int end = size - 1;
	
	while (begin < end)
	{
		int min = begin;//较小值坐标
		int max = end;//较大值坐标
		for (int i = begin; i <= end; i++)
		{
			if (arr[i] < arr[min])//取得新的较小值坐标
				min = i;
			if (arr[i] > arr[max])//取得新的较大值坐标
				max = i;
		}
		Swap(arr, begin, min);//较小值放入有序部分
		
		if (max == begin)//有可能begin对应的值已经和min对应的值发生了交换
			max = min;
		Swap(arr, end, max);//较大值放入有序部分
		begin++;
		end--;
	}

}




void HeadCreat(int *arr,int size)//建堆
{
	int parent = (size - 2) / 2;
	while (parent>=0)
	{
		ShiftDown(arr, parent, size);
		parent--;
	}
}

void ShiftDown(int *arr, int parent, int size)
{
	int child = 2 * parent + 1;
	while (child < size)
	{
		if (child + 1 < size&&arr[child + 1] > arr[child])//选择最大的孩子
			child++;

		if (arr[child] > arr[parent])//调整节点为最大值
			Swap(arr, child, parent);

		parent = child;//更新父节点
		child = 2 * parent + 1;//更新子节点
	}
}
 
void HeadSort(int *arr,int size )
{
	HeadCreat(arr, size);//建堆,升序建大堆

	while (size>1)//交换第一个和最后一个节点，再尾删
	{
		Swap(arr, 0, size - 1);
		size--;
		ShiftDown(arr, 0, size);
	}
}