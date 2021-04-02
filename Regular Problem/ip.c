//将ip地址用整形存储

#include <stdio.h>
#include <windows.h>


struct A
{
	unsigned char a : 8;
	unsigned char b : 8;
	unsigned char c : 8;
	unsigned char d : 8;


}val;

int main()
{
	
	const char* str = "172.168.22.59";
	int arr[4] = { 0 };

	int temp = 0;
	int sub = 0;

	while (*str)//将字符串转成整形存储于数组之中
	{
		if (*str == '.')
		{
			arr[sub++] = temp;
			temp = 0;
		}
		else
		{
			temp *= 10;
			temp += *str-'0';
		}
		str++;
	}
	arr[sub] = temp;//最后一次没有保存

	//将分解好的整形存储于位段之中
	val.a = arr[0];
	val.b = arr[1];
	val.c = arr[2];
	val.d = arr[3];

	unsigned int *p = (unsigned int*)&val;
	unsigned int num = *p;//存储整形之中
	
	//进行读取
	unsigned char *read = (unsigned char *)&num;
	for (int i = 0; i < 4; i++)
	{
		printf("%d", *(read+i));
		if (i != 3)
			printf(".");
		else
		printf("\n");
	}


	




	


	//printf("%d %d %d\n", val.a, val.b, val.c);

	//printf("%d\n", val);


	system("pause");
	return 0;
}