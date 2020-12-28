#include "heap.h"


void heapCreate(Heap *hp, HPDataType *arr, int size)
{
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

void ShiftDown(HPDataType *arr, int size, int parent)//�����½��е���
{
	int child = parent*2+1;//��������
	while (child < size)
	{
		if (child + 1 < size&&arr[child + 1] < arr[child])//�Һ��ӱ�����С
			child++;
		if (arr[child] < arr[parent])//���ڵ�Ⱥ��ڵ�Ҫ��
		{
			Swap(arr,parent,child);//���н���

			//�ڵ����
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break; //���ڵ�Ⱥ��ڵ�С
	}
}

void ShiftUp(HPDataType *arr, int size, int parent)//�����½��е���,����Ϊ���
{
	int child = parent * 2 + 1;//��������
	while (child < size)
	{
		if (child + 1 < size&&arr[child + 1] > arr[child])//�Һ��ӱ�����С
			child++;
		if (arr[child] > arr[parent])//���ڵ�Ⱥ��ڵ�Ҫ��
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