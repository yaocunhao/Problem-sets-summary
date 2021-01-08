#include"sort.h"

void test()
{
	srand((unsigned)time(NULL));
	int size = 100000;
	int *arr = (int *)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand();
	}



	
	int begin = clock();
	InsertSort(arr, size);
	int end = clock();
	printf("insert_time:%d\n", end - begin);

	printf("insertsort: ");
	//Print(arr, size);
	printf("\n\n");
}
void test1()
{
	srand((unsigned)time(NULL));
	int size = 100000;
	int *arr = (int *)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand();
	}
	
	int begin = clock();
	ShellSort(arr, size);
	int end = clock();
	printf("shell :%d\n", end - begin);

	printf("shellsort: ");
	//Print(arr, size);
	printf("\n\n");
}
void test2()
{
	srand((unsigned)time(NULL));
	int size = 100000;
	int *arr = (int *)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand();
	}

	int begin = clock();
	SelectSort(arr, size);
	int end = clock();
	printf("select :%d\n", end - begin);
	printf("selectsort: ");
	//Print(arr, size);
	printf("\n");
	printf("\n");
}
void test4()
{
	srand((unsigned)time(NULL));
	int size = 10;
	int *arr = (int *)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand();
	}

	int begin = clock();
	HeadSort(arr, size);
	int end = clock();
	printf("heap :%d\n", end - begin);
	printf("heap: ");
	Print(arr, size);
	printf("\n");
	printf("\n");
}


int main()
{
	/*test();
	test1();
	test2();*/
	test4();
	system("pause");
	return 0;
}