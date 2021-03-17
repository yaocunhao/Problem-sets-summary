//力扣112题


bool GetSum(struct TreeNode* root, int targetSum, int count)
{
	if (root == NULL)//到达空节点说明上一节点不成立
		return false;

	count += root->val;//将当前的值相加

	if (root->left == NULL&&root->right == NULL&&count == targetSum)//到达叶子节点
		return true;


	return GetSum(root->left, targetSum, count) || GetSum(root->right, targetSum, count);
}

bool hasPathSum(struct TreeNode* root, int targetSum){

	//二叉树，首先确定一种遍历的方法，遍历一般都是前/中/后序递归
	//通过回溯剪枝的方法，如果当前路径上面的值，大于目标值则直接退出
	//回溯需要一个变量保存当前节点的值，如果下一节点不满足条件，则进行剪枝
	//由于这里条件特殊不能进行剪枝处理

	if (root == NULL)
		return false;

	int  count = 0;

	return GetSum(root, targetSum, count);

}