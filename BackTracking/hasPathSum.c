//����112��


bool GetSum(struct TreeNode* root, int targetSum, int count)
{
	if (root == NULL)//����սڵ�˵����һ�ڵ㲻����
		return false;

	count += root->val;//����ǰ��ֵ���

	if (root->left == NULL&&root->right == NULL&&count == targetSum)//����Ҷ�ӽڵ�
		return true;


	return GetSum(root->left, targetSum, count) || GetSum(root->right, targetSum, count);
}

bool hasPathSum(struct TreeNode* root, int targetSum){

	//������������ȷ��һ�ֱ����ķ���������һ�㶼��ǰ/��/����ݹ�
	//ͨ�����ݼ�֦�ķ����������ǰ·�������ֵ������Ŀ��ֵ��ֱ���˳�
	//������Ҫһ���������浱ǰ�ڵ��ֵ�������һ�ڵ㲻��������������м�֦
	//���������������ⲻ�ܽ��м�֦����

	if (root == NULL)
		return false;

	int  count = 0;

	return GetSum(root, targetSum, count);

}