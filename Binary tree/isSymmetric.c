����һ����������������Ƿ��Ǿ���ԳƵġ�

����˼·��
1.�жϵ�ǰ���������ڵ��Ƿ����
2.�����ȣ��ݹ鴫���������������ҽڵ�

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
	return isS(root->left, root->right);//������������
}