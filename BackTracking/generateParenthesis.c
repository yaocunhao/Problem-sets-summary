22.��������

void Get(char**ret, char *temp, int *returnSize, int n, int left, int right, int sub)
{
	if (left>n || right>n)//����һ�������ƥ��
	{
		return;
	}

	if (left == right&&left + right == 2 * n)//���������������ӵ�����������
	{
		ret[*returnSize] = (char *)malloc(sizeof(char)*(2 * n + 1));//���ٿռ䣬\0���ռ�
		memcpy(ret[*returnSize], temp, sizeof(char)*n * 2);
		ret[*returnSize][2 * n] = '\0';//��ֹ��
		(*returnSize)++;
		return;
	}

	//����ʱ����֮����������

	if (left<n)
	{
		temp[sub] = '(';
		Get(ret, temp, returnSize, n, left + 1, right, sub + 1);
	}

	if (right<left)
	{
		temp[sub] = ')';
		Get(ret, temp, returnSize, n, left, right + 1, sub + 1);
	}

}



char ** generateParenthesis(int n, int* returnSize){

	//�����㷨ʵ�֣�ͨ����״�ṹ����������������¼�����ź������ŵ���
	//��������ŵ��������������ţ�����м�֦����
	//һ��ʼȫ��������

	char **ret = (char **)malloc(sizeof(char*)* 2000);
	char *temp = (char *)malloc(sizeof(char)*(n * 2 + 1));//ÿ��һά�������ж������ţ���Ҫ��\0���ٿռ�
	*returnSize = 0;


	Get(ret, temp, returnSize, n, 0, 0, 0);

	return ret;

}