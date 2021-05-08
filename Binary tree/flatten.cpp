二叉树展开为链表

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==nullptr)
            return;
        
        flatten(root->left);
        flatten(root->right);

        //将右子树拼到左子树上
        TreeNode *left=root->left;
        if(left)
        {
        while(left->right)
        {
            left=left->right;
        }
        left->right=root->right;
        root->right=root->left;
        root->left=nullptr;
        }
    }
};