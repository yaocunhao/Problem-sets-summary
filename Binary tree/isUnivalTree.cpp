���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������
ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��


��һ�����ڵ��ֵ��Ȼ����еݹ�ѭ���Ƚ��ж�

bool Un(struct TreeNode* root, int tree_val)
{
	if (root == NULL)
		return true;

	return
		Un(root->left, tree_val) &&
		Un(root->right, tree_val) &&
		(root->val == tree_val);//�������µݹ�

}


bool isUnivalTree(struct TreeNode* root){
	return Un(root, root->val);
