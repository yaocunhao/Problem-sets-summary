//把字符串转换成整数
//假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。
//如果数值超过这个范围，请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。


//注意点：
//1.*str是字符，要与数字比较需要 - 字符零
//2.比较是否越界时，不能*10再去比较，这样会越界

int strToInt(char* str){
	int num = 0;
	int count = 1;
	int flag = 1;

	while (*str == ' ')
	{
		str++;//筛除空白
	}


	if (*str != '+' && *str != '-' && *str - '0'>9)//第一个字符不是有效字符,注意字符串中的数字为字符
		return 0;

	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}

	int max = pow(2, 31) - 1;//取得最大值
	int min = -1 * max - 1;//取得最小值
	int judge = max / 10;

	while (*str != '\0'&&*str - '0'<10 && *str - '0' >= 0)//保证为有效字符
	{
		if (num>judge)
		{
			if (flag == 1)
				return max;
			else
				return min;
		}
		else if (num == judge)
		{
			if (*str-'0'>7)//超出了正数范围
			{
				if (flag == 1)
					return max;
				else
					return min;
			}
		}
		num = num*count + (*str - '0');
		str++;
		if (count == 1)
			count *= 10;
	}
	num *= flag;
	return num;

}

