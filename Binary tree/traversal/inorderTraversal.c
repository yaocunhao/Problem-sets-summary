给定一个二叉树的根节点 root ，返回它的 中序 遍历。



//先赋值左孩子，再根，再右孩子节点


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
		//先赋值左孩子然后根节点再右孩子节点
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