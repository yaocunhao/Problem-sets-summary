//����13

int movingCount(int m, int n, int k){

	//�������ܲ��ܵ���ĳλ�ã������¼���
	//1.��λ�õ����������Ƿ���Թ���
	//2.��λ�������Ƿ�<=k
	//ͨ��ѭ��������ܵ�ĳλ������Ϊ1����������Ϊ0������������ͳ��1�ĸ���


	int *arr[m];
	for (int i = 0; i<m; i++)
	{
		arr[i] = (int*)calloc(n, sizeof(int));
	}


	int ret = 1;//��һ�����ӿ϶�����

	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			int count = i % 10 + i / 10 + j % 10 + j / 10;//ͳ�������

			if (i == 0 && j == 0)//��һ�����ӣ��϶��ܵ�
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