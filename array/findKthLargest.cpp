215. 数组中的第K个最大元素

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> heap(nums.begin(),nums.begin()+k) ;//小堆

        for(int i=k;i<nums.size();i++)
        {
            if(nums[i]>heap.top())
            {
                heap.pop();
                heap.push(nums[i]);
            }
        }

        //此时heap中是nums中最大的k个元素构成的小堆
        return heap.top();

    }
};