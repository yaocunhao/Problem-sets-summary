int uniquePaths(int m, int n){
	int(*arr)[n] = (int *)malloc(m*n*sizeof(int *));

	arr[0][0] = 1;
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			if (i == 0 || j == 0)//最上边或者最左边只有一条路可以走
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
		}
	}

	return arr[m - 1][n - 1];

}