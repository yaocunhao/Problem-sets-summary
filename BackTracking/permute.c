力扣：46

void GetNum(int* nums, int *arr, int numsSize, int* returnSize, int** returnColumnSizes, int **ret, int *temp, int temp_sub)
{
	if (temp_sub == numsSize)//当元素满足后填充至返回数组
	{
		ret[*returnSize] = (int*)malloc(sizeof(int)*numsSize);//给二级指针内的一级指针开辟空间
		memcpy(ret[*returnSize], temp, sizeof(int)*numsSize);//内容填充
		(*returnColumnSizes)[*returnSize] = temp_sub;
		(*returnSize)++;//行坐标下移

		return;
	}

	for (int i = 0; i<numsSize; i++)
	{
		if (!arr[i])
		{
			temp[temp_sub] = nums[i];
			arr[i] = 1;//进行标记
		}
		else
			continue;

		GetNum(nums, arr, numsSize, returnSize, returnColumnSizes, ret, temp, temp_sub + 1);

		arr[i] = 0;//取消标记
	}

}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

	int **ret = (int **)malloc(sizeof(int*)* 1000);
	*returnSize = 0;//行坐标
	*returnColumnSizes = (int *)calloc(1000, sizeof(int));//列坐标

	int *temp = (int *)malloc(sizeof(int)* 1000);//临时装纳数组元素

	int *arr = (int *)calloc(numsSize, sizeof(int));//标记数组，用0,1来进行标记

	GetNum(nums, arr, numsSize, returnSize, returnColumnSizes, ret, temp, 0);

	return ret;

}