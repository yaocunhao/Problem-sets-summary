//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
//如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//你可以假设数组中无重复元素。

//解题思路：看到有序查找首先想到的是二分查找，我们通过二分查找可以直接找到对应的值，如果存在的话
//如果对应的值不存在，那么我们可以巧妙的利用mid下标，如果nums[mid]>target说明，从mid下标开始
//整体数组需要往后挪，然后target插入在mid下标这里
//如果，nums[mid]<target，说明应该插入在mid的下一个位置

int searchInsert(int* nums, int numsSize, int target){
	int left = 0;
	int right = numsSize - 1;
	int mid = left + (right - left) / 2;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid]>target)
			right = mid - 1;
		else if (nums[mid]<target)
			left = mid + 1;
		else
			return mid;
	}

	//没有找到
	if (nums[mid]>target)
		return mid;

	return mid + 1;
}