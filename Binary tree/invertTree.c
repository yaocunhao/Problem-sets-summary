//��תһ�ö�����

���������ڵ㣬����ڵ㲻Ϊ�գ��������������н���


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