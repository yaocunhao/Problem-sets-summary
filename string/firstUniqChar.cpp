leetcode 387. 字符串中的第一个唯一字符


class Solution {
public:
	int firstUniqChar(string s) {
		if (s.size() == 0)
			return -1;

		int arr[26] = { 0 };//统计所有字符出现的次数
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