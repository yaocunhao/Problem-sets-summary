void _Merge(int *arr, int begin1, int end1, int begin2, int end2, int *temp)
{

	int sub = begin1;

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
	memcpy(arr + begin1, temp + begin1, sizeof(int)*(end2 - begin1 + 1));
}
void MergeSortNoR(int *arr, int size)
{
	assert(arr);
	int *temp = (int *)malloc(sizeof(int)*size);

	int gap = 1;
	while (gap <size)
	{
		for (int i = 0; i < size; i += 2 * gap)//完成单趟排序
		{
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;

			if (begin2 >= size)//第二组不存在,不需要合并
				break;
			if (end2 >= size)//第二组存在，但是不完整
				end2 = size - 1;

			_Merge(arr, begin1, end1, begin2, end2, temp);//区间[i,i+gap-1],[i+gap,i+2*gap-1]

		}

		gap *= 2;
		Print(arr, size);
	}
	free(temp);
}