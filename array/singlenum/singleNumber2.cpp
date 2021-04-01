137.只出现一次的数字2
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret=0; 
        for(int i=0;i<32;i++)
        {
            int temp=0;
            for(auto e:nums)
            {
                temp+=(e>>i)&1;
            }
            ret+=(temp%3)<<i;
        }
        return ret;
    }
};