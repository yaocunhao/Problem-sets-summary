�����ַ������һ�����ʵĳ��ȣ������Կո������


#include <iostream>
using namespace std;

int main()
{
	string s;
	getline(cin, s);//����

	int pos = s.rfind(' ');//�ҵ��ո��λ��
	if (pos == string::npos)
		cout << s.size() << endl;
	else
		cout << s.size() - pos - 1 << endl;
}