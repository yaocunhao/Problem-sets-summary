剑指 Offer 60. n个骰子的点数

class Solution {
public:
    vector<double> dicesProbability(int n) {
        //下一个骰子出现的所有点数=前面的一个筛子[+1+2+3+4+5+6];
        //每多一颗骰子，空间比前面需要多五个
        
        vector<vector<double>> dp;//建立动规数组
        dp.resize(n);//开辟n个二维空间

        for(int i=0;i<6;i++)//将只有一颗骰子时的所有概率初始化
        {
            dp[0].push_back(1.0/6.0);
        }

        for(int i=1;i<n;i++)//控制骰子数
        {
            dp[i].resize(dp[i-1].size()+5,0);//多五个空间，并且全部初始化为0

            for(int j=1;j<=6;j++)//控制点数
            {  
                int sub=j-1;//控制从第几个位置开始加起来
               
                 for(int k=0;k<dp[i-1].size();k++)//控制上一层所有的概率
                {
                    dp[i][sub++]+=dp[i-1][k]*1.0/6.0;
                }
            }
        }

        return dp[n-1];
    }
};