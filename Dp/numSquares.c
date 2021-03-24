279,完全平方数


int numSquares(int n){
	if (n == 0)
		return 0;

	int *ret = (int *)calloc(n + 1, sizeof(int));//0->n，n+1个数

	double val = sqrt(n);


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= val; j++)
		{
			int num = i - (int)pow(j, 2);
			if (num >= 0)
			{
				if (num == 0)
					ret[i] = 1;//直接从0->i，为一种方法

				else if (ret[i] != 0 && ret[num] != 0)
					ret[i] = fmin(ret[i], ret[num] + 1);//取较小值

				else if (ret[i] == 0 && ret[num] != 0)//直接等于前面的加上一个数
					ret[i] = ret[num] + 1;

				//如果等于零，说明来不了
			}
		}
	}

	return ret[n];


}
