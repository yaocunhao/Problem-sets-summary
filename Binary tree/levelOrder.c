���ϵ��´�ӡ����������ÿ���ڵ㣬ͬһ��Ľڵ㰴�մ����ҵ�˳���ӡ��

������ģ����У����в������


int* levelOrder(struct TreeNode* root, int* returnSize){
	if (root == NULL)//Ϊ��ʱ
	{
		*returnSize = 0;
		return root;
	}

	struct TreeNode** queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * 1200);//�洢���ڵ�
	int *arr = (int *)malloc(sizeof(int)* 1200);//�洢Ԫ��

	//�����±�
	int size = 0;
	int sub = 0;
	int count = 0;

	queue[size++] = root;//����һ��

	while (sub != size)
	{
		struct TreeNode* _root = queue[sub++];
		if (_root)
		{
			arr[count++] = _root->val;

			if (_root->left != NULL)//��ֹ��ջ
				queue[size++] = _root->left;//���������
			if (_root->right != NULL)
				queue[size++] = _root->right;//���������

		}
	}

	*returnSize = count;
	return arr;


}