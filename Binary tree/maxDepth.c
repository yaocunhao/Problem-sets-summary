给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。


树的深==左子树的深度和右子树的深度的较大值+1；


int maxDepth(struct TreeNode* root){
	if (root == NULL)//空的返回0
		return 0;
	//树深度=左子树的高度或者右子树的高度+1
	int l = maxDepth(root->left);
	int r = maxDepth(root->right);
	return l>r ? l + 1 : r + 1;
}