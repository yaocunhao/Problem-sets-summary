216.组合总和3

void GetNum(int k, int n, int* returnSize, int** returnColumnSizes, int **ret, int *temp, int count, int temp_sub, int sub)
{
	if (count>n || temp_sub>k)//剪枝
		return;

	if (count == n&&temp_sub == k)//满足条件进行拷贝
	{
		ret[*returnSize] = (int *)malloc(sizeof(int)*k);//开空间
		memcpy(ret[*returnSize], temp, sizeof(int)*k);//拷贝
		returnColumnSizes[0][*returnSize] = k;//二维数组中一维数组元素个数
		(*returnSize)++;//二维数组行增加
		return;
	}

	for (int i = sub; i<10; i++)//元素1-9，且不出现重复元素
	{
		temp[temp_sub] = i;
		count += i;//计数器

		GetNum(k, n, returnSize, returnColumnSizes, ret, temp, count, temp_sub + 1, i + 1);//i+1保证不会出现重复元素

		count -= i;//回溯
	}

}
int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){

	//开辟数组
	int **ret = (int **)malloc(sizeof(int*)* 1000);
	*returnSize = 0;
	*returnColumnSizes = (int *)calloc(1000, sizeof(int));
	int *temp = (int *)malloc(sizeof(int)* 9);

	int count = 0;//计数器

	GetNum(k, n, returnSize, returnColumnSizes, ret, temp, count, 0, 1);

	return ret;

}