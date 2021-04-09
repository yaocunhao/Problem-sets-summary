剑指 Offer 32 - III. 从上到下打印二叉树 III


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==NULL)
        return ret;

        ret.resize(1200);
        int row=0;

        stack<TreeNode*> st1;
        stack<TreeNode*> st2;

        st1.push(root);//入栈

        while(!st1.empty()||!st2.empty())
        {
            while(!st1.empty())
            {
                TreeNode* temp=st1.top();
                st1.pop();

                if(temp->left)
                st2.push(temp->left);
                if(temp->right)
                st2.push(temp->right);

                ret[row].push_back(temp->val);
            }
            if(!st2.empty())
            row++;

             while(!st2.empty())
            {
                TreeNode* temp=st2.top();
                st2.pop();

                if(temp->right)
                st1.push(temp->right);
                if(temp->left)
                st1.push(temp->left);

                ret[row].push_back(temp->val);
            }
            if(!st1.empty())
            row++;
        }
        ret.resize(row+1);
        return ret;
    }
};