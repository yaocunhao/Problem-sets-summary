剑指 Offer 32 - I. 从上到下打印二叉树

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int>ret;
        if(root==NULL)
        return ret;

        queue<TreeNode*>q;

        q.push(root);//先根入队

        while(!q.empty())//判断队列是否为空
        {
            TreeNode* temp=q.front();//获取队首元素
            q.pop();//出队

            //入队
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);

            ret.push_back(temp->val);
        }
        return ret;
    }
};
