//����78


void GetArray(int* nums, int numsSize, int* returnSize, int** returnColumnSizes, int **ret, int *temp, int temp_sub, int sub)
{
	ret[*returnSize] = (int *)malloc(sizeof(int*)*temp_sub);//������ָ���ڵ�һ��ָ�����ռ�,��һ�η�����ǿ�

	memcpy(ret[*returnSize], temp, sizeof(int)*temp_sub);//��һά������������뵽��ά����֮��

	(*returnColumnSizes)[*returnSize] = temp_sub;//���뵱ǰ��ά������һά�����Ԫ�ظ�������ǰ�Ӽ���Ԫ�ظ���

	(*returnSize)++;//returnSizeΪ��ά��������±꣬��ʾ��ά�������ж��ٸ�Ԫ��

	for (int i = sub; i < numsSize; i++)
	{
		temp[temp_sub] = nums[i];//�����Ӽ�

		GetArray(nums, numsSize, returnSize, returnColumnSizes, ret, temp, temp_sub + 1, i + 1);//i+1���뵱ǰ��

	}

}


int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{

	//**returnColumnSizes��ʾ���Ƕ�ά������ÿ��һά����Ԫ����Ԫ�صĸ���

	*returnColumnSizes = (int *)calloc(2000, sizeof(int));//������ָ���е�һ��ָ�����ռ䣬���ҳ�ʼ��Ϊ0

	int **ret = (int **)malloc(sizeof(int*)* 2000);//nums���10��Ԫ�أ�����......�ֽ�

	*returnSize = 0;//��ά�����У�һά����ĸ���

	int *temp = (int *)malloc(sizeof(int)* 10);//ÿ�ֽ������10��Ԫ��

	GetArray(nums, numsSize, returnSize, returnColumnSizes, ret, temp, 0, 0);

	return ret;
}