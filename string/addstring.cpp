415. �ַ������

class Solution {
public:
	string addStrings(string num1, string num2) {
		int next = 0;//��λ
		int end1 = num1.size() - 1;
		int end2 = num2.size() - 1;
		string ret;

		while (end1 >= 0 || end2 >= 0 || next != 0)
		{
			int n1 = 0;
			int n2 = 0;

			if (end1 >= 0)
			{
				n1 = num1[end1] - '0';//ת��Ϊ����
				end1--;
			}
			if (end2 >= 0)
			{
				n2 = num2[end2] - '0';
				end2--;
			}

			int  count = n1 + n2 + next;
			if (count >= 10)
			{
				next = 1;
				count -= 10;
			}
			else
			{
				next = 0;//û�н�λ
			}

			ret += ('0' + count);//ת��Ϊ�ַ���������β��������
		}

		reverse(ret.begin(), ret.end());

		//    int start=0;
		//    int end=ret.size()-1;
		//    while(start<end)//���еߵ�
		//    {
		//        swap(ret[start++],ret[end--]);
		//    }
		return ret;
	}
};