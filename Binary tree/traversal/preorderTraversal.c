//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

 二叉树具有天然的递归属性，递归的同时清除要让计算机干什么就行了
不必清楚其中的具体过程


int GetSize(struct TreeNode* root)//获得元素的个数
{
	if (root == NULL)
		return 0;
	return GetSize(root->left) + GetSize(root->right) + 1;//左节点+右节点+1
}
void Traversal(int *arr, struct TreeNode* root, int *count)//遍历往数组里面填入数据
{
	if (root != NULL)
	{
		arr[*count] = root->val;//填入根节点
		(*count)++;
		Traversal(arr, root->left, count);
		Traversal(arr, root->right, count);//填入右节点
	}
}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
	int size = GetSize(root);
	int *arr = (int *)malloc(sizeof(int)*size);

	int count = 0;
	Traversal(arr, root, &count);//注意传地址进去

	*returnSize = count;
	return arr;
}