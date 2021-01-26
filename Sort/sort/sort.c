#include "sort.h"

void Print(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");
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

void ShellSort(int *arr, int size)//希尔排序
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

void Swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void SelectSort(int *arr, int size)//选择排序
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
		Swap(&arr[begin], &arr[min]);//较小值放入有序部分

		if (max == begin)//有可能begin对应的值已经和min对应的值发生了交换
			max = min;
		Swap(&arr[end], &arr[max]);//较大值放入有序部分
		begin++;
		end--;
	}

}




void HeadCreat(int *arr, int size)//建堆
{
	int parent = (size - 2) / 2;
	while (parent >= 0)
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
			Swap(&arr[child], &arr[parent]);

		parent = child;//更新父节点
		child = 2 * parent + 1;//更新子节点
	}
}

void HeapSort(int *arr, int size)
{
	HeadCreat(arr, size);//建堆,升序建大堆

	while (size>1)//交换第一个和最后一个节点，再尾删
	{
		Swap(&arr[0], &arr[size - 1]);
		size--;
		ShiftDown(arr, 0, size);
	}
}

void BubbleSort(int *arr, int size)//冒泡排序
{
	for (int i = 0; i < size - 1; i++)
	{
		int lable = 1;
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j]>arr[j + 1])
				Swap(&arr[j], &arr[j + 1]);
			lable = 0;
		}
		if (lable == 1)
			break;
	}
}


int partion(int *arr, int begin, int end)//hoare
{
	int key = Getmid(arr, begin, end);//三数取中
	Swap(&arr[begin], &arr[key]);
	key = begin;


	while (begin<end)
	{
		while (begin<end&&arr[key] <= arr[end])//从后往前寻找比key小的值
		{
			end--;
		}
		while (begin<end&&arr[begin] <= arr[key])//从后往前寻找比key大的值
		{
			begin++;
		}
		if (begin < end)
			Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[begin], &arr[key]);//相遇位置的值和key进行交换
	return begin;//返回相遇位置
}

int partion2(int *arr, int begin, int end)//挖坑
{
	int key = Getmid(arr, begin, end);//三数取中
	Swap(&arr[begin], &arr[key]);
	key = arr[begin];

	while (begin<end)
	{
		while (begin<end&&key <= arr[end])//从后往前寻找比key小的值
		{
			end--;
		}
		arr[begin] = arr[end];//将比key小的值填入坑内

		while (begin<end&&arr[begin] <= key)//从后往前寻找比key大的值
		{
			begin++;
		}
		arr[end] = arr[begin];//比key大的值填入坑内
	}
	arr[begin] = key;//基准值填入相遇位置
	return begin;//返回相遇位置
}

int partion3(int *arr, int begin, int end)//前后指针
{
	int key = Getmid(arr, begin, end);//三数取中
	Swap(&arr[begin], &arr[key]);
	key = arr[begin];

	int prev = begin;//最后一个小于基准值的位置
	int cur = prev + 1;//当前位置
	while (cur <= end)
	{
		if (arr[cur]<key&&++prev != cur)//找到下一个小于基准值的位置且两个指针位置不连续
		{
			Swap(&arr[prev], &arr[cur]);//进行交换
		}
		cur++;
	}
	Swap(&arr[begin], &arr[prev]);//基准值与最后一个小于基准值的值进行交换

	return prev;
}

void QuickSort(int *arr, int begin, int end)
{
	if (begin >= end)
		return;

	if ((end - begin + 1) > 10)
	{
		int keypos = partion3(arr, begin, end);

		QuickSort(arr, begin, keypos - 1);//前段
		QuickSort(arr, keypos + 1, end);//后段
	}
	else
	{
		InsertSort(arr + begin, end - begin + 1);//元素个数小于10采用直接插入排序,有序程度越高插入排序时间复杂度越小
	}

}


int Getmid(int *arr, int begin, int end)//三数取中
{
	int mid = begin + (end - begin) / 2;
	if (arr[begin] < arr[mid])
	{
		if (arr[mid] < arr[end])
			return mid;
		else
		{
			if (arr[begin] < arr[end])
			{
				return end;
			}
			else
			{
				return begin;
			}
		}
	}
	else
	{
		if (arr[end] < arr[mid])
		{
			return mid;
		}
		else
		{
			if (arr[end] < arr[begin])
			{
				return end;
			}
			else
			{
				return begin;
			}
		}
	}
}



void QuickSortNoRSt(int *arr, int begin, int end)//非递归,利用栈
{
	stack st;
	StackInit(&st);
	if (end - begin)
	{
		//入栈
		StackPush(&st, end);
		StackPush(&st, begin);
	}
	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);//出栈
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);

		int keypos = partion(arr, begin, end);

		//入栈
		if (keypos + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, keypos + 1);
		}
		if (keypos - 1 > begin)
		{
			StackPush(&st, keypos - 1);
			StackPush(&st, begin);
		}
	}
	StackDestory(&st);
}

void QuickSortNoRQe(int *arr, int begin, int end)//利用栈实现快排
{
	Queue q;
	QueueInit(&q);
	if (end - begin)
	{
		//入队
		QueuePush(&q, begin);
		QueuePush(&q, end);
	}
	while (!QueueEmpty(&q))
	{
		//出队
		int begin = QueueFront(&q);
		QueuePop(&q);
		int end = QueueFront(&q);
		QueuePop(&q);

		int keypos = partion2(arr, begin, end);

		//子序列入队
		if (begin<keypos - 1)
		{
			QueuePush(&q, begin);
			QueuePush(&q, keypos - 1);
		}
		if (keypos + 1 < end)
		{
			QueuePush(&q, keypos + 1);
			QueuePush(&q, end);
		}

	}
	QueueDestory(&q);
}

void Merge(int *arr, int begin, int mid, int end, int *temp)
{
	//划分为两个区间
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int sub = begin;

	while (begin1 <= end1&&begin2 <= end2)//两个数组中，较小的元素放入新辅助空间之中
	{
		if (arr[begin1] < arr[begin2])
			temp[sub++] = arr[begin1++];
		else
			temp[sub++] = arr[begin2++];
	}
	//检查区间之中是否还有剩余的元素
	if (begin1 <= end1)
		memcpy(temp + sub, arr + begin1, sizeof(int)*(end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(temp + sub, arr + begin2, sizeof(int)*(end2 - begin2 + 1));

	//拷贝回原来的空间
	memcpy(arr + begin, temp + begin, sizeof(int)*(end - begin + 1));
}



void MergeR(int *arr, int begin, int end, int *temp)
{
	if (begin >= end)
		return;
	//将区间分解为单个元素的区间，单个元素的区间天然有序
	int mid = begin + (end - begin) / 2;
	MergeR(arr, begin, mid, temp);
	MergeR(arr, mid + 1, end, temp);

	//进行合并，从下往上，进行合并有序序列
	Merge(arr, begin, mid, end, temp);
}

void MergeSort(int *arr, int begin, int end, int size)
{
	int *temp = (int *)malloc(sizeof(int)*size);
	MergeR(arr, begin, end, temp);
	memcpy(arr, temp, sizeof(int)*size);//将排好序的数组拷贝回来
	free(temp);
}