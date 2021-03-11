从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

用数组模拟队列，进行层序遍历


int* levelOrder(struct TreeNode* root, int* returnSize){
	if (root == NULL)//为零时
	{
		*returnSize = 0;
		return root;
	}

	struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1200);//存储根节点
	int *arr = (int *)malloc(sizeof(int)* 1200);//存储元素

	//三个下标
	int size = 0;
	int sub = 0;
	int count = 0;

	queue[size++] = root;//将第一个

	while (sub != size)
	{
		struct TreeNode* _root = queue[sub++];
		if (_root)
		{
			arr[count++] = _root->val;

			if (_root->left != NULL)//防止爆栈
				queue[size++] = _root->left;//左子树入队
			if (_root->right != NULL)
				queue[size++] = _root->right;//右子树入队

		}
	}

	*returnSize = count;
	return arr;


}