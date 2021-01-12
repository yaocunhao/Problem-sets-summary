矩阵中的路径

解法：典型的回溯问题，通过不断的剪枝和递归来完成解题



bool BackTracking(char **board, int boardSize, int size, char *word, int row, int col, int sub)
{
	if (row<0 || col<0 || row >= boardSize || col >= size || board[row][col] != word[sub])
		return false; //越界或者对应的矩阵值和字符串不相等

	if (strlen(word) == sub)//下标比长度小1
		return true;//完成了搜索

	char temp = board[row][col];//阻止重复寻找
	board[row][col] = '/0';

	//判断当前节点的上下左右是否有满足要求的值
	bool ret = BackTracking(board, boardSize, size, word, row, col + 1, sub + 1) ||
		BackTracking(board, boardSize, size, word, row, col - 1, sub + 1) ||
		BackTracking(board, boardSize, size, word, row + 1, col, sub + 1) ||
		BackTracking(board, boardSize, size, word, row - 1, col, sub + 1);

	board[row][col] = temp;//还原案发现场

	return ret;


}


bool exist(char** board, int boardSize, int* boardColSize, char* word){
	int size = *boardColSize;

	//双层循环，将每一个节点都传入到递归判断之中
	for (int i = 0; i<boardSize; i++)
	{
		for (int j = 0; j<size; j++)
		{
			if (BackTracking(board, boardSize, size, word, i, j, 0))
				return true;
		}
	}
	return false;

}