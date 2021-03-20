计算字符串最后一个单词的长度，单词以空格隔开。


#include <iostream>
using namespace std;

int main()
{
	string s;
	getline(cin, s);//输入

	int pos = s.rfind(' ');//找到空格的位置
	if (pos == string::npos)
		cout << s.size() << endl;
	else
		cout << s.size() - pos - 1 << endl;
}