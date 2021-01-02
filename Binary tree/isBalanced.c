给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

解题思路：
求出左右子树的高度，在相减判断


int TreeH(struct TreeNode* root)//求高度
{
	if (root == NULL)
		return 0;

	int l = 1 + TreeH(root->left);
	int r = 1 + TreeH(root->right);

	return (l>r ? l : r);


}

bool isBalanced(struct TreeNode* root){
	if (root == NULL)
		return true;

	int L = TreeH(root->left);//左子树高度
	int R = TreeH(root->right);//右子树高度

	if (abs(L - R)>1)
		return false;


	return
		isBalanced(root->left) &&
		isBalanced(root->right);


}