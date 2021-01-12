�����е�·��

�ⷨ�����͵Ļ������⣬ͨ�����ϵļ�֦�͵ݹ�����ɽ���



bool BackTracking(char **board, int boardSize, int size, char *word, int row, int col, int sub)
{
	if (row<0 || col<0 || row >= boardSize || col >= size || board[row][col] != word[sub])
		return false; //Խ����߶�Ӧ�ľ���ֵ���ַ��������

	if (strlen(word) == sub)//�±�ȳ���С1
		return true;//���������

	char temp = board[row][col];//��ֹ�ظ�Ѱ��
	board[row][col] = '/0';

	//�жϵ�ǰ�ڵ�����������Ƿ�������Ҫ���ֵ
	bool ret = BackTracking(board, boardSize, size, word, row, col + 1, sub + 1) ||
		BackTracking(board, boardSize, size, word, row, col - 1, sub + 1) ||
		BackTracking(board, boardSize, size, word, row + 1, col, sub + 1) ||
		BackTracking(board, boardSize, size, word, row - 1, col, sub + 1);

	board[row][col] = temp;//��ԭ�����ֳ�

	return ret;


}


bool exist(char** board, int boardSize, int* boardColSize, char* word){
	int size = *boardColSize;

	//˫��ѭ������ÿһ���ڵ㶼���뵽�ݹ��ж�֮��
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