剑指 Offer 59 - I. 滑动窗口的最大值

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if(nums.size()==0)
        return ret;
        deque<int> qe;

        for(int i=0;i<nums.size();i++)
        {
            while(!qe.empty() && nums[i]>nums[qe.back()])//删除小于当前入队的元素,前面的元素不会再用到，先出队列
                qe.pop_back();
            
            if(!qe.empty() && i-qe.front()>=k)//qe中保存的是下标，那么此时入队的下标，与其差值==k，说明要出队了
                qe.pop_front();
            
            qe.push_back(i);//将下标入队，因为要比较保头节点是否“过期”
            
            
            if(i>=k-1)//开始入返回数组
            ret.push_back(nums[qe.front()]);
        
        }
        return ret;

    }
};
