class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1[0] == '0' || num2[0] == '0')
			return "0";

		int n1 = num1.size();
		int n2 = num2.size();
		int size = n1 + n2 - 1;//���֮�����������һλ

		int *arr = new int[size + 1];//�洢���
		memset(arr, 0, sizeof(int)*(n1 + n2));
		int next = 0;
		int count = 0;

		for (int i = num1.size() - 1; i >= 0; i--)//�Ӻ���ǰȡ����
		{
			int n1 = num1[i] - '0';
			int temp = size - count;//��ʾ�����￪ʼ���
			count++;

			for (int j = num2.size() - 1; j >= 0; j--)
			{
				n2 = num2[j] - '0';

				arr[temp] += n1*n2 + next;

				if (arr[temp] >= 10)
				{
					next = arr[temp] / 10;//��λ
					arr[temp] = arr[temp] % 10;
				}
				else
					next = 0;

				//ÿ�������ǰŲ��һλ
				temp--;
			}
			if (next != 0)//���һ�μ��㻹����next
			{
				arr[temp] = next;
				next = 0;
			}
		}

		int i = 0;
		while (arr[i] == 0)
		{
			i++;//��һλΪ����������Ų
		}

		string s3;
		for (; i <= size; i++)
		{
			s3 += arr[i] + '0';
		}
		return s3;
	}
};