����һ���������� nums�����㽫�������������С�

�ⷨ������ϣ������������������


void ShellSort(int *arr, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//ÿ�εĲ���Ϊgap
		for (int i = 0; i < size - gap; i++)
		{
			int end = i;//��������һ��Ԫ�ص��±�
			int key = arr[end + gap];
			while (end >= 0 && arr[end]>key)
			{
				arr[end + gap] = arr[end];//����Ų��һ��λ��
				end -= gap;
			}
			arr[end + gap] = key;
		}
	}
}

int* sortArray(int* nums, int numsSize, int* returnSize){
	ShellSort(nums, numsSize);
	*returnSize = numsSize;
	return nums;
}