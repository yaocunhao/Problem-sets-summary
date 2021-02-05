//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
//���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
//����Լ������������ظ�Ԫ�ء�

//����˼·������������������뵽���Ƕ��ֲ��ң�����ͨ�����ֲ��ҿ���ֱ���ҵ���Ӧ��ֵ��������ڵĻ�
//�����Ӧ��ֵ�����ڣ���ô���ǿ������������mid�±꣬���nums[mid]>target˵������mid�±꿪ʼ
//����������Ҫ����Ų��Ȼ��target������mid�±�����
//�����nums[mid]<target��˵��Ӧ�ò�����mid����һ��λ��

int searchInsert(int* nums, int numsSize, int target){
	int left = 0;
	int right = numsSize - 1;
	int mid = left + (right - left) / 2;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid]>target)
			right = mid - 1;
		else if (nums[mid]<target)
			left = mid + 1;
		else
			return mid;
	}

	//û���ҵ�
	if (nums[mid]>target)
		return mid;

	return mid + 1;
}