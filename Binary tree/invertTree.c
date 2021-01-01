//翻转一棵二叉树

看做三个节点，如果节点不为空，则将左右子树进行交换


struct TreeNode* invertTree(struct TreeNode* root){
	if (root)
	{
		invertTree(root->left);
		invertTree(root->right);

		struct TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;
	}

	return root;
}