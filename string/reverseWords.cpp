557. ��ת�ַ����еĵ��� III

class Solution {
public:
	string reverseWords(string s) {
		int pos1 = 0;
		size_t pos2 = s.find(' ', pos1);//Ѱ�ҿո�

		while (pos2 != string::npos)
		{
			reverse(s.begin() + pos1, s.begin() + pos2);
			pos1 = pos2 + 1;//���������һ���ַ���ͷ��
			pos2 = s.find(' ', pos1);//�ٴ�Ѱ�ҿո�
		}
		reverse(s.begin() + pos1, s.end());//�����һ�����ʽ��з�ת
		return s;

	}
};