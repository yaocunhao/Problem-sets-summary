void GetRoad(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes, int **ret, int* temp, int count, int sub)
{
	if (root == NULL)//ǰ��һ���ڵ���Ѿ�����ȷ
		return;

	temp[sub++] = root->val;//���浱ǰ�ڵ�

	count += root->val;

	if (root->left == NULL&&root->right == NULL&&count == targetSum)//��ǰ·���Ϸ�
	{
		ret[*returnSize] = (int*)malloc(sizeof(int)*sub);//���ٿռ�

		memcpy(ret[*returnSize], temp, sub*sizeof(int));//����

		returnColumnSizes[0][*returnSize] = sub;//���浱ǰ��ά������һά����Ԫ�صĸ���
		(*returnSize)++;//������Ԫ�ر�������   
		return;
	}


	GetRoad(root->left, targetSum, returnSize, returnColumnSizes, ret, temp, count, sub);//ǰ�����
	GetRoad(root->right, targetSum, returnSize, returnColumnSizes, ret, temp, count, sub);

}


int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes){

	*returnColumnSizes = (int *)calloc(5000, sizeof(int));//������¼��·���У��ڵ����
	*returnSize = 0;//·������

	int **ret = (int **)malloc(sizeof(int)* 1000);//��·����Ԫ�ص�ַ

	// for(int i=0;i<10;i++)
	// {
	//     ret[i]=(int *)malloc(sizeof(int)*1000);//������ָ���е�һ��ָ�뿪�ٿռ�
	// }

	int *temp = (int *)malloc(1000 * sizeof(int));//��ʱ��¼·������


	int count = 0;//ͳ����Ŀ
	int sub = 0;//ͳ�ƽڵ����

	GetRoad(root, targetSum, returnSize, returnColumnSizes, ret, temp, count, sub);

	return ret;


}