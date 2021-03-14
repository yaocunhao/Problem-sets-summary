
三步问题。有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶或3阶。
实现一种方法，计算小孩有多少种上楼梯的方式。结果可能很大，你需要对结果模1000000007。


//典型的动态规划，可以和前面的硬币问题对比，这里是要求顺序的，硬币问题是求组合不要重复的


//class Solution {
//public:
//	int waysToStep(int n) {
//		int *arr = new int[n + 1];
//		memset(arr, 0, sizeof(int)*(n + 1));
//		arr[0] = 1;//第零阶时站这不动一种方法
//		int num[3] = { 1, 2, 3 };
//
//		for (int i = 1; i<n + 1; i++)
//		{
//			for (int j = 0; j<3; j++)
//			{
//				if (i - num[j] >= 0)
//					arr[i] = (arr[i] + arr[i - num[j]]) % 1000000007;
//			}
//		}
//		return arr[n];
//	}
//};

不需要额外空间：
class Solution {
public:
	int waysToStep(int n) {
		if (n <= 2)//台阶数小于等于2
			return n;
		if (n == 3)
			return 4;

		//先求出前面3步的数
		int dp1 = 1;
		int dp2 = 2;
		int dp3 = 4;

		//由于步伐是1,2,3,因此具有特殊性，即每次的步伐都等于前面3次相加
		int dp = 0;
		for (int i = 4; i <= n; i++)//后面的总数，始终等于前面三步相加
		{
			dp = ((dp1 + dp2) % 1000000007 + dp3) % 1000000007;
			dp1 = dp2;
			dp2 = dp3;
			dp3 = dp;
		}
		return dp;
	}

};