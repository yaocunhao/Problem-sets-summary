//�����ĳ��Ʊ�ļ۸���ʱ���Ⱥ�˳��洢�������У����������ù�Ʊһ�ο��ܻ�õ���������Ƕ��٣�



//ת�Ʒ��� dp[i]=max(dp[i],dp[i-1])
//��ǰ����==ǰһ������ͽ�����������ֵ
int maxProfit(int* prices, int pricesSize){
	if (pricesSize == 0)
		return 0;

	int min = prices[0];//��¼��ǰ����ͼ۸�
	int max = 0;//��¼��ǰ���������

	for (int i = 0; i<pricesSize; i++)
	{
		if (prices[i] - min >= max)//��¼��ǰ�������
			max = prices[i] - min;

		if (prices[i]<min)//��¼��ǰ��С�۸�
			min = prices[i];
	}
	return max;

}