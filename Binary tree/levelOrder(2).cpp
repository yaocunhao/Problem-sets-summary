剑指 Offer 32 - II. 从上到下打印二叉树 II

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ret;
        int row=0;//记录行号
       
        if(root==NULL)
        return ret;

        queue<TreeNode*> q_1;
        queue<TreeNode*> q_2;

        q_1.push(root);
        ret.resize(1200);//开辟空间
        

        while(!q_1.empty()||!q_2.empty())//一个队列不为空就继续
        {
            while(!q_1.empty())
            {
                TreeNode* temp=q_1.front();
                q_1.pop();//出队

                if(temp->left)
                q_2.push(temp->left);
                if(temp->right)
                q_2.push(temp->right);

                ret[row].push_back(temp->val);
            }
            if(!q_2.empty())
            row++;//换行，进入下一行

            while(!q_2.empty())
            {
                TreeNode* temp=q_2.front();
                q_2.pop();//出队

                if(temp->left)
                q_1.push(temp->left);
                if(temp->right)
                q_1.push(temp->right);
                
                ret[row].push_back(temp->val);
            }
            if(!q_1.empty())
            row++;//换行
        }

        ret.resize(row+1);//去除后面的空成员
        return ret;

    }
};