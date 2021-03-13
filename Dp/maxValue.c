//在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你
//可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
//给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？


利用动态规划，将当前的最大礼物价值保存在数组里面，直接利用原数组，不用开辟空间

int maxValue(int** grid, int gridSize, int* gridColSize){
	int n = *gridColSize;

	for (int i = 0; i<gridSize; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (i - 1 >= 0 && j - 1 >= 0)//不是处于边界
			{
				grid[i][j] += fmax(grid[i - 1][j], grid[i][j - 1]);
			}
			else//只能往下或者往右
			{
				if (i - 1 >= 0)
					grid[i][j] += grid[i - 1][j];
				else if (j - 1 >= 0)
					grid[i][j] += grid[i][j - 1];
			}
		}
	}
	return grid[gridSize - 1][n - 1];
}