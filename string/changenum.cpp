//��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� 
//��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0

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