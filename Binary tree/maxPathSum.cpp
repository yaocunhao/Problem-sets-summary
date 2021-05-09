二叉树中的最大路径和

class Solution {
public:
    int _maxPathSum(TreeNode* root,int &count) 
    {
        if(root==nullptr)
            return 0;
        int left=_maxPathSum(root->left,count);
        int right=_maxPathSum(root->right,count);
        int val=root->val;
    //找出当前子树路径最大值
        int temp1=val+left+right;
        int temp2=val+left;
        int temp3=val+right;
        int temp4=fmax(temp1,fmax(temp2,temp3));
    //记录下来
        count=fmax(temp4,count);
    //判断对上层是否有贡献
        if(temp2<0&&temp3<0)
        {
            if(val<0)
            return 0;
            return val;
        }
        return fmax(temp2,temp3);
    }

    int maxPathSum(TreeNode* root) {
        int count=root->val;
        _maxPathSum(root,count);
        return count;
    }
};