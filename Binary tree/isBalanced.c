����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
�����У�һ�ø߶�ƽ�����������Ϊ��
һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ��

����˼·��
������������ĸ߶ȣ�������ж�


int TreeH(struct TreeNode* root)//��߶�
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

	int L = TreeH(root->left);//�������߶�
	int R = TreeH(root->right);//�������߶�

	if (abs(L - R)>1)
		return false;


	return
		isBalanced(root->left) &&
		isBalanced(root->right);


}