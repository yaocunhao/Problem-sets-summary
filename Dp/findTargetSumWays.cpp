目标和
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //原问题转换:s1-s2=target -> 2s1=target + sum -> s1=(target+sum) /2
        //即从nums之中选取s1个数 = (target+sum)/2； sum(nums之中所有元素的总和)

        int sum=0;
        int count=0;
        for(auto &e:nums)
        {
            sum+=e;
        }
        if(target>sum||target<-sum)
            return count;
        
        if((sum+target)%2!=0)
            return 0;

        sum=(sum+target)/2;//得到"背包容量"
        
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1,0));
        dp[0][0]=1;//0个数字组成0

        //dp[0][n] //0个数字组成n，0种方法 
        //dp[n][0] //n个数字组成0 -> 有可能都是0，也可能不选

        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(nums[i]==0)//nums[i]==0时表示拿不拿都一样的 +0 -0 不拿三种情况
                    dp[i+1][j]=2*dp[i][j];
                else if(j-nums[i]>=0)
                    dp[i+1][j]=dp[i][j-nums[i]]+dp[i][j];//拿了和没拿的总和
                else
                    dp[i+1][j]=dp[i][j];//拿不了
            }
        }
        return dp[nums.size()][sum];

    }
};