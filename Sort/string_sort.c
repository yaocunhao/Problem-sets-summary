//���ַ������� ����һ�����Ȳ�����20���ַ���������������ַ���������ASCII��Ĵ�С��С���������������������Ľ��

//����˼·�����ü�������


#include <stdio.h>
int main()
{
	char dst[21] = { 0 };
	scanf("%s", dst);
	int lon = strlen(dst);
	int max = dst[0];
	int min = dst[0];
	for (int i = 0; i<lon; i++)//�Ҵ�С
	{
		if (dst[i]>max)
			max = dst[i];
		if (dst[i]<min)
			min = dst[i];
	}
	int *temp = (int *)malloc(sizeof(int)*(max - min + 1));
	for (int i = 0; i<lon; i++)//ͳ��
	{
		temp[dst[i] - min]++;
	}
	int sub = 0;
	for (int i = 0; i<max - min + 1; i++)//����
	{
		while (temp[i])
		{
			dst[sub++] = i + min;
			temp[i]--;
		}
	}
	free(temp);
	return 0;
}