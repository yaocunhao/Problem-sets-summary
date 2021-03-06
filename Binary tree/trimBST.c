给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。
通过修剪二叉搜索树，使得所有节点的值在[low, high]中。修剪树不应该改变保留在树中的元素的相对结构（
即，如果没有被移除，原有的父代子代关系都应当保留）。 可以证明，存在唯一的答案。
所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变

二叉搜索树：
若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 
若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值； 它的左、右子树也分别为二叉排序树

通过后序遍历的方法，判断当前节点的值和边界的问题，如果大于边界则返回它的左节点
如果小于边界则返回它的右节点


struct TreeNode* trimBST(struct TreeNode* root, int low, int high){

	if (NULL == root)
	{
		return NULL;
	}

	root->left = trimBST(root->left, low, high);
	root->right = trimBST(root->right, low, high);

	if (root->val < low)//当前值小于最小值
	{
		return root->right;
	}

	if (high < root->val)//当前值大于最大值
	{
		return root->left;
	}

	return root;

}