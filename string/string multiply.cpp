class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1[0] == '0' || num2[0] == '0')
			return "0";

		int n1 = num1.size();
		int n2 = num2.size();
		int size = n1 + n2 - 1;//相乘之后的数组的最后一位

		int *arr = new int[size + 1];//存储结果
		memset(arr, 0, sizeof(int)*(n1 + n2));
		int next = 0;
		int count = 0;

		for (int i = num1.size() - 1; i >= 0; i--)//从后往前取数字
		{
			int n1 = num1[i] - '0';
			int temp = size - count;//表示从哪里开始相加
			count++;

			for (int j = num2.size() - 1; j >= 0; j--)
			{
				n2 = num2[j] - '0';

				arr[temp] += n1*n2 + next;

				if (arr[temp] >= 10)
				{
					next = arr[temp] / 10;//进位
					arr[temp] = arr[temp] % 10;
				}
				else
					next = 0;

				//每次相加往前挪动一位
				temp--;
			}
			if (next != 0)//最后一次计算还留有next
			{
				arr[temp] = next;
				next = 0;
			}
		}

		int i = 0;
		while (arr[i] == 0)
		{
			i++;//第一位为零则往后面挪
		}

		string s3;
		for (; i <= size; i++)
		{
			s3 += arr[i] + '0';
		}
		return s3;
	}
};