剑指 Offer 57 - II. 和为s的连续正数序列

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
       int begin=1;
       int end=1;
       int max=1;
       vector<vector<int>> ret;

        while(begin<=target/2)//begin如果超过target的一半，那么后面的值肯定不行了
        {
            if(max<target)
            {
                end++;
                max+=end;
            }

            else if(max>target)
            {
                begin++;
                end=begin;
                max=end;
            }
            else//相等
            {
                vector<int> temp;
                for(int i=begin;i<=end;i++)
                {
                    temp.push_back(i);
                }
                ret.push_back(temp);
                begin++;
                end=begin;
                max=end;
            }
        }
        return ret;

    }
};