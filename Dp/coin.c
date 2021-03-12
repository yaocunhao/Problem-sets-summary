#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
//
//�����������޵�Ӳ�ң���ֵΪ25�֡�10�֡�5�ֺ�1�֣�
//��д�������n���м��ֱ�ʾ����(������ܻ�ܴ�����Ҫ�����ģ��1000000007)

//
//�ֽⷽ��Ϊ��Ӳ����ֵ����n��ʱ�����һöӲ�϶���1��10��5��25���е�һö
//��ʱf(n) = f(n - 1) + f(n - 5) + f(n - 10) + f(n - 25)
//��Ҫ�����f(n)�͵��ȼ����ǰ��ģ���˼���˳��Ϊf(1), f(2), f(3)........f(n)




int waysToChange(int n){

	int div = 1000000007;
	int *ret = (int *)calloc(n+1,sizeof(int));//װÿ�ֽ�����м��ַ��������㿪ʼ�������n+1���ռ�

	ret[0] = 1;//��n-1/5/10/25==0��ʱ�򣬴�ʱһöӲ�Ҿ�����ɣ�Ҳ��һ�ַ���

	int coins[] = { 1, 5, 10, 25 };//����Ӳ��

	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j <= n; j++)//��ÿ��Ǯ�ǰӲ��Ϊ���һö
		{
			if (j - coins[i] >= 0)//�����������
			{
				ret[j] =(ret[j - coins[i]] + ret[j]) % div;
			}
		}
	}
	return ret[n];

}
int main()
{

	int ret = waysToChange(10);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
