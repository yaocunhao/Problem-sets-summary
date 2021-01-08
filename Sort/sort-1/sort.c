#include "sort.h"

void Print(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}

 void InsertSort(int *arr, int size)//��������
{
	for (int i = 0; i < size - 1; i++)//����
	{
		int end = i;//������������һ��Ԫ���±�
		int key = arr[end + 1];//��������ĵ�һ��Ԫ��
		while (end >= 0 && arr[end]>key)
		{
			arr[end + 1] = arr[end];//����Ų��һ��λ��
			end--;
		}
		arr[end + 1] = key;
	}

	//for (int i = 0; i < size - 1; i++)//����
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
		gap = gap / 2;//ÿ�εĲ���Ϊgap
		for (int i = 0; i < size - gap; i++)
		{
			int end = i;//��������һ��Ԫ�ص��±�
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
		int min = begin;//��Сֵ����
		int max = end;//�ϴ�ֵ����
		for (int i = begin; i <= end; i++)
		{
			if (arr[i] < arr[min])//ȡ���µĽ�Сֵ����
				min = i;
			if (arr[i] > arr[max])//ȡ���µĽϴ�ֵ����
				max = i;
		}
		Swap(arr, begin, min);//��Сֵ�������򲿷�
		
		if (max == begin)//�п���begin��Ӧ��ֵ�Ѿ���min��Ӧ��ֵ�����˽���
			max = min;
		Swap(arr, end, max);//�ϴ�ֵ�������򲿷�
		begin++;
		end--;
	}

}




void HeadCreat(int *arr,int size)//����
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
		if (child + 1 < size&&arr[child + 1] > arr[child])//ѡ�����ĺ���
			child++;

		if (arr[child] > arr[parent])//�����ڵ�Ϊ���ֵ
			Swap(arr, child, parent);

		parent = child;//���¸��ڵ�
		child = 2 * parent + 1;//�����ӽڵ�
	}
}
 
void HeadSort(int *arr,int size )
{
	HeadCreat(arr, size);//����,���򽨴��

	while (size>1)//������һ�������һ���ڵ㣬��βɾ
	{
		Swap(arr, 0, size - 1);
		size--;
		ShiftDown(arr, 0, size);
	}
}