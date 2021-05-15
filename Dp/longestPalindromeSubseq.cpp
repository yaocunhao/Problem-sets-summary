最长回文子序列
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //dp[i][j]表示j-i的回文串之中字符的个数
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        int max=0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j>=0;j--)
            {
                if(i==j)
                    dp[i][j]=1;//一个字符时
                else if(s[i]==s[j])
                    dp[i][j]=dp[i-1][j+1]+2;//中间回文串的个数+2
                else//不是回文串
                    dp[i][j]=fmax(dp[i][j+1],dp[i-1][j]);

                max=fmax(max,dp[i][j]);
            }
        }
        return max;
    }
};