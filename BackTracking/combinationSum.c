����33�⣺����ܺ�

void GetNum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, int **ret, int *temp, int temp_sub, int count, int sub)
{
	if (count == target)//�ﵽ��������
	{
		ret[*returnSize] = (int *)malloc(sizeof(int)*temp_sub);
		memcpy(ret[*returnSize], temp, temp_sub*sizeof(int));
		returnColumnSizes[0][*returnSize] = temp_sub;
		(*returnSize)++;
		return;
	}
	if (count>target)//��֦
		return;

	for (int i = sub; i<candidatesSize; i++)
	{
		temp[temp_sub] = candidates[i];
		count += candidates[i];//����������¼��ǰ����������Ԫ�ص��ܺ�

		//temp_sub+1,��֤��������Ԫ��������ӣ�����ʱ�ص�ԭ����λ��
		//count��֤�˵�ǰ�����ж�ʱ��count���ǵ�ǰ����������Ԫ�ص��ܺ�
		//sub��֤�˵��õ��Ӻ���Ҳ�Ǵ�һ����λ�ÿ�ʼ���� 
		GetNum(candidates, candidatesSize, target, returnSize, returnColumnSizes, ret, temp, temp_sub + 1, count, i);
		count -= candidates[i];//����
	}
}

int Campa(const int *x, const int *y)
{
	return *x - *y;
}

int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){

	qsort(candidates, candidatesSize, sizeof(int), Campa);//����

	//׼����ά����
	int **ret = (int **)malloc(sizeof(int*)* 1000);
	*returnColumnSizes = (int *)calloc(1000, sizeof(int));
	*returnSize = 0;

	int *temp = (int *)malloc(sizeof(int)* 1000);//��ʱ����
	int count = 0;//������

	GetNum(candidates, candidatesSize, target, returnSize, returnColumnSizes, ret, temp, 0, 0, 0);

	return ret;

}
