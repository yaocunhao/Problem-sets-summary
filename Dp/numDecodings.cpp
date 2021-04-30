class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0||s[0]=='0')
        return 0;

        //最少有一个元素，且第一个元素不为0
        vector<int> dp(s.size(),0);
        dp[0]=1;

        for(int i=1;i<s.size();i++)
        {
            if(s[i]=='0')//只能与前面进行组合
            {
                if(s[i-1]>'2'||s[i-1]=='0')//不能进行组合
                return 0;

                if(i>=2)
                dp[i]=dp[i-2];
                else
                dp[i]=1;//第二个元素为0
            }
            else//s[i]!=0
            {
                if(s[i-1]=='1')//前面为1，
                   {
                       if(i-2>=0)
                       dp[i]=dp[i-1]+dp[i-2];
                       else
                       dp[i]=2;//当前为第二个元素
                   }
                else if(s[i-1]=='2'&&s[i]<='6')//前面为2
                    {
                        if(i-2>=0)
                        dp[i]=dp[i-1]+dp[i-2];
                        else
                        dp[i]=2;
                    }
                else
                dp[i]=dp[i-1];
            }
        }
        return dp[s.size()-1];
    }
};


class Solution {
public:
    int numDecodings(string s) {
        if(s.size()==0||s[0]=='0')
            return 0;
        //dp[i]=dp[i-1]+dp[i-2];
        int first=1;
        int second=1;
        int third=first;

        for(int i=1;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                if(s[i-1]=='0'||s[i-1]>'2')
                    return 0;
                else
                {
                    third=second;
                    second=first;
                    first=third;
                }
            }
            else//s[i]!+'0'
            {
                if(s[i-1]=='1')
                {
                    third=first+second;
                    second=first;
                    first=third;
                }
                else if(s[i-1]=='2'&&s[i]<='6')
                {
                    third=first+second;
                    second=first;
                    first=third;
                }
                else
                    {
                    third=first;
                    second=first;
                    first=second;
                    }
            }
        }
        return third;
    }
};
