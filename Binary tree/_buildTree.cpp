class Solution {
public:
    TreeNode* _buildTree(vector<int>&inorder,vector<int>&postorder,int &pos,int begin,int end)
    {
        int index=begin;
        while(index<end)
        {
            if(inorder[index]!=postorder[pos])//在中序之中寻找
                index++;
            else
                break;
        }
        //构造根节点
            TreeNode* root=new TreeNode(postorder[pos]);
        //划分区间，构建左右子树
        if(index+1<=end)
            root->right=_buildTree(inorder,postorder,--pos,index+1,end);//构造右子树
        if(begin<=index-1)
            root->left=_buildTree(inorder,postorder,--pos,begin,index-1);//构造左子树
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pos=postorder.size()-1;
        if(pos<0)//空树
            return nullptr;
        return _buildTree(inorder,postorder,pos,0,inorder.size()-1);
    }
};