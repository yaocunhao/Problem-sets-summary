class Solution {
public:
	int count = 0;//ͳ�ƻ��Ĵ�����

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
		//������չ�������ĵ�ֻ����1�������2����
		//��Ϊ��3���������1������չ����
		//4�����������������չ����

		for (int i = 0; i<s.size(); i++)
		{
			GetString(s, i, i);//1�����ĵ�
			GetString(s, i, i + 1);//�������ĵ�
		}

		return count;
	}
};