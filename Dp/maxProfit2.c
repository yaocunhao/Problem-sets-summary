//假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？



//转移方程 dp[i]=max(dp[i],dp[i-1])
//当前利润==前一天利润和今天利润的最大值
int maxProfit(int* prices, int pricesSize){
	if (pricesSize == 0)
		return 0;

	int min = prices[0];//记录当前的最低价格
	int max = 0;//记录当前的最高利润

	for (int i = 0; i<pricesSize; i++)
	{
		if (prices[i] - min >= max)//记录当前最高利润
			max = prices[i] - min;

		if (prices[i]<min)//记录当前最小价格
			min = prices[i];
	}
	return max;

}