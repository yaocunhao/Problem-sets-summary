力扣47题

void GetNum(int *nums, int *arr, int *temp, int numsSize, int *returnSize, int **returnColumnSizes, int **ret, int temp_sub)
{
	if (temp_sub == numsSize)
	{
		ret[*returnSize] = (int *)malloc(sizeof(int)*numsSize);
		memcpy(ret[*returnSize], temp, sizeof(int)*numsSize);
		returnColumnSizes[0][*returnSize] = numsSize;
		(*returnSize)++;

		return;
	}

	for (int i = 0; i<numsSize; i++)
	{
		if (i - 1 >= 0 && arr[i - 1] == 0 && nums[i - 1] == nums[i])//重复元素，剪枝
			continue;

		if (!arr[i])
		{
			temp[temp_sub] = nums[i];
			arr[i] = 1;
		}
		else
			continue;

		GetNum(nums, arr, temp, numsSize, returnSize, returnColumnSizes, ret, temp_sub + 1);
		arr[i] = 0;


	}
}

int  ComInt(const int *x, const int *y)//,传进来的是一个序列之中，任意一个元素的地址
{
	return *x - *y;
}


int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

	qsort(nums, numsSize, sizeof(int), ComInt);


	int **ret = (int **)malloc(sizeof(int)* 2000);
	*returnSize = 0;
	*returnColumnSizes = (int *)calloc(2000, sizeof(int));
	int *temp = (int*)malloc(sizeof(int)* 2000);

	int *arr = (int *)calloc(2000, sizeof(int));//标记数组

	GetNum(nums, arr, temp, numsSize, returnSize, returnColumnSizes, ret, 0);

	return ret;

}