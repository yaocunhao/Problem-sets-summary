class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        //假设a是最小的那个数，那么不论a与谁进行组合，a都会被加入，和它组队的那个就会被舍弃
        //所以，要挑一个第二小的数与a进行组合

        sort(nums.begin(),nums.end());
        int sum=0;

        for(int i=0;i<nums.size();i+=2)
        {
            sum+=nums[i];
        }
        return sum;

    }
};