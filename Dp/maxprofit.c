
int maxProfit(int* prices, int pricesSize){
    if(pricesSize==0)
    return 0;
    int min=prices[0];
    for(int i=pricesSize-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(prices[j]<min)
                min=prices[j];//找到最小值
        }
        prices[i]=prices[i]-min;//转移方程
        min=prices[0];//计数器复位
    }

    int max=0;
    for(int i=1;i<pricesSize;i++)
        {
            if(prices[i]>max)
                max=prices[i];//找到数组中的最大值
        }

    return max;

}
