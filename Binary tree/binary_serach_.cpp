class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int>ret;
        TreeNode *Left=nullptr;
        if(root)
        {
            st.push(root);
            ret.push_back(root->val);
            Left=root->left;
        }
        while(!st.empty()||Left)
        {
            while(Left)//左子树不为空则一直走下去
            {
                ret.push_back(Left->val);
                st.push(Left);//将左子树入栈
                Left=Left->left;
            }
            //此时左子树全部走完,开始走右子树
            Left=st.top()->right;
            st.pop();
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ret;
        stack<TreeNode*>st;
        TreeNode* Left=nullptr;
        if(root)
        {
            st.push(root);
            Left=root->left;
        }
        while(!st.empty()||Left)
        {
            while(Left)
            {
                st.push(Left);//入栈
                Left=Left->left;//往左走
            }
            //此时左节点全在栈中
            Left=st.top();//从栈中拿值
            st.pop();
            ret.push_back(Left->val);//存值
            Left=Left->right;//往右走
        }
        return ret;
    }
};class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*>st;
        TreeNode* prev=nullptr;//记录上一个被访问过的节点
        TreeNode* Left=nullptr;
        if(root)
        {
            st.push(root);
            Left=root->left;
        }
        while(!st.empty()||Left)
        {
            while(Left)//将左子树全部入栈
            {
                st.push(Left);
                Left=Left->left;
            }
            TreeNode* node=st.top();//从栈中获取节点

            if(node->right==nullptr||node->right==prev)//右子树为空，或者已经访问过了
            {
                ret.push_back(node->val);
                prev=node;//记录下来
                st.pop();//出栈
            }
            else
                Left=node->right;//否则获取该节点的右子树
        }
        return ret;
    }
};