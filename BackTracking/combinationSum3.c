216.����ܺ�3

void GetNum(int k, int n, int* returnSize, int** returnColumnSizes, int **ret, int *temp, int count, int temp_sub, int sub)
{
	if (count>n || temp_sub>k)//��֦
		return;

	if (count == n&&temp_sub == k)//�����������п���
	{
		ret[*returnSize] = (int *)malloc(sizeof(int)*k);//���ռ�
		memcpy(ret[*returnSize], temp, sizeof(int)*k);//����
		returnColumnSizes[0][*returnSize] = k;//��ά������һά����Ԫ�ظ���
		(*returnSize)++;//��ά����������
		return;
	}

	for (int i = sub; i<10; i++)//Ԫ��1-9���Ҳ������ظ�Ԫ��
	{
		temp[temp_sub] = i;
		count += i;//������

		GetNum(k, n, returnSize, returnColumnSizes, ret, temp, count, temp_sub + 1, i + 1);//i+1��֤��������ظ�Ԫ��

		count -= i;//����
	}

}
int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){

	//��������
	int **ret = (int **)malloc(sizeof(int*)* 1000);
	*returnSize = 0;
	*returnColumnSizes = (int *)calloc(1000, sizeof(int));
	int *temp = (int *)malloc(sizeof(int)* 9);

	int count = 0;//������

	GetNum(k, n, returnSize, returnColumnSizes, ret, temp, count, 0, 1);

	return ret;

}