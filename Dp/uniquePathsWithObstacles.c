//һ��������λ��һ�� m x n ��������Ͻ� ����ʼ������ͼ�б��Ϊ��Start�� ����
//
//������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ��Finish������
//
//���ڿ������������ϰ����ô�����Ͻǵ����½ǽ����ж�������ͬ��·����


//·��������֣�ֻ��Ҫ���ϰ��ﴦ����Ϊ0����


int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
	if (obstacleGrid[0][0] == 1)//�ſ����ϰ���
		return 0;

	int line = *obstacleGridColSize;
	int row = obstacleGridSize;

	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<line; j++)
		{
			if (obstacleGrid[i][j] == 1)//����ʯͷ
				obstacleGrid[i][j] = 0;
			else if (i == 0 && j == 0)
				obstacleGrid[i][j] = 1;//վ�Ų�����һ��
			else if (i == 0 || j == 0)
			{
				if (i == 0)
					obstacleGrid[i][j] = obstacleGrid[i][j - 1];//�����ϱ���
				else
					obstacleGrid[i][j] = obstacleGrid[i - 1][j];//���������
			}
			else// i,j����Ϊ��
			{
				obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
			}
		}
	}
	return obstacleGrid[row - 1][line - 1];

}
