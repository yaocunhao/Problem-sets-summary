260. 只出现一次的数字 III

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
  
        int val=0;
        for(auto e:nums )
        {
            val^=e;//得到全部异或的值
        }
        if(val==0)
        return  nums;

        int count=0;
        while(1)//找到bit为1的位置
        {
            if((val>>count)&1==1)
            break;
            count++;
        }

        int num1=0;
        int num2=0;
        for(auto e:nums)//分为两组进行异或
        {
            if((e>>count)&1==1)
            num1^=e;
            else
            num2^=e;
        }

        vector<int> ret;      
        ret.push_back(num1);
        ret.push_back(num2);

        return ret;
    }
};

