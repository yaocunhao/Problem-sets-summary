#include "avl.hpp"

void test1(vector<int>&arr)
{
	AVLTree<int,int> t1;

	cout << "�����������ڵ�----------------" << endl;
	for (auto&e : arr)
	{
		t1[e]++;
	}

	t1.Inorder();

	cout << "�����������ڵ�----------------" << endl << endl;;

	cout << "ͨ�����������ж��Ƿ���ƽ�������" << endl;

	if (t1.Isbalance())
		cout << "��ƽ�������" << endl;
	else
		cout << "����ƽ�������" << endl;

}

int main()
{
	cout << "����1" << endl;
	vector<int>arr1 = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	test1(arr1);
	
	cout << endl << "����2" << endl;
	vector<int>arr2 = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	test1(arr2);



	system("pause");
	return 0;
}