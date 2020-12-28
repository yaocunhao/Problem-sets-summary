#include "heap.h"

void test()
{
	Heap hp;
	HPDataType arr[] = { 15, 122, 18, 1, 5, 6455, 18, 5 };
	int num = sizeof(arr) / sizeof(arr[0]);
	heapCreate(&hp,arr,num);
	for (int i = 0; i < num; i++)
	{
		printf("%d ", hp.arr[i]);
	}
}

int main()
{
	
	test();

	system("pause");
	return 0;
}