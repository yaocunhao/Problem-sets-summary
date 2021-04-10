剑指 Offer 68 - I. 二叉搜索树的最近公共祖先

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val>p->val&&root->val>q->val)//说明两个节点都在当前节点的左边
            return lowestCommonAncestor(root->left,p,q);//转移到左子树

        else if(root->val<p->val&&root->val<q->val)//说明两个节点都在当前节点的右边
            return lowestCommonAncestor(root->right,p,q);//转移到右子树
        else
        return root;
        
    }
};