class Solution {
public:
    void _Convert(TreeNode* root,TreeNode*& prev)
    {
      if(root==nullptr)
          return ;
      _Convert(root->left,prev);
      
      root->left=prev;     
      if(prev)
        prev->right=root;
      
      prev=root;
      _Convert(root->right,prev);
    }
    TreeNode* Convert(TreeNode* pRootOfTree) {
      TreeNode *prev=nullptr;
      if(pRootOfTree==nullptr)
         return nullptr;
      TreeNode* head=pRootOfTree;
      while(head->left)//不断往左走，找到头节点
      {
        head=head->left;
      }
      _Convert(pRootOfTree,prev);
      return head;
      
        
    }
};
