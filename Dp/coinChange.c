322.��Ǯ�һ�


int coinChange(int* coins, int coinsSize, int amount){

	if (amount == 0)//�ܽ��Ϊ0ʱ��Ӳ�Ҹ���Ϊ0������0
		return 0;

	int *ret = (int *)calloc(amount + 1, sizeof(int));


	for (int i = 0; i<amount + 1; i++)
	{
		for (int j = 0; j<coinsSize; j++)
		{

			if (i - coins[j] >= 0)//��Խ���Һ����λ���ǿ��Դﵽ��
			{
				if (i - coins[j] == 0)
					ret[i] = 1;//һ��Ӳ��ֱ�ӵ���

				else if (ret[i] != 0 && ret[i - coins[j]] != 0)//��ǰ��Ϊ����ǰ�治Ϊ��
					ret[i] = fmin(ret[i - coins[j]] + 1, ret[i]);//ǰ��+1�ͺ���ıȽ�

				else if (ret[i] == 0, ret[i - coins[j]] != 0)//��ǰΪ��,ǰ��Ĳ�Ϊ��
					ret[i] = 1 + ret[i - coins[j]];

				//ǰ�����Ϊ�㣬�͵�����Ŀǰ��λ��
			}
		}
	}
	if (ret[amount] == 0)
		return -1;

	return ret[amount];
}