
ƽ����������Ż��ⷨ�����ú������м��㣬ʱ�临�Ӷ�ΪO(N^2)

bool _isBalanced(struct TreeNode *root, int *depth)
{
	if (root == NULL)
	{
		*depth = 0;
		return true;
	}

	int LetfDepth = 0;
	if (_isBalanced(root->left, &LetfDepth) == false)//������
		return false;//���������ƽ��������ֱ�ӷ���

	int RightDepth = 0;
	if (_isBalanced(root->right, &RightDepth) == false)//������
		return false;

	if (abs(LetfDepth - RightDepth)>1)//�жϵ�ǰ�ڵ��Ƿ���������
		return false;

	*depth = LetfDepth>RightDepth ? LetfDepth + 1 : RightDepth + 1;//��ǰ�ڵ�ĸ߶�
	return true;

}

bool isBalanced(struct TreeNode* root){
	int depth = 0;
	return _isBalanced(root, &depth);
}