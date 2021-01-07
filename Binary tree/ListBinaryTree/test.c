#include"binary.h"


void test()
{
	char a[] = "ABD##E#H##CF##G##";
	int pi = 0;
	BTNode *root = BinaryTreeCreate(a, &pi);
	//BinaryTreeDestory(&root);

	/*int c=BinaryTreeSize(root);
	printf("%d\n", c);

	int d = BinaryTreeLeafSize(root);
	printf("%d\n", d);

	int b = BinaryTreeLevelKSize(root,6);
	printf("%d\n", b);*/

	BinaryTreePrveOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");

	BinaryTreeLevelOrder(root);
	printf("\n");
	if (BinaryTreeComplete(root))
		printf("是完全二叉树\n");
	else
		printf("不是完全二叉树\n");
}



int main()
{
	test();

	system("pause");
	return 0;
}