最长递增子序列

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ret(nums.size(),1);

        for(int i=1;i<nums.size();i++)
        {
            int sub=i-1;
            while(sub>=0)
            {
                if(nums[i]>nums[sub])
                {
                    ret[i]=fmax(ret[i],ret[sub]+1);
                }
                    sub--;
            }
        }
        int max=ret[0];
        for(int i=0;i<ret.size();i++)
        {
            max=fmax(max,ret[i]);
        }
        return max;
    }
};