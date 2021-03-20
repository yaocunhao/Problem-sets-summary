125. ��֤���Ĵ�

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

				start++;//�ҵ���ĸ��������
			}
			while (!((s[end] >= 'a'&&s[end] <= 'z') || (s[end] >= 'A'&&s[end] <= 'Z') || (s[end] >= '0'&&s[end] <= '9')))
			{
				if (start >= end)
					break;

				end--;//�ҵ���ĸ��������
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