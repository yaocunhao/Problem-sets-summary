剑指 Offer 68 - II. 二叉树的最近公共祖先


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;

        if(root==p||root==q)//找到一个节点
            return root;
        
       TreeNode *left = lowestCommonAncestor(root->left,p,q);
       TreeNode *right = lowestCommonAncestor(root->right,p,q);

        if(left&&right)//两个都不为空，说明当前节点为根节点
            return root;
        else if(left==NULL&&right!=NULL)//说明都在右子树 之中
            return right;
        else//说明在左子树之中
            return left;
    }
};