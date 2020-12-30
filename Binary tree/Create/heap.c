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
	//���ж����ݵĿ���
	hp->arr = (HPDataType *)malloc(sizeof(HPDataType)*size);//���ٶѿռ�
	if (hp->arr == NULL)
		return;
	hp->capacity = hp->size = size;
	memcpy(hp->arr, arr, size*sizeof(HPDataType));

	//���жѵ����򣬴����һ����Ҷ�ӽڵ㿪ʼ
	int parent = (size - 2) / 2;//���һ����Ҷ�ӽڵ�
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

void ShiftDown(HPDataType *arr, int size, int parent)//�����½��е���
{
	assert(arr);
	int child = parent * 2 + 1;//��������
	while (child < size)
	{
		if (child + 1 < size&&arr[child + 1] < arr[child])//�Һ��ӱ�����С
			child++;
		if (arr[child] < arr[parent])//���ڵ�Ⱥ��ڵ�Ҫ��
		{
			Swap(arr, parent, child);//���н���

			//�ڵ����
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break; //���ڵ�Ⱥ��ڵ�С
	}
}

void ShiftUp(HPDataType *arr, int child)//���ϵ���
{
	assert(arr);
	int parent = (child - 1) / 2;
	while (child > 0)//�к��ڵ�ض��и��ڵ�
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
	if (hp->size == hp->capacity)//�ռ������ж�
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
	if (hp->size == 0)//Ϊ��
		return;

	Swap(hp->arr, 0, hp->size - 1);//����
	hp->size--;//ɾ��
	ShiftDown(hp->arr, hp->size, 0);//���µ���
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
	if (hp->size == 0)//Ϊ��
	{
		printf("��Ϊ��\n");
		return 1;
	}
	else
	{
		printf("�ǿ�\n");
		return 0;
	}
}

void HeapDestory(Heap *hp)//�ѵ�����
{
	assert(hp);
	hp->size = hp->capacity = 0;
	free(hp->arr);
	hp->arr = NULL;
}

void HeapSort(int *arr, int n)//�������������
{
	assert(arr);
	int size = n;
	int parent = (size - 2) / 2;
	while (parent >= 0)//������
	{
		ShiftDown(arr, size, parent);
		parent--;
	}
	while (size  > 1)
	{
		Swap(arr, 0, size - 1);//����
		size--;
		ShiftDown(arr, size, 0);
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}