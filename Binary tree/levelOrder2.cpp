剑指 Offer 32 - II. 从上到下打印二叉树 II

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ret;
        if(root==NULL)
        return ret;

        int sub_1=0;
        int sub_2=0;
        vector<vector<TreeNode*>>cur;

        cur.resize(1200);
        cur[0].push_back(root);//根入类

        queue<vector<TreeNode*>>q;
        q.push(cur[sub_1]);//入队,将每层放进去
        ret.resize(1);//返回类开辟空间


        while(!q.empty())
        {
            TreeNode* temp=q.front()[sub_2++];//取出元素,sub_2控制vector<treenode*>的下标
             
                    //先入对应层
                    if(temp->left)
                    cur[sub_1+1].push_back(temp->left);
                    if(temp->right)
                    cur[sub_1+1].push_back(temp->right);


                ret[sub_1].push_back(temp->val);//存值

                if(sub_2==cur[sub_1].size())//当前vector元素全部取出,将vector出队
             {
                 q.pop();//出队

                 if(cur[sub_1+1].size())//如果下一层不为空则入队，并且给返回类加一个空间
                {
                     q.push(cur[sub_1+1]);//将新的元素入队
                    ret.resize(ret.size()+1);//增加一个空间
                }

                 sub_2=0;//复位
                 sub_1++;//到下一层              
             }
        }

        return ret;
    }
};