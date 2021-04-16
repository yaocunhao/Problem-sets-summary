剑指 Offer 49. 丑数

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n,0);

        dp[0]=1;
        int two=0,there=0,five=0;

        for(int i=1;i<n;i++)
        {
            int num_two=dp[two]*2;
            int num_there=dp[there]*3;
            int num_five=dp[five]*5;
            dp[i]=fmin(fmin(num_two,num_there),num_five);//转移方程

        //当前下标乘(2,3,5)，已经用过当中的哪一个了值了
            if(dp[i]==num_two)
                two++;
            if(dp[i]==num_there)
                there++;
            if(dp[i]==num_five)
                five++;
        }
        return dp[n-1];
    }
};