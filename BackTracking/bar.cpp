一个袋子有n个球


#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
//数组里面有n个数，可以移除数组内的数，数组内剩余元素的和>剩余元素的积的排列

void GetNum(vector<int>&arr,int &count,int sum,int mul,vector<bool> &flag,int sub)
{
    if(sum>mul)
        count++;
    else if(sum<mul&&sum!=0)
        return ;
    for(int i=sub;i<arr.size();i++)
    {
        if(i>0&&arr[i-1]==arr[i]&&flag[i-1]==false)//遇到重复的
               continue;
        flag[i]=true;
        sum+=arr[i];
        mul*=arr[i];
        GetNum(arr,count,sum,mul,flag,i+1);
        flag[i]=false;
        sum-=arr[i];
        mul/=arr[i];
    }
}

int main()
{
    int n;
    int val;
    while(cin>>n)
    {
      //准备工作  
        vector<int>arr;
        int count=0;

        while(cin>>val)
        {
            arr.push_back(val);
        }
        //此时获得的数组内有n个元素
        //将其进行组合起来，最少一个
        sort(arr.begin(),arr.end());
        vector<bool> flag(arr.size(),false);
        
        GetNum(arr,count,0,1,flag,0);
        cout<<count<<endl;
    }
 
    return  0;
}