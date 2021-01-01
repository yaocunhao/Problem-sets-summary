如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
只有给定的树是单值二叉树时，才返回 true；否则返回 false。


给一个根节点的值，然后进行递归循环比较判断

bool Un(struct TreeNode* root, int tree_val)
{
	if (root == NULL)
		return true;

	return
		Un(root->left, tree_val) &&
		Un(root->right, tree_val) &&
		(root->val == tree_val);//继续往下递归

}


bool isUnivalTree(struct TreeNode* root){
	return Un(root, root->val);
