#include "hash.hpp"
#include "hashmap.hpp"
#include "hashset.hpp"


//void test_map()
//{
//
//	YCH_MAP::ych_unordered_map<int, int> map;
//
//
//
//	map.insert(make_pair(1, 1));
//	map.insert(make_pair(2, 2));
//	map.insert(make_pair(3, 3));
//	map.insert(make_pair(4, 4));
//
//	for (auto&e : map)
//	{
//		cout << e.first << " " << e.second << endl;
//	}
//
//	cout << "_______²âÊÔ2_______" << endl;
//
//	YCH_MAP::ych_unordered_map<string, string> map2;
//	map2.insert(make_pair("Æ»¹û", "ºÃ³Ô"));
//	map2.insert(make_pair("Ïã½¶", "buºÃ³Ô"));
//	map2.insert(make_pair("¹şÃÜ¹Ï", "»¹¿ÉÒÔ"));
//	map2.insert(make_pair("·ïÀæ", "Ò²»¹¿ÉÒÔ"));
//	map2.insert(make_pair("Ë®ÃÛÌÒ", "Ò²»¹²»´í"));
//
//	for (auto&e : map2)
//	{
//		cout << e.first << " " << e.second << endl << endl;
//	}
//}
//
//void test_set()
//{
//	cout << "-------set·â×°²âÊÔ----" << endl;
//	YCH_MAP::ych_unordered_set<int> set;
//
//	set.insert(1);
//	set.insert(12);
//	set.insert(13);
//	set.insert(10);
//	set.insert(8);
//
//	for (auto &e : set)
//	{
//		cout << e << endl;
//	}
//
//	cout << "_____²éÕÒ10£¬²¢ÇÒÊä³ö____" << endl;
//	YCH_MAP::ych_unordered_set<int>::iterator it = set.find(10);
//	if (it != set.end())
//		cout << *it << endl<< endl;
//
//}

void test_open_map()
{
	cout << "____YCH_MAP::ych_unordered_map<int, int> map___" << endl ;
	YCH_MAP::ych_unordered_map<int, int> map;
	
	map.insert(make_pair(1, 1));
	map.insert(make_pair(54, 54));
	map.insert(make_pair(55, 55));
	map.insert(make_pair(56, 56));
	map.insert(make_pair(54, 54));
	map.insert(make_pair(108, 108));

	auto it = map.begin();

	while (it != map.end())
	{
		cout << it->first << " " << it->second << endl;
		++it;
	}
	cout << endl;


	cout << "____[]²âÊÔ____<<endl";
	map[500]++;
	map[200]=100;
	map[111] = 153;

	for (auto&e : map)
	{
		cout << e.first<<" "<<e.second<< endl;
	}
}

void test_open_set()
{
	cout << "_____YCH_MAP::ych_unordered_set<string> set______ " << endl;
	YCH_MAP::ych_unordered_set<string> set;
	set.insert("ÅÅĞò");
	set.insert("×Ö·û´®");
	set.insert("Ëã·¨");
	set.insert("Ëã·¨");
	set.insert("×Ö·û´®");
	set.insert("¹şÏ£±í");

	for (auto&e : set)
	{
		cout << e << endl;
	}
}

int main()
{
	test_open_map();	
	test_open_set();



	system("pause");
	return 0;

}
