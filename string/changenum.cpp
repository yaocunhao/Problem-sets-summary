//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 
//数值为0或者字符串不是一个合法的数值则返回0

class Solution {
public:
	int StrToInt(string str) {
		int flag = 1;
		long long ret = 0;
		int judge = 0;
		if (str[0] == '-')
		{
			flag = -1;
			judge = 1;
		}
		else if (str[0] == '+')
		{
			judge = 1;
		}
		for (int i = judge; i<str.size(); i++)
		{
			int num = str[i] - '0';
			if (num<0 || num>9)
				return 0;

			ret *= 10;
			ret += num;
		}
		return ret*flag;

	}
};