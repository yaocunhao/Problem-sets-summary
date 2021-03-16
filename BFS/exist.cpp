//剑：12

bool Find(char **board, int boardSize, int *boardColSize, char *word, int row, int line, int sub)
{
	//越界或字符不相等直接返回false
	if (row<0 || row>(boardSize - 1) || line<0 || line>((*boardColSize) - 1) || board[row][line] != word[sub])
		return false;

	if (strlen(word) - sub == 1)//最后一个元素检测完毕
		return true;

	//剪枝处理，防止走重复路径  
	char temp = board[row][line];
	board[row][line] = '\0';


	bool ret =
		Find(board, boardSize, boardColSize, word, row + 1, line, sub + 1)//往下搜索
		|| Find(board, boardSize, boardColSize, word, row - 1, line, sub + 1)//往上搜索
		|| Find(board, boardSize, boardColSize, word, row, line - 1, sub + 1)//往左搜索
		|| Find(board, boardSize, boardColSize, word, row, line + 1, sub + 1);//往右搜索

	board[row][line] = temp;//恢复剪枝    

	return ret;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word){
	//广度优先搜索，试着将每一个点都传入
	int row = boardSize;
	int line = *boardColSize;

	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<line; j++)
		{
			if (Find(board, boardSize, boardColSize, word, i, j, 0))//找到返回，没找到换下一个点继续
				return true;
		}
	}
	return false;
}