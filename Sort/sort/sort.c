#include "sort.h"

void Print(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n\n");
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

void ShellSort(int *arr, int size)//ϣ������
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

void Swap(int *num1, int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void SelectSort(int *arr, int size)//ѡ������
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
		Swap(&arr[begin], &arr[min]);//��Сֵ�������򲿷�

		if (max == begin)//�п���begin��Ӧ��ֵ�Ѿ���min��Ӧ��ֵ�����˽���
			max = min;
		Swap(&arr[end], &arr[max]);//�ϴ�ֵ�������򲿷�
		begin++;
		end--;
	}

}




void HeadCreat(int *arr, int size)//����
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
		if (child + 1 < size&&arr[child + 1] > arr[child])//ѡ�����ĺ���
			child++;

		if (arr[child] > arr[parent])//�����ڵ�Ϊ���ֵ
			Swap(&arr[child], &arr[parent]);

		parent = child;//���¸��ڵ�
		child = 2 * parent + 1;//�����ӽڵ�
	}
}

void HeapSort(int *arr, int size)
{
	HeadCreat(arr, size);//����,���򽨴��

	while (size>1)//������һ�������һ���ڵ㣬��βɾ
	{
		Swap(&arr[0], &arr[size - 1]);
		size--;
		ShiftDown(arr, 0, size);
	}
}

void BubbleSort(int *arr, int size)//ð������
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
	int key = Getmid(arr, begin, end);//����ȡ��
	Swap(&arr[begin], &arr[key]);
	key = begin;


	while (begin<end)
	{
		while (begin<end&&arr[key] <= arr[end])//�Ӻ���ǰѰ�ұ�keyС��ֵ
		{
			end--;
		}
		while (begin<end&&arr[begin] <= arr[key])//�Ӻ���ǰѰ�ұ�key���ֵ
		{
			begin++;
		}
		if (begin < end)
			Swap(&arr[begin], &arr[end]);
	}
	Swap(&arr[begin], &arr[key]);//����λ�õ�ֵ��key���н���
	return begin;//��������λ��
}

int partion2(int *arr, int begin, int end)//�ڿ�
{
	int key = Getmid(arr, begin, end);//����ȡ��
	Swap(&arr[begin], &arr[key]);
	key = arr[begin];

	while (begin<end)
	{
		while (begin<end&&key <= arr[end])//�Ӻ���ǰѰ�ұ�keyС��ֵ
		{
			end--;
		}
		arr[begin] = arr[end];//����keyС��ֵ�������

		while (begin<end&&arr[begin] <= key)//�Ӻ���ǰѰ�ұ�key���ֵ
		{
			begin++;
		}
		arr[end] = arr[begin];//��key���ֵ�������
	}
	arr[begin] = key;//��׼ֵ��������λ��
	return begin;//��������λ��
}

int partion3(int *arr, int begin, int end)//ǰ��ָ��
{
	int key = Getmid(arr, begin, end);//����ȡ��
	Swap(&arr[begin], &arr[key]);
	key = arr[begin];

	int prev = begin;//���һ��С�ڻ�׼ֵ��λ��
	int cur = prev + 1;//��ǰλ��
	while (cur <= end)
	{
		if (arr[cur]<key&&++prev != cur)//�ҵ���һ��С�ڻ�׼ֵ��λ��������ָ��λ�ò�����
		{
			Swap(&arr[prev], &arr[cur]);//���н���
		}
		cur++;
	}
	Swap(&arr[begin], &arr[prev]);//��׼ֵ�����һ��С�ڻ�׼ֵ��ֵ���н���

	return prev;
}

void QuickSort(int *arr, int begin, int end)
{
	if (begin >= end)
		return;

	if ((end - begin + 1) > 10)
	{
		int keypos = partion3(arr, begin, end);

		QuickSort(arr, begin, keypos - 1);//ǰ��
		QuickSort(arr, keypos + 1, end);//���
	}
	else
	{
		InsertSort(arr + begin, end - begin + 1);//Ԫ�ظ���С��10����ֱ�Ӳ�������,����̶�Խ�߲�������ʱ�临�Ӷ�ԽС
	}

}


int Getmid(int *arr, int begin, int end)//����ȡ��
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



void QuickSortNoRSt(int *arr, int begin, int end)//�ǵݹ�,����ջ
{
	stack st;
	StackInit(&st);
	if (end - begin)
	{
		//��ջ
		StackPush(&st, end);
		StackPush(&st, begin);
	}
	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);//��ջ
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);

		int keypos = partion(arr, begin, end);

		//��ջ
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

void QuickSortNoRQe(int *arr, int begin, int end)//����ջʵ�ֿ���
{
	Queue q;
	QueueInit(&q);
	if (end - begin)
	{
		//���
		QueuePush(&q, begin);
		QueuePush(&q, end);
	}
	while (!QueueEmpty(&q))
	{
		//����
		int begin = QueueFront(&q);
		QueuePop(&q);
		int end = QueueFront(&q);
		QueuePop(&q);

		int keypos = partion2(arr, begin, end);

		//���������
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
	//����Ϊ��������
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int sub = begin;

	while (begin1 <= end1&&begin2 <= end2)//���������У���С��Ԫ�ط����¸����ռ�֮��
	{
		if (arr[begin1] < arr[begin2])
			temp[sub++] = arr[begin1++];
		else
			temp[sub++] = arr[begin2++];
	}
	//�������֮���Ƿ���ʣ���Ԫ��
	if (begin1 <= end1)
		memcpy(temp + sub, arr + begin1, sizeof(int)*(end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(temp + sub, arr + begin2, sizeof(int)*(end2 - begin2 + 1));

	//������ԭ���Ŀռ�
	memcpy(arr + begin, temp + begin, sizeof(int)*(end - begin + 1));
}



void MergeR(int *arr, int begin, int end, int *temp)
{
	if (begin >= end)
		return;
	//������ֽ�Ϊ����Ԫ�ص����䣬����Ԫ�ص�������Ȼ����
	int mid = begin + (end - begin) / 2;
	MergeR(arr, begin, mid, temp);
	MergeR(arr, mid + 1, end, temp);

	//���кϲ����������ϣ����кϲ���������
	Merge(arr, begin, mid, end, temp);
}

void MergeSort(int *arr, int begin, int end, int size)
{
	int *temp = (int *)malloc(sizeof(int)*size);
	MergeR(arr, begin, end, temp);
	memcpy(arr, temp, sizeof(int)*size);//���ź�������鿽������
	free(temp);
}