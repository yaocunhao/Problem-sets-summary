���ۣ�46

void GetNum(int* nums, int *arr, int numsSize, int* returnSize, int** returnColumnSizes, int **ret, int *temp, int temp_sub)
{
	if (temp_sub == numsSize)//��Ԫ��������������������
	{
		ret[*returnSize] = (int*)malloc(sizeof(int)*numsSize);//������ָ���ڵ�һ��ָ�뿪�ٿռ�
		memcpy(ret[*returnSize], temp, sizeof(int)*numsSize);//�������
		(*returnColumnSizes)[*returnSize] = temp_sub;
		(*returnSize)++;//����������

		return;
	}

	for (int i = 0; i<numsSize; i++)
	{
		if (!arr[i])
		{
			temp[temp_sub] = nums[i];
			arr[i] = 1;//���б��
		}
		else
			continue;

		GetNum(nums, arr, numsSize, returnSize, returnColumnSizes, ret, temp, temp_sub + 1);

		arr[i] = 0;//ȡ�����
	}

}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

	int **ret = (int **)malloc(sizeof(int*)* 1000);
	*returnSize = 0;//������
	*returnColumnSizes = (int *)calloc(1000, sizeof(int));//������

	int *temp = (int *)malloc(sizeof(int)* 1000);//��ʱװ������Ԫ��

	int *arr = (int *)calloc(numsSize, sizeof(int));//������飬��0,1�����б��

	GetNum(nums, arr, numsSize, returnSize, returnColumnSizes, ret, temp, 0);

	return ret;

}