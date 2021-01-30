void _Merge(int *arr, int begin1, int end1, int begin2, int end2, int *temp)
{

	int sub = begin1;

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
	memcpy(arr + begin1, temp + begin1, sizeof(int)*(end2 - begin1 + 1));
}
void MergeSortNoR(int *arr, int size)
{
	assert(arr);
	int *temp = (int *)malloc(sizeof(int)*size);

	int gap = 1;
	while (gap <size)
	{
		for (int i = 0; i < size; i += 2 * gap)//��ɵ�������
		{
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;

			if (begin2 >= size)//�ڶ��鲻����,����Ҫ�ϲ�
				break;
			if (end2 >= size)//�ڶ�����ڣ����ǲ�����
				end2 = size - 1;

			_Merge(arr, begin1, end1, begin2, end2, temp);//����[i,i+gap-1],[i+gap,i+2*gap-1]

		}

		gap *= 2;
		Print(arr, size);
	}
	free(temp);
}