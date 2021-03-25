#include <iostream>
using namespace std;
#include <string>


int main()
{
	string str;

	while (cin >> str)
	{
		int *arr = new int[26]{0};
		int flag = 0;
		for (int i = 0; i<str.size(); i++)
		{
			arr[str[i] - 'a']++;
		}

		for (int i = 0; i<str.size(); i++)
		{
			if (arr[str[i] - 'a'] == 1)
			{
				cout << str[i] << endl;
				flag = 1;
				break;
			}
		}
		if (!flag)
			cout << -1 << endl;
	}


	return 0;
}