验证二叉搜索树

class Solution {
public:
    bool _isvalidBST(TreeNode *root,stack<int> &ret)
    {
        if(root==NULL)
            return true;
        
       bool left= _isvalidBST(root->left,ret);

        if(ret.empty())
        ret.push(root->val);
        else
       {
         if(root->val<=ret.top())
         return false;
         ret.pop();
         ret.push(root->val);
        }

       return left&&_isvalidBST(root->right,ret);
    }
    bool isValidBST(TreeNode* root) {
       stack<int> ret;
        return _isvalidBST(root,ret);
    }
};