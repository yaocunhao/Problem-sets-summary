#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//
//给定数量不限的硬币，币值为25分、10分、5分和1分，
//编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)

//
//分解方程为：硬币总值到达n的时候，最后一枚硬肯定是1、10、5、25其中的一枚
//此时f(n) = f(n - 1) + f(n - 5) + f(n - 10) + f(n - 25)
//想要计算出f(n)就得先计算出前面的，因此计算顺序为f(1), f(2), f(3)........f(n)




int waysToChange(int n){

	int div = 1000000007;
	int *ret = (int *)calloc(n+1,sizeof(int));//装每种金额能有几种方法，从零开始，因此是n+1个空间

	ret[0] = 1;//当n-1/5/10/25==0的时候，此时一枚硬币就能完成，也是一种方法

	int coins[] = { 1, 5, 10, 25 };//四种硬币

	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j <= n; j++)//算每种钱差当前硬币为最后一枚
		{
			if (j - coins[i] >= 0)//解决出界问题
			{
				ret[j] =(ret[j - coins[i]] + ret[j]) % div;
			}
		}
	}
	return ret[n];

}
int main()
{

	int ret = waysToChange(10);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
