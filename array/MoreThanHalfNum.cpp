数组中超过一半的元素

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size()==0)//没有数字
            return 0;
        
        int prev=numbers[0];
        int count=1;
        for(int i=1;i<numbers.size();i++)
        {
            if(count==0)
                prev=numbers[i];
            if(numbers[i]==prev)
                count++;
            else
            {
                count--;
                if(count==0)
                    prev=0;
            }
        }
        if(count==0)//不存在
            return prev;
       
        count=0;
        for(int i=0;i<numbers.size();i++)
        {
            if(prev==numbers[i])
                count++;
        }
        if(count>numbers.size()/2)
            return prev;
        return 0;
    
    }
};