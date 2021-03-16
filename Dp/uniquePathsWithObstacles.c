//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
//
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
//
//现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？


//路径问题变种，只需要将障碍物处，设为0即可


int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
	if (obstacleGrid[0][0] == 1)//门口是障碍物
		return 0;

	int line = *obstacleGridColSize;
	int row = obstacleGridSize;

	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<line; j++)
		{
			if (obstacleGrid[i][j] == 1)//遇到石头
				obstacleGrid[i][j] = 0;
			else if (i == 0 && j == 0)
				obstacleGrid[i][j] = 1;//站着不动算一种
			else if (i == 0 || j == 0)
			{
				if (i == 0)
					obstacleGrid[i][j] = obstacleGrid[i][j - 1];//靠着上边走
				else
					obstacleGrid[i][j] = obstacleGrid[i - 1][j];//靠着左边走
			}
			else// i,j都不为零
			{
				obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
			}
		}
	}
	return obstacleGrid[row - 1][line - 1];

}
