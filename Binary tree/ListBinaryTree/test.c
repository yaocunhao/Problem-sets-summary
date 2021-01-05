#include"binary.h"


void test()
{
	char a[] = "ABD##E#H##CF##G##";
	int pi = 0;
	BTNode *root=BinaryTreeCreate(a,&pi);
	//BinaryTreeDestory(&root);

	int c=BinaryTreeSize(root);
	printf("%d\n", c);

	int d = BinaryTreeLeafSize(root);
	printf("%d\n", d);

	int b = BinaryTreeLevelKSize(root,6);
	printf("%d\n", b);

	BTNode *aa = BinaryTreeFind(root, 'G');

}



int main()
{
	test();

	system("pause");
	return 0;
}