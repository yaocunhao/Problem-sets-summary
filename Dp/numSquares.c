279,��ȫƽ����


int numSquares(int n){
	if (n == 0)
		return 0;

	int *ret = (int *)calloc(n + 1, sizeof(int));//0->n��n+1����

	double val = sqrt(n);


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= val; j++)
		{
			int num = i - (int)pow(j, 2);
			if (num >= 0)
			{
				if (num == 0)
					ret[i] = 1;//ֱ�Ӵ�0->i��Ϊһ�ַ���

				else if (ret[i] != 0 && ret[num] != 0)
					ret[i] = fmin(ret[i], ret[num] + 1);//ȡ��Сֵ

				else if (ret[i] == 0 && ret[num] != 0)//ֱ�ӵ���ǰ��ļ���һ����
					ret[i] = ret[num] + 1;

				//��������㣬˵��������
			}
		}
	}

	return ret[n];


}
