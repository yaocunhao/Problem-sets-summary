����һ�����������ҳ��������ȡ�
�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����


������==����������Ⱥ�����������ȵĽϴ�ֵ+1��


int maxDepth(struct TreeNode* root){
	if (root == NULL)//�յķ���0
		return 0;
	//�����=�������ĸ߶Ȼ����������ĸ߶�+1
	int l = maxDepth(root->left);
	int r = maxDepth(root->right);
	return l>r ? l + 1 : r + 1;
}