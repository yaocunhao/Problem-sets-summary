125. 验证回文串

class Solution {
public:
	bool isPalindrome(string s) {
		if (s.size() == 0)
			return true;

		int start = 0;
		int end = s.size() - 1;

		while (start<end)
		{
			while (!((s[start] >= 'a'&&s[start] <= 'z') || (s[start] >= 'A'&&s[start] <= 'Z') || (s[start] >= '0'&&s[start] <= '9')))
			{
				if (start >= end)
					break;

				start++;//找到字母或者数字
			}
			while (!((s[end] >= 'a'&&s[end] <= 'z') || (s[end] >= 'A'&&s[end] <= 'Z') || (s[end] >= '0'&&s[end] <= '9')))
			{
				if (start >= end)
					break;

				end--;//找到字母或者数字
			}

			if (s[start] != s[end] && (s[start] ^ 32) != s[end])
				return false;
			else
			{
				start++;
				end--;
			}
		}
		return true;

	}
};