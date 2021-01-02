给定一个二叉树，检查它是否是镜像对称的。

解题思路：
1.判断当前左右子树节点是否相等
2.如果相等，递归传入左右子树的左右节点

bool isS(struct TreeNode* Left, struct TreeNode* Right)
{
	if (Left == NULL&&Right == NULL)
		return true;
	if (Left == NULL || Right == NULL)
		return false;

	return
		(Left->val == Right->val) &&
		isS(Left->left, Right->right) &&
		isS(Left->right, Right->left);

}

bool isSymmetric(struct TreeNode* root){
	if (root == NULL)
		return true;
	return isS(root->left, root->right);//传入左右子树
}