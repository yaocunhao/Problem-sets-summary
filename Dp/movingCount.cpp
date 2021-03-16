//剑：13

int movingCount(int m, int n, int k){

	//机器人能不能到达某位置，有以下几点
	//1.该位置的上下左右是否可以过来
	//2.该位置坐标是否<=k
	//通过循环，如果能到某位置设置为1，不能设置为0，最后遍历数组统计1的个数


	int *arr[m];
	for (int i = 0; i<m; i++)
	{
		arr[i] = (int*)calloc(n, sizeof(int));
	}


	int ret = 1;//第一个格子肯定可以

	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			int count = i % 10 + i / 10 + j % 10 + j / 10;//统计坐标和

			if (i == 0 && j == 0)//第一个格子，肯定能到
				arr[0][0] = 1;
			else
			{
				if (((i - 1 >= 0 && arr[i - 1][j] != 0) || (i + 1<m&&arr[i + 1][j] != 0) || (j - 1 >= 0 && arr[i][j - 1] != 0) ||
					(j + 1<n&&arr[i][j + 1] != 0)) && count <= k)
				{
					arr[i][j] = 1;
					ret++;
				}
			}
		}
	}

	return ret;

}