
平衡二叉树的优化解法，利用后续进行计算，时间复杂度为O(N^2)

bool _isBalanced(struct TreeNode *root, int *depth)
{
	if (root == NULL)
	{
		*depth = 0;
		return true;
	}

	int LetfDepth = 0;
	if (_isBalanced(root->left, &LetfDepth) == false)//左子树
		return false;//如果不满足平衡条件则直接返回

	int RightDepth = 0;
	if (_isBalanced(root->right, &RightDepth) == false)//右子树
		return false;

	if (abs(LetfDepth - RightDepth)>1)//判断当前节点是否满足条件
		return false;

	*depth = LetfDepth>RightDepth ? LetfDepth + 1 : RightDepth + 1;//当前节点的高度
	return true;

}

bool isBalanced(struct TreeNode* root){
	int depth = 0;
	return _isBalanced(root, &depth);
}