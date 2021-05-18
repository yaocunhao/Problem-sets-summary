class Solution {
public:
    void _tree2str(TreeNode *root,string &str)
    {
        if(root==nullptr)
            return;
        str+=to_string(root->val);//加入值

        if(root->left==nullptr&&root->right==nullptr)//左右孩子都为空
            return ;
        
        str+='(';//左孩子括号始终要加上
        _tree2str(root->left,str);
        str+=')';

        if(root->right==nullptr)
            return ;
        str+='(';
        _tree2str(root->right,str);
        str+=')';
    }
    string tree2str(TreeNode* root) {
        string str;
        if(root==nullptr)
            return str;
        _tree2str(root,str);
        return str;
    }
};
