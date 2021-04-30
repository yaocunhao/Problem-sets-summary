class Solution {
public:
    int trap(vector<int>& height) {
        int sum=0;

        for(int i=1;i<(int)(height.size()-1);i++)//第一个，和最后一个柱子不需要求
        {
            int left_max=0;
            int right_max=0;
            for(int j=0;j<i;j++)//寻找当前柱子左侧的最大高度
            {
                if(left_max<height[j])
                   left_max=height[j];
            }
            for(int j=i+1;j<height.size();j++)//寻找当前柱子右侧的最大高度
            {
                if(right_max<height[j])
                    right_max=height[j];
            }
            int temp=fmin(left_max,right_max)-height[i];
            if(temp>0)//当前可以储水
            sum+=temp;
        }
        
        return sum;
    }
};



class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=1)
        return 0;

        vector<int> left;
        vector<int> right;

        int max=0;
        for(size_t i=1;i<height.size()-1;i++)
        {
            max=fmax(max,height[i-1]);//i-1等于当前列的新增左侧
            left.push_back(max);//保存起来
        }
        max=0;
        for(size_t i=height.size()-2;i>=1;i--)
        {
            max=fmax(max,height[i+1]);//i+1,为当前列的新增右列
            right.push_back(max);
        }

        reverse(right.begin(),right.end());//颠倒，当前右节点的值是倒过来的

        int sum=0;
        for(int i=0;i<left.size();i++)
        {
            int min=fmin(left[i],right[i])-height[i+1];//获取储水量
            if(min>0)
            sum+=min;
        }
        return sum;
    }
};
