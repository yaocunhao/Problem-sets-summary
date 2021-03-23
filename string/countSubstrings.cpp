class Solution {
public:
	int count = 0;//统计回文串变量

	void GetString(string s, int begin, int end)
	{
		while (begin >= 0 && end<s.size() && s[begin] == s[end])
		{
			count++;
			begin--;
			end++;
		}

	}

	int countSubstrings(string s) {
		//中心扩展法，中心点只能是1个点或者2个点
		//因为，3个点可以由1个点扩展而来
		//4个点可以由两个点扩展而来

		for (int i = 0; i<s.size(); i++)
		{
			GetString(s, i, i);//1个中心点
			GetString(s, i, i + 1);//两个中心点
		}

		return count;
	}
};