零钱兑换 II
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        dp[0]=1;//组成金额为0的总数为1种

        for(int i=0;i<coins.size();i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(j-coins[i]>=0)//表示可以选
                    dp[j]=dp[j-coins[i]]+dp[j];
            }
        }
        return dp[amount];
    }
};