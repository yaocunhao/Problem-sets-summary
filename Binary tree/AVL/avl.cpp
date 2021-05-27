#include "avl.hpp"

void test1(vector<int>&arr)
{
	AVLTree<int,int> t1;

	cout << "中序遍历输出节点----------------" << endl;
	for (auto&e : arr)
	{
		t1[e]++;
	}

	t1.Inorder();

	cout << "中序遍历输出节点----------------" << endl << endl;;

	cout << "通过函数调用判断是否是平衡二叉树" << endl;

	if (t1.Isbalance())
		cout << "是平衡二叉树" << endl;
	else
		cout << "不是平衡二叉树" << endl;

}

int main()
{
	cout << "测试1" << endl;
	vector<int>arr1 = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	test1(arr1);
	
	cout << endl << "测试2" << endl;
	vector<int>arr2 = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	test1(arr2);



	system("pause");
	return 0;
}