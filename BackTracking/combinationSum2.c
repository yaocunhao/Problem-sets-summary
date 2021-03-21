力扣40.组合总和


void GetNum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int **ret, int *temp, int *flag, int temp_sub, int count, int sub)
{
	if (count>target)//都是正整数
		return;
	if (count == target)//满足条件的出口
	{
		ret[*returnSize] = (int *)malloc(sizeof(int)*temp_sub);//给二维数组的一维数组开辟空间
		memcpy(ret[*returnSize], temp, temp_sub*sizeof(int));//拷贝
		returnColumnSizes[0][*returnSize] = temp_sub;
		(*returnSize)++;
		return;
	}

	for (int i = sub; i<candidatesSize; i++)
	{
		if (i - 1 >= 0 && flag[i - 1] == 0 && candidates[i - 1] == candidates[i])
			continue;

		temp[temp_sub] = candidates[i];
		flag[i] = 1;//进行标记
		count += candidates[i];

		GetNum(candidates, candidatesSize, target, returnSize, returnColumnSizes, ret, temp, flag, temp_sub + 1, count, i + 1);
		count -= candidates[i];//回溯
		flag[i] = 0;//取消标记

	}

}

int Compar(int *x, int *y)
{
	return *x - *y;
}


int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){

	qsort(candidates, candidatesSize, sizeof(int), Compar);

	int **ret = (int **)malloc(sizeof(int*)* 1000);
	*returnSize = 0;
	*returnColumnSizes = (int *)calloc(1000, sizeof(int));
	int *temp = (int *)malloc(sizeof(int)* 1000);

	int flag[1000] = { 0 };

	GetNum(candidates, candidatesSize, target, returnSize, returnColumnSizes, ret, temp, flag, 0, 0, 0);

	return ret;
}