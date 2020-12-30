#include "heap.h"

void Print(Heap *hp, int size)
{
	assert(hp);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", hp->arr[i]);
	}
	printf("\n");
}


void heapCreate(Heap *hp, HPDataType *arr, int size)
{
	assert(hp);
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
		ShiftDown(hp->arr, size, parent);
		parent--;
	}

}

void Swap(HPDataType *arr, int first, int second)
{
	assert(arr);
	HPDataType temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}

void ShiftDown(HPDataType *arr, int size, int parent)//堆向下进行调整
{
	assert(arr);
	int child = parent * 2 + 1;//左孩子坐标
	while (child < size)
	{
		if (child + 1 < size&&arr[child + 1] < arr[child])//右孩子比左孩子小
			child++;
		if (arr[child] < arr[parent])//父节点比孩节点要大
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

void ShiftUp(HPDataType *arr, int child)//向上调整
{
	assert(arr);
	int parent = (child - 1) / 2;
	while (child > 0)//有孩节点必定有父节点
	{
		if (arr[parent] > arr[child])
		{
			Swap(arr, parent, child);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void HeapPush(Heap *hp, HPDataType data)
{
	assert(hp);
	if (hp->size == hp->capacity)//空间容量判定
	{
		HPDataType *Node = (HPDataType *)malloc(sizeof(HPDataType)* 2 * hp->capacity);
		if (Node == NULL)
			exit(-1);
		hp->capacity = 2 * hp->capacity;
	}
	hp->arr[hp->size++] = data;
	ShiftUp(hp->arr, hp->size - 1);
}

void HeapPop(Heap *hp)
{
	assert(hp);
	if (hp->size == 0)//为空
		return;

	Swap(hp->arr, 0, hp->size - 1);//交换
	hp->size--;//删除
	ShiftDown(hp->arr, hp->size, 0);//向下调整
}

HPDataType HeapTop(Heap *hp)
{
	assert(hp);
	if (hp->size == 0)
		exit(-1);
	return hp->arr[0];
}

HPDataType heapSize(Heap *hp)
{
	assert(hp);
	return hp->size;
}

int HeapEmpty(Heap *hp)
{
	assert(hp);
	if (hp->size == 0)//为空
	{
		printf("堆为空\n");
		return 1;
	}
	else
	{
		printf("非空\n");
		return 0;
	}
}

void HeapDestory(Heap *hp)//堆的销毁
{
	assert(hp);
	hp->size = hp->capacity = 0;
	free(hp->arr);
	hp->arr = NULL;
}

void HeapSort(int *arr, int n)//对数组进行排序
{
	assert(arr);
	int size = n;
	int parent = (size - 2) / 2;
	while (parent >= 0)//构建堆
	{
		ShiftDown(arr, size, parent);
		parent--;
	}
	while (size  > 1)
	{
		Swap(arr, 0, size - 1);//交换
		size--;
		ShiftDown(arr, size, 0);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}