����һ���������ĸ��ڵ� root ���������� ���� ������



//�ȸ�ֵ���ӣ��ٸ������Һ��ӽڵ�


int GetSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return GetSize(root->left) + GetSize(root->right) + 1;
}
void  Traversal(int *arr, struct TreeNode* root, int *count)
{
	if (root)
	{
		//�ȸ�ֵ����Ȼ����ڵ����Һ��ӽڵ�
		Traversal(arr, root->left, count);
		arr[(*count)++] = root->val;
		Traversal(arr, root->right, count);
	}
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
	int size = GetSize(root);
	int *arr = (int *)malloc(sizeof(int)*size);

	int count = 0;
	Traversal(arr, root, &count);

	*returnSize = count;
	return arr;

}