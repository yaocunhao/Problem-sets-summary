97. 交错字符串

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.size();
        int l2=s2.size();
        if(l1+l2!=s3.size())
        return false;

        vector<vector<bool>> dp(l1+1,vector<bool>(l2+1,false));
        dp[0][0] = true;

    //初始化第一行和第一列
        for(int i=1;i<=l1;i++)//只能由s1来匹配
            dp[i][0]=(dp[i-1][0]&&s3[i-1]==s1[i-1]);
       
        for(int j=1;j<=l2;j++)//只能由s2来匹配
            dp[0][j]=(dp[0][j-1]&&s3[j-1]==s2[j-1]);

    // 由 s1 或者 s2 来进行匹配
        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {  
                dp[i][j]=(dp[i-1][j]&&(s3[i+j-1]==s1[i-1]))||(dp[i][j-1]&&(s3[i+j-1]==s2[j-1]));
            }
        }
        return dp[l1][l2];
    }
};