541. ��ת�ַ��� II

class Solution {
public:
	string reverseStr(string s, int k) {
		int begin = 0;
		int end = s.size();

		while (end - begin >= 2 * k)//�Ƚ���ͷ��ת
		{
			reverse(s.begin() + begin, s.begin() + k + begin);
			begin += 2 * k;
		}

		if (end - begin<k&&end - begin>0)//С��k��ֱ�ӷ�ת
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