37.解数独




int JudgeNum(char **board, int row, int col, char ch)//判断是否能够放入字符
{
	for (int i = 0; i<9; i++)
	{
		if (board[row][i] == ch)//当前行是否有重复数字
			return 0;

		if (board[i][col] == ch)//当前列是否有重复数字
			return 0;

		if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)//当前九宫格有重复数字
			return 0;
	}
	return 1;//可以填入

}

int GetNum(char** board, int row, int col)
{
	if (row == 8 && col == 9)//递归出口,刚刚填好最后一个字符
		return 1;
	if (col == 9)//只是填好某一行的最后一个字符
	{
		row++;
		col = 0;
	}

	while (board[row][col] != '.')//当前位置有字符
	{
		col++;

		if (row == 8 && col == 9)//递归出口
			return 1;

		if (col == 9)//当前行填满了
		{
			row++;
			col = 0;
		}
	}

	//经过上面的循环到达这里，说明此处位置需要填入字符

	for (char i = '1'; i <= '9'; i++)//循环填入字符
	{
		if (JudgeNum(board, row, col, i))//判断是否能够填入
		{
			board[row][col] = i;//填入数字

			int num = GetNum(board, row, col + 1);//下一个位置继续填写

			if (num)//填好了，所有数字都满足条件
			{
				return 1;
			}
			else//有位置不能填入，回溯重新填写字符
			{
				board[row][col] = '.';//回溯'
			}
		}
		else
			continue;//当前字符不能填入，换一个字符   
	}
	//到达此位置，说明，所有的字符都不能填入，返回0
	return 0;
}


void solveSudoku(char** board, int boardSize, int* boardColSize){

	GetNum(board, 0, 0);

}