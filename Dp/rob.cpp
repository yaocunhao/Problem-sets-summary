打家劫舍

class Solution {
public:
    int rob(vector<int>& nums) {
      if(nums.size()==1)
      return nums[0];
      if(nums.size()==2)
      return fmax(nums[0],nums[1]);

      vector<int> sum(nums.size(),0);
      sum[0]=nums[0];
      sum[1]=fmax(nums[0],nums[1]);

    //偷昨天的今天不能偷、偷前天的今天可以偷
    //比较两个值之间的大小，选择较大的
    //如果相等则今天不偷，明天可以继续偷
      for(int i=2;i<nums.size();i++)
      {
          sum[i]=fmax(sum[i-1],sum[i-2]+nums[i]);
      }

      return sum[nums.size()-1];
    }
};