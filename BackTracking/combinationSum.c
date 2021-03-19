力扣33题：组合总和

void GetNum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int **ret, int *temp, int temp_sub, int count, int sub)
{
	if (count == target)//达到满足条件
	{
		ret[*returnSize] = (int *)malloc(sizeof(int)*temp_sub);
		memcpy(ret[*returnSize], temp, temp_sub*sizeof(int));
		returnColumnSizes[0][*returnSize] = temp_sub;
		(*returnSize)++;
		return;
	}
	if (count>target)//剪枝
		return;

	for (int i = sub; i<candidatesSize; i++)
	{
		temp[temp_sub] = candidates[i];
		count += candidates[i];//计数器，记录当前数组内所有元素的总和

		//temp_sub+1,保证了数组内元素往后叠加，回溯时回到原来的位置
		//count保证了当前进行判断时，count内是当前数组内所有元素的总和
		//sub保证了调用的子函数也是从一样的位置开始出发 
		GetNum(candidates, candidatesSize, target, returnSize, returnColumnSizes, ret, temp, temp_sub + 1, count, i);
		count -= candidates[i];//回溯
	}
}

int Campa(const int *x, const int *y)
{
	return *x - *y;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){

	qsort(candidates, candidatesSize, sizeof(int), Campa);//排序

	//准备二维数组
	int **ret = (int **)malloc(sizeof(int*)* 1000);
	*returnColumnSizes = (int *)calloc(1000, sizeof(int));
	*returnSize = 0;

	int *temp = (int *)malloc(sizeof(int)* 1000);//临时数组
	int count = 0;//计数器

	GetNum(candidates, candidatesSize, target, returnSize, returnColumnSizes, ret, temp, 0, 0, 0);

	return ret;

}
