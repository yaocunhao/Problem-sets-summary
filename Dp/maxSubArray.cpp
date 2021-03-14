//输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
//要求时间复杂度为O(n)。

//思路：数组中求最值，典型的动态规划问题，
//转移方程：如果dp[i - 1] <= 0说明它对dp[i]没有贡献，则不需要理会
//如果大于零说明是有贡献的，则需要相加，同时给一个变量，记录下每一次相加后的结果中的最大值；


int maxSubArray(int* nums, int numsSize){
	int max = nums[0];

	for (int i = 0; i<numsSize - 1; i++)
	{
		if (nums[i]>0)//只有当前元素为正时，才能给下一个元素做出贡献
			nums[i + 1] = nums[i] + nums[i + 1];

		if (nums[i + 1]>max)
			max = nums[i + 1];
	}
	return max;

}