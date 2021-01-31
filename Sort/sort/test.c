#include"sort.h"

void  test()
{
	srand((unsigned)time(NULL));
	int size = 0;
	scanf("%d", &size);
	int *arr = (int *)malloc(sizeof(int)*size);
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand();
	}

	int *arr1 = (int *)malloc(sizeof(int)*size);
	int *arr2 = (int *)malloc(sizeof(int)*size);
	int *arr3 = (int *)malloc(sizeof(int)*size);
	int *arr4 = (int *)malloc(sizeof(int)*size);
	int *arr5 = (int *)malloc(sizeof(int)*size);
	int *arr6 = (int *)malloc(sizeof(int)*size);
	int *arr7 = (int *)malloc(sizeof(int)*size);
	int *arr8 = (int *)malloc(sizeof(int)*size);
	int *arr9 = (int *)malloc(sizeof(int)*size);
	int *arr10 = (int *)malloc(sizeof(int)*size);
	int *arr11 = (int *)malloc(sizeof(int)*size);


	memcpy(arr1, arr, sizeof(int)*size);
	memcpy(arr2, arr, sizeof(int)*size);
	memcpy(arr3, arr, sizeof(int)*size);
	memcpy(arr4, arr, sizeof(int)*size);
	memcpy(arr5, arr, sizeof(int)*size);
	memcpy(arr6, arr, sizeof(int)*size);
	memcpy(arr7, arr, sizeof(int)*size);
	memcpy(arr8, arr, sizeof(int)*size);
	memcpy(arr9, arr, sizeof(int)*size);
	memcpy(arr10, arr, sizeof(int)*size);
	memcpy(arr11, arr, sizeof(int)*size);


	int begin = clock();
	InsertSort(arr1, size);
	int end = clock();
	printf("Insert :%d\n\n", end - begin);
	//Print(arr1, size);

	begin = clock();
	ShellSort(arr2, size);
	end = clock();
	printf("Shell :%d\n\n", end - begin);
	//Print(arr2, size);

	begin = clock();
	SelectSort(arr3, size);
	end = clock();
	printf("Select :%d\n\n", end - begin);
	//Print(arr3, size);

	begin = clock();
	HeapSort(arr4, size);
	end = clock();
	printf("Heap :%d\n\n", end - begin);
	//Print(arr4, size);

	//begin = clock();
	//BubbleSort(arr5, size);
	//end = clock();
	//printf("Bubble :%d\n\n", end - begin);
	////Print(arr5, size);

	begin = clock();
	QuickSort(arr6, 0, size - 1);
	end = clock();
	printf("Quick :%d\n\n", end - begin);
	//Print(arr6, size);


	begin = clock();
	QuickSortNoRSt(arr7, 0, size - 1);
	end = clock();
	printf("QuickNorSt :%d\n\n", end - begin);
	//Print(arr7, size);

	begin = clock();
	QuickSortNoRQe(arr8, 0, size - 1);
	end = clock();
	printf("QuickNorQe :%d\n\n", end - begin);
	//Print(arr8, size);

	begin = clock();
	MergeSort(arr9, 0, size - 1, size);
	end = clock();
	printf("Merge :%d\n\n", end - begin);
	//Print(arr9, size);

	begin = clock();
	MergeSortNoR(arr10, size);
	end = clock();
	printf("MergeNoR :%d\n\n", end - begin);
	//Print(arr10, size);

	begin = clock();
	CountSort(arr11, size);
	end = clock();
	printf("CountSore :%d\n\n", end - begin);
	//Print(arr11, size);
}



int main()
{

	test();
	system("pause");
	return 0;
}



