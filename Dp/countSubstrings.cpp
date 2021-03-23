221. 最大正方形

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){

	int line = *matrixColSize;


	for (int i = 0; i<matrixSize; i++)//matrix char 类型，注意陷阱
	{
		for (int j = 0; j<line; j++)
		{
			matrix[i][j] -= '0';//转换成数字
		}
	}
	for (int i = 1; i<matrixSize; i++)//从1开始，是因为上和左边界为右下角的正方形最大边长就是自己
	{
		for (int j = 1; j<line; j++)
		{
			if (matrix[i][j] != 0)//自己不能为零
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
			max = matrix[i][j]>max ? matrix[i][j] : max;//找出最大的max
		}
	}

	return max*max;

}