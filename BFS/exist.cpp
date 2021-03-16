//����12

bool Find(char **board, int boardSize, int *boardColSize, char *word, int row, int line, int sub)
{
	//Խ����ַ������ֱ�ӷ���false
	if (row<0 || row>(boardSize - 1) || line<0 || line>((*boardColSize) - 1) || board[row][line] != word[sub])
		return false;

	if (strlen(word) - sub == 1)//���һ��Ԫ�ؼ�����
		return true;

	//��֦������ֹ���ظ�·��  
	char temp = board[row][line];
	board[row][line] = '\0';


	bool ret =
		Find(board, boardSize, boardColSize, word, row + 1, line, sub + 1)//��������
		|| Find(board, boardSize, boardColSize, word, row - 1, line, sub + 1)//��������
		|| Find(board, boardSize, boardColSize, word, row, line - 1, sub + 1)//��������
		|| Find(board, boardSize, boardColSize, word, row, line + 1, sub + 1);//��������

	board[row][line] = temp;//�ָ���֦    

	return ret;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word){
	//����������������Ž�ÿһ���㶼����
	int row = boardSize;
	int line = *boardColSize;

	for (int i = 0; i<row; i++)
	{
		for (int j = 0; j<line; j++)
		{
			if (Find(board, boardSize, boardColSize, word, i, j, 0))//�ҵ����أ�û�ҵ�����һ�������
				return true;
		}
	}
	return false;
}