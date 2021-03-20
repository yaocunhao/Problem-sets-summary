541. 反转字符串 II

class Solution {
public:
	string reverseStr(string s, int k) {
		int begin = 0;
		int end = s.size();

		while (end - begin >= 2 * k)//先将大头反转
		{
			reverse(s.begin() + begin, s.begin() + k + begin);
			begin += 2 * k;
		}

		if (end - begin<k&&end - begin>0)//小于k个直接反转
		{
			reverse(s.begin() + begin, s.end());
			return s;
		}
		else  if (end - begin<2 * k&&end - begin >= k)
		{
			reverse(s.begin() + begin, s.begin() + begin + k);
			return s;
		}
		return s;
	}
};