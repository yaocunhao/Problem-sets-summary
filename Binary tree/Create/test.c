#include "heap.h"

void test()
{
	Heap hp;
	HPDataType arr[] = { 15, 122, 18, 1, 5, 6455, 18, 5 };
	int num = sizeof(arr) / sizeof(arr[0]);
	heapCreate(&hp, arr, num);
	Print(&hp, hp.size);
	HeapPush(&hp, 0);
	Print(&hp, hp.size);
	HeapPop(&hp);
	Print(&hp, hp.size);
	HeapPop(&hp);
	Print(&hp, hp.size);
	HeapPop(&hp);
	Print(&hp, hp.size);
	HeapPop(&hp);
	Print(&hp, hp.size);
	HeapPop(&hp);
	Print(&hp, hp.size);
	HeapPop(&hp);
}
void test2()
{
	int arr[] = { 15, 15, 8, 15, 111, 518, 96, 15 };
	int n = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, n);
}

void test3()
{
	Heap hp;
	int arr[] = { 1, 52, 82, 8, 28, 2, 6841, 18933, 4, 8415, 666, 1552 };
	int size = sizeof(arr) / sizeof(arr[0]);
	heapCreate(&hp, arr, size);
	Print(&hp, size);
	//HeapDestory(&hp);
	HeapEmpty(&hp);
	HPDataType num = HeapTop(&hp);
	printf("%d\n", num);

	HPDataType ret = heapSize(&hp);
	printf("ÔªËØ¸öÊý%d\n", ret);


}
int main()
{

	//test();
	//test2();
	test3();
	system("pause");
	return 0;
}