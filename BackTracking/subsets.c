//力扣78


void GetArray(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int **ret, int *temp, int temp_sub, int sub)
{
	ret[*returnSize] = (int *)malloc(sizeof(int*)*temp_sub);//给二级指针内的一级指针分配空间,第一次分配的是空

	memcpy(ret[*returnSize], temp, sizeof(int)*temp_sub);//将一维数组的内容填入到二维数组之中

	(*returnColumnSizes)[*returnSize] = temp_sub;//填入当前二维数组中一维数组的元素个数即当前子集的元素个数

	(*returnSize)++;//returnSize为二维数组的行下标，表示二维数组中有多少个元素

	for (int i = sub; i < numsSize; i++)
	{
		temp[temp_sub] = nums[i];//填入子集

		GetArray(nums, numsSize, returnSize, returnColumnSizes, ret, temp, temp_sub + 1, i + 1);//i+1不与当前第

	}

}


int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{

	//**returnColumnSizes表示的是二维数组中每个一维数组元素中元素的个数

	*returnColumnSizes = (int *)calloc(2000, sizeof(int));//给二级指针中的一级指针分配空间，并且初始化为0

	int **ret = (int **)malloc(sizeof(int*)* 2000);//nums最多10个元素，即有......种解

	*returnSize = 0;//二维数组中，一维数组的个数

	int *temp = (int *)malloc(sizeof(int)* 10);//每种解最多有10个元素

	GetArray(nums, numsSize, returnSize, returnColumnSizes, ret, temp, 0, 0);

	return ret;
}