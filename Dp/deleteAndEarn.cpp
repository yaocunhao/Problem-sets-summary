删除并获得点数

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int min=nums[0];
        int max=nums[0];
        for(auto &e:nums)
        {
            min=fmin(e,min);
            max=fmax(e,max);
        }
        vector<int> arr(max-min+1,0);
        for(auto &e:nums)
        {
            arr[e-min]++;
        }

        if(arr.size()==1)
        return arr[0]*(min);
        if(arr.size()==2)
        return fmax(arr[0]*min,arr[1]*(min+1));

        int day1=arr[0]*(min);
        int day2=fmax(arr[0]*min,arr[1]*(min+1));
        int sum=day2;
        //当前位置删除 -> dp[i]+=dp[i-2]
        //当前位置不删除 -> dp[i]=dp[i-1]
        for(int i=2;i<arr.size();i++)
        {
            sum=fmax(day1+arr[i]*(i+min),day2);
            day1=day2;
            day2=sum;
        }

        return sum;

    }
};