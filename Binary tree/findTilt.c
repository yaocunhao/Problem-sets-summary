//һ������ �ڵ���¶� ���弴Ϊ���ýڵ��������Ľڵ�֮�ͺ��������ڵ�֮�͵� ��ľ���ֵ ��
//���û���������Ļ����������Ľڵ�֮��Ϊ 0 ��û���������Ļ�Ҳ��һ�����ս����¶��� 0 ��
//������ ���¶Ⱦ��������нڵ���¶�֮�͡�

// ͨ������������������������¶�
int traverse(struct TreeNode *root, int *tilt)
{
	int l, r;
	if (root)
	{
		l = traverse(root->left, tilt);     //��������
		r = traverse(root->right, tilt);    //��������
		*tilt += abs(l - r);        //���¶�
		return l + r + root->val;
	}
	return 0;
}

int findTilt(struct TreeNode *root)
{
	int tilt = 0;
	traverse(root, &tilt);
	return tilt;
}