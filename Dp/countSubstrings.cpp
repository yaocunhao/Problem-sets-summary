221. ���������

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){

	int line = *matrixColSize;


	for (int i = 0; i<matrixSize; i++)//matrix char ���ͣ�ע������
	{
		for (int j = 0; j<line; j++)
		{
			matrix[i][j] -= '0';//ת��������
		}
	}
	for (int i = 1; i<matrixSize; i++)//��1��ʼ������Ϊ�Ϻ���߽�Ϊ���½ǵ����������߳������Լ�
	{
		for (int j = 1; j<line; j++)
		{
			if (matrix[i][j] != 0)//�Լ�����Ϊ��
			{
				matrix[i][j] =
					((matrix[i - 1][j]>matrix[i][j - 1] ? matrix[i][j - 1] : matrix[i - 1][j])
	>matrix[i - 1][j - 1] ? matrix[i - 1][j - 1] :
	(matrix[i - 1][j]>matrix[i][j - 1] ? matrix[i][j - 1] : matrix[i - 1][j])) + 1;

			}
		}
	}
	int max = 0;
	for (int i = 0; i<matrixSize; i++)
	{
		for (int j = 0; j<line; j++)
		{
			max = matrix[i][j]>max ? matrix[i][j] : max;//�ҳ�����max
		}
	}

	return max*max;

}