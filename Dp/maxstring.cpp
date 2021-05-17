#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  string str1;
  string str2;
  while(cin>>str1)
  {
    cin>>str2;
    if(str1.size()<str2.size())
        str1.swap(str2);//保证str1为较长串
    int len1=str1.size();
    int len2=str2.size();
    string str;
    
    vector<vector<int>>dp(len2+1,vector<int>(len1+1,0));
    
    for(int i=0;i<len2;i++)
    {
      for(int j=0;j<len1;j++)
      {
        if(str2[i]==str1[j])
        {
          dp[i+1][j+1]=dp[i][j]+1;
          if(dp[i+1][j+1]>str.size())//新的较长子串
          {
            int begin=i-dp[i+1][j+1]+1;//相同子串的起始位置
            string temp(str2.begin()+begin,str2.begin()+i+1);
            str.swap(temp);//获得新的子串
          }
        }
        else
          dp[i+1][j+1]=0;//不相等
      }
    }
    cout<<str<<endl;
  }
  return 0;
}