//����������ĸ��ڵ� root ���������ڵ�ֵ�� ǰ�� ������

 ������������Ȼ�ĵݹ����ԣ��ݹ��ͬʱ���Ҫ�ü������ʲô������
����������еľ������


int GetSize(struct TreeNode* root)//���Ԫ�صĸ���
{
	if (root == NULL)
		return 0;
	return GetSize(root->left) + GetSize(root->right) + 1;//��ڵ�+�ҽڵ�+1
}
void Traversal(int *arr, struct TreeNode* root, int *count)//����������������������
{
	if (root != NULL)
	{
		arr[*count] = root->val;//������ڵ�
		(*count)++;
		Traversal(arr, root->left, count);
		Traversal(arr, root->right, count);//�����ҽڵ�
	}
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
	int size = GetSize(root);
	int *arr = (int *)malloc(sizeof(int)*size);

	int count = 0;
	Traversal(arr, root, &count);//ע�⴫��ַ��ȥ

	*returnSize = count;
	return arr;
}