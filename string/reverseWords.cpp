557. 反转字符串中的单词 III

class Solution {
public:
	string reverseWords(string s) {
		int pos1 = 0;
		size_t pos2 = s.find(' ', pos1);//寻找空格

		while (pos2 != string::npos)
		{
			reverse(s.begin() + pos1, s.begin() + pos2);
			pos1 = pos2 + 1;//起点来到下一个字符的头部
			pos2 = s.find(' ', pos1);//再次寻找空格
		}
		reverse(s.begin() + pos1, s.end());//将最后一个单词进行反转
		return s;

	}
};