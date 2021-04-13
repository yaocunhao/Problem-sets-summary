剑指 Offer 33. 二叉搜索树的后序遍历序列

class Solution {
public:
    bool Judge(vector<int>& postorder,int begin,int end)
    {
        if(begin>=end)//叶子节点，肯定满足条件
        return true;

        int max=end;//根节点的值
        for(int i=begin;i<end;i++)
        {
            if(postorder[i]>postorder[max])
            {
                max=i;//第一个大于于根节点值的坐标
                break;
            }
        }
        for(int i=max;i<end;i++)//右子树区间全部要大于根的值
        {
            if(postorder[i]<postorder[end])
            return false;
        }

        return Judge(postorder,begin,max-1)&&Judge(postorder,max,end-1);

    }
    bool verifyPostorder(vector<int>& postorder) {
        
        return Judge(postorder,0,postorder.size()-1);

    }
};