//实现 int sqrt(int x) 函数。
//计算并返回 x 的平方根，其中 x 是非负整数。
//由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

//
//解法：利用二分查找，下边界为0，上边界为x，需要注意的是越界问题
//因此不能用mid*mid和x进行比较，而是mid和x/mid进行比较从而防止越界
//
//二分查找出来的mid，如果正好是对应的值则直接返回，如果不是，那么mid*mid要么大于x，要么小于x(最接近)
//因此只需要判断当前mid*mid是否大于x，如果大于则返回mid-1，如果不大于则直接返回，因为只要求返回整数部分

int mySqrt(int x){

	int left = 0;
	int right = x;
	int mid = left + (right - left) / 2;
	if (mid == 0)//为零或者1时
		return x;

	while (left <= right)
	{
		mid = left + (right - left) / 2;

		if (mid>x / mid) //mid*mid>x,换种写法防止越界
			right = mid - 1;
		else if (mid<x / mid)
			left = mid + 1;
		else
			return mid;
	}
	if (mid>x / mid)
		return mid - 1;

	return mid;

}