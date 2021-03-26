22.括号生成

void Get(char**ret, char *temp, int *returnSize, int n, int left, int right, int sub)
{
	if (left>n || right>n)//超过一半代表不会匹配
	{
		return;
	}

	if (left == right&&left + right == 2 * n)//左右括号相等且相加等于总括号数
	{
		ret[*returnSize] = (char *)malloc(sizeof(char)*(2 * n + 1));//开辟空间，\0留空间
		memcpy(ret[*returnSize], temp, sizeof(char)*n * 2);
		ret[*returnSize][2 * n] = '\0';//终止符
		(*returnSize)++;
		return;
	}

	//往临时数组之内填入括号

	if (left<n)
	{
		temp[sub] = '(';
		Get(ret, temp, returnSize, n, left + 1, right, sub + 1);
	}

	if (right<left)
	{
		temp[sub] = ')';
		Get(ret, temp, returnSize, n, left, right + 1, sub + 1);
	}

}



char ** generateParenthesis(int n, int* returnSize){

	//回溯算法实现，通过树状结构，给定两个变量记录左括号和右括号的数
	//如果有括号的数量大于左括号，则进行剪枝处理
	//一开始全用左括号

	char **ret = (char **)malloc(sizeof(char*)* 2000);
	char *temp = (char *)malloc(sizeof(char)*(n * 2 + 1));//每个一维数组内有多少括号，需要给\0开辟空间
	*returnSize = 0;


	Get(ret, temp, returnSize, n, 0, 0, 0);

	return ret;

}