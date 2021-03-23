322.零钱兑换


int coinChange(int* coins, int coinsSize, int amount){

	if (amount == 0)//总金额为0时，硬币个数为0，返回0
		return 0;

	int *ret = (int *)calloc(amount + 1, sizeof(int));


	for (int i = 0; i<amount + 1; i++)
	{
		for (int j = 0; j<coinsSize; j++)
		{

			if (i - coins[j] >= 0)//不越界且后面的位置是可以达到的
			{
				if (i - coins[j] == 0)
					ret[i] = 1;//一种硬币直接到达

				else if (ret[i] != 0 && ret[i - coins[j]] != 0)//当前不为零且前面不为零
					ret[i] = fmin(ret[i - coins[j]] + 1, ret[i]);//前面+1和后面的比较

				else if (ret[i] == 0, ret[i - coins[j]] != 0)//当前为零,前面的不为零
					ret[i] = 1 + ret[i - coins[j]];

				//前面如果为零，就到不了目前的位置
			}
		}
	}
	if (ret[amount] == 0)
		return -1;

	return ret[amount];
}