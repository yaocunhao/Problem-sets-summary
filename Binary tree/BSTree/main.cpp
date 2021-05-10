#include "BSTree.hpp"


//void TestBSTree()
//{
//	BSTree<int> tree;
//
//	tree.Insert(5);
//	tree.Insert(3);
//	tree.Insert(7);
//	tree.Insert(1);
//	tree.Insert(4);
//	tree.Insert(6);
//	tree.Insert(8);
//	tree.Insert(0);
//	tree.Insert(2);
//	tree.Insert(9);
//	tree.Inorder();
//	tree.Erase(7);
//	tree.Inorder();
//	tree.Erase(2);
//	tree.Inorder();
//	tree.Erase(3);
//	tree.Inorder();
//	tree.Erase(2);
//	tree.Inorder();
//	tree.Erase(1);
//	tree.Inorder();
//	tree.Erase(0);
//	tree.Erase(3);
//	tree.Erase(4);
//	tree.Inorder();
//}

void TestBSTree()
{
	//BSTree<string, string> dict;
	//dict.Insert("vector","数组");
	//dict.Insert("list", "链表");
	//dict.Insert("erase","删除");
	//dict.Insert("find","查找");

	//dict.Inorder();

	//string str;
	//while (cin >> str)
	//{
	//	BSTreeNode<string,string> *ret=dict.Find(str);
	//	if (ret)
	//	{
	//		cout << ret->_value << " ";
	//	}
	//	else
	//		cout << "该单词不存在" << endl;

	//}


	string arr[] = { "饼干", "饼干", "水果","水果", "面包","面包" , "饼干", "水果", "饼干", "桃" };
	BSTree<string, int> countTree;
	for (auto &e : arr)
	{
		BSTreeNode<string,int> *ret = countTree.Find(e);
		if (ret == nullptr)//第一次出现
		{
			countTree.Insert(e, 1);
		}
		else//不是第一次出现
		{
			ret->_value++;
		}
	}

	countTree.Inorder();
}
int main()
{

	TestBSTree();
	system("pause");
	return 0;
}