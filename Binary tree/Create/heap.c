#include "heap.h"


void heapCreate(Heap *hp, HPDataType *arr, int size)
{
	//进行堆数据的拷贝
	hp->arr = (HPDataType *)malloc(sizeof(HPDataType)*size);//开辟堆空间
	if (hp->arr == NULL)
		return;
	hp->capacity = hp->size = size;
	memcpy(hp->arr, arr, size*sizeof(HPDataType));

	//进行堆的排序，从最后一个非叶子节点开始
	int parent = (size - 2) / 2;//最后一个非叶子节点
	while (parent >= 0)
	{
		//ShiftDown(hp->arr, size, parent);
		ShiftUp(hp->arr, size, parent);
		parent--;
	}

}

void Swap(HPDataType *arr, int parent, int child)
{
	HPDataType temp = arr[parent];
	arr[parent] = arr[child];
	arr[child] = temp;
}

void ShiftDown(HPDataType *arr, int size, int parent)//堆向下进行调整
{
	int child = parent*2+1;//左孩子坐标
	while (child < size)
	{
		if (child + 1 < size&&arr[child + 1] < arr[child])//右孩子比左孩子小
			child++;
		if (arr[child] < arr[parent])//父节点比孩节点要大
		{
			Swap(arr,parent,child);//进行交换

			//节点更新
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break; //父节点比孩节点小
	}
}

void ShiftUp(HPDataType *arr, int size, int parent)//堆向下进行调整,调整为大堆
{
	int child = parent * 2 + 1;//左孩子坐标
	while (child < size)
	{
		if (child + 1 < size&&arr[child + 1] > arr[child])//右孩子比左孩子小
			child++;
		if (arr[child] > arr[parent])//父节点比孩节点要大
		{
			Swap(arr, parent, child);//进行交换

			//节点更新
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break; //父节点比孩节点小
	}
}