leetcode 387. �ַ����еĵ�һ��Ψһ�ַ�


class Solution {
public:
	int firstUniqChar(string s) {
		if (s.size() == 0)
			return -1;

		int arr[26] = { 0 };//ͳ�������ַ����ֵĴ���
		for (int i = 0; i<s.size(); i++)
		{
			arr[s[i] - 'a']++;
		}
		for (int i = 0; i<s.size(); i++)
		{
			if (arr[s[i] - 'a'] == 1)
				return i;
		}
		return -1;
	}
};