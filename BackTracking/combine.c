����77�⣺

void GetNum(int n, int k, int * returnSize, int **returnColumnSizes, int *temp, int **ret, int temp_sub, int sub)
{
	if (temp_sub == k)//���������������鿽������������
	{
		ret[*returnSize] = (int *)malloc(sizeof(int)*k);
		memcpy(ret[*returnSize], temp, sizeof(int)*k);
		returnColumnSizes[0][*returnSize] = k;
		(*returnSize)++;
		return;
	}

	for (int i = sub; i <= n; i++)
	{
		temp[temp_sub] = i;

		GetNum(n, k, returnSize, returnColumnSizes, temp, ret, temp_sub + 1, i + 1);//i+1��֤����������
	}

}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){

	//׼����ά����
	int **ret = (int **)malloc(sizeof(int)* 15000);
	*returnSize = 0;
	*returnColumnSizes = (int *)malloc(sizeof(int)* 15000);

	int *temp = (int *)malloc(sizeof(int)*k);//��ʱ����K����������

	GetNum(n, k, returnSize, returnColumnSizes, temp, ret, 0, 1);

	return ret;

}