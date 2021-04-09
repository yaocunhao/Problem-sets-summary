27.二叉树的镜像

class Solution {
public:
    void TreeSwap(TreeNode* root)
    {
        if(root==NULL)
        return ;

        TreeSwap(root->left);
        TreeSwap(root->right);
        swap(root->left,root->right);//交换左右子树的指针
    }
    TreeNode* mirrorTree(TreeNode* root) {
        //总体思路就是，将整个树看做根节点，和两个左右子树
        //如果根节点为空则不许需要交换，如果不为空，则交换左右子树
     
        TreeSwap(root);
        return root;
    }
};