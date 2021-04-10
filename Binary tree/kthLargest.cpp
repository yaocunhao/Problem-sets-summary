剑指 Offer 54. 二叉搜索树的第k大节点

class Solution {
public:
    void GetNum(TreeNode* root,int *k,int *num)
    {
        if(root==NULL|| *k==0)
        return ;

        //第k大，右根左得到降序数组
        GetNum(root->right,k,num);
        if(0==*k)
        return ;

        (*k)--;     
        if(0==*k)
        {
            *num=root->val;
            return ;
        }

        GetNum(root->left,k,num);
    }

    int kthLargest(TreeNode* root, int k) {

        int num=0;
       GetNum(root,&k,&num);

        return num;
    }
};