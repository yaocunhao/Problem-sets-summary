//【字符串排序】 输入一个长度不超过20的字符串，对所输入的字符串，按照ASCII码的大小从小到大进行排序，请输出排序后的结果

//解题思路：利用计数排序


#include <stdio.h>
int main()
{
	char dst[21] = { 0 };
	scanf("%s", dst);
	int lon = strlen(dst);
	int max = dst[0];
	int min = dst[0];
	for (int i = 0; i<lon; i++)//找大小
	{
		if (dst[i]>max)
			max = dst[i];
		if (dst[i]<min)
			min = dst[i];
	}
	int *temp = (int *)malloc(sizeof(int)*(max - min + 1));
	for (int i = 0; i<lon; i++)//统计
	{
		temp[dst[i] - min]++;
	}
	int sub = 0;
	for (int i = 0; i<max - min + 1; i++)//回填
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