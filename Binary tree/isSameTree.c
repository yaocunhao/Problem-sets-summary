

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	//�ж������������Ƿ���ȣ���Ҫ�ж������������ĸ������������������Ƿ����
	if (p == NULL&&q == NULL)//ͬʱ����ͬ
		return true;

	if (p == NULL || q == NULL)//һ����һ����������ͬ
		return false;

	return(p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}