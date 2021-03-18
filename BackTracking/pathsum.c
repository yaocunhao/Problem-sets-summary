void GetRoad(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes, int **ret, int* temp, int count, int sub)
{
	if (root == NULL)//前面一个节点就已经不正确
		return;

	temp[sub++] = root->val;//保存当前节点

	count += root->val;

	if (root->left == NULL&&root->right == NULL&&count == targetSum)//当前路径合法
	{
		ret[*returnSize] = (int*)malloc(sizeof(int)*sub);//开辟空间

		memcpy(ret[*returnSize], temp, sub*sizeof(int));//拷贝

		returnColumnSizes[0][*returnSize] = sub;//保存当前二维数组中一维数组元素的个数
		(*returnSize)++;//该数组元素保存下来   
		return;
	}


	GetRoad(root->left, targetSum, returnSize, returnColumnSizes, ret, temp, count, sub);//前序遍历
	GetRoad(root->right, targetSum, returnSize, returnColumnSizes, ret, temp, count, sub);

}


int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes){

	*returnColumnSizes = (int *)calloc(5000, sizeof(int));//用来记录，路径中，节点个数
	*returnSize = 0;//路径条数

	int **ret = (int **)malloc(sizeof(int)* 1000);//放路径首元素地址

	// for(int i=0;i<10;i++)
	// {
	//     ret[i]=(int *)malloc(sizeof(int)*1000);//给二级指针中的一级指针开辟空间
	// }

	int *temp = (int *)malloc(1000 * sizeof(int));//临时记录路径数组


	int count = 0;//统计数目
	int sub = 0;//统计节点个数

	GetRoad(root, targetSum, returnSize, returnColumnSizes, ret, temp, count, sub);

	return ret;


}