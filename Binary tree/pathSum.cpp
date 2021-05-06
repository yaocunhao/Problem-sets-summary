
class Solution {
public:
    void _pathSum(TreeNode* root, int targetSum,int sum,int &count)
    {
        if(root==NULL)
            return;
        sum+=root->val;
        if(sum==targetSum)
            count++;
        
        _pathSum(root->left,targetSum,sum,count);
        _pathSum(root->right,targetSum,sum,count);
    }
    void __pathSum(TreeNode* root, int targetSum,int &count)
    {
        if(root==NULL)
            return;

        _pathSum(root,targetSum,0,count);
        __pathSum(root->left, targetSum,count);
        __pathSum(root->right, targetSum,count);
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        //前序遍历整颗树，当值相等时，路径计数器+1

        int count=0;
        __pathSum(root,targetSum,count);
        return count;
    }
};

作者：ych9527
链接：https://leetcode-cn.com/problems/path-sum-iii/solution/liang-ge-di-gui-ju-ran-guo-liao-ge-bi-xi-8ydc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。