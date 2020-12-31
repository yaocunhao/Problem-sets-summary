//后序遍历


int GetSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return GetSize(root->left) + GetSize(root->right) + 1;
}

void Traversal(int *arr, struct TreeNode* root, int *count)
{
	//先左再右再根
	if (root)
	{
		Traversal(arr, root->left, count);
		Traversal(arr, root->right, count);
		arr[(*count)++] = root->val;
	}
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
	int size = GetSize(root);
	int *arr = (int *)malloc(sizeof(int)*size);

	int count = 0;
	Traversal(arr, root, &count);

	*returnSize = count;
	return arr;
}