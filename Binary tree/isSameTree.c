

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	//判断两个二叉树是否相等，则要判断两个二叉树的根，左子树，右子树是否相等
	if (p == NULL&&q == NULL)//同时空相同
		return true;

	if (p == NULL || q == NULL)//一个空一个不空则不相同
		return false;

	return(p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}