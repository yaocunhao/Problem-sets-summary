�����ö�����A��B���ж�B�ǲ���A���ӽṹ��(Լ��������������һ�������ӽṹ)

B��A���ӽṹ�� �� A���г��ֺ�B��ͬ�Ľṹ�ͽڵ�ֵ��

�ⷨ��ͨ���ݹ�ǰ�������⣬���ж�A��B����Ϊ�պ󣬽��еݹ�
�ڵݹ�Ĺ������ж�A���Ƿ��к�B��ȵ��ӽṹ



bool Judge(struct TreeNode* A, struct TreeNode* B)
{
	if (B == NULL)
		return true;
	if (A == NULL&&B != NULL)
		return false;

	return
		(A->val == B->val) &&
		Judge(A->left, B->left) &&
		Judge(A->right, B->right);
}

bool isSubStructure(struct TreeNode* A, struct TreeNode* B){
	if (B == NULL || A == NULL)
		return false;//����

	if (Judge(A, B))
		return true;

	return isSubStructure(A->left, B) || isSubStructure(A->right, B);

}