给你一个整数数组 nums，请你将该数组升序排列。

解法：利用希尔排序对数组进行排序


void ShellSort(int *arr, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//每次的步距为gap
		for (int i = 0; i < size - gap; i++)
		{
			int end = i;//有序的最后一个元素的下标
			int key = arr[end + gap];
			while (end >= 0 && arr[end]>key)
			{
				arr[end + gap] = arr[end];//往后挪动一个位置
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