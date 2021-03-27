37.������




int JudgeNum(char **board, int row, int col, char ch)//�ж��Ƿ��ܹ������ַ�
{
	for (int i = 0; i<9; i++)
	{
		if (board[row][i] == ch)//��ǰ���Ƿ����ظ�����
			return 0;

		if (board[i][col] == ch)//��ǰ���Ƿ����ظ�����
			return 0;

		if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)//��ǰ�Ź������ظ�����
			return 0;
	}
	return 1;//��������

}

int GetNum(char** board, int row, int col)
{
	if (row == 8 && col == 9)//�ݹ����,�ո�������һ���ַ�
		return 1;
	if (col == 9)//ֻ�����ĳһ�е����һ���ַ�
	{
		row++;
		col = 0;
	}

	while (board[row][col] != '.')//��ǰλ�����ַ�
	{
		col++;

		if (row == 8 && col == 9)//�ݹ����
			return 1;

		if (col == 9)//��ǰ��������
		{
			row++;
			col = 0;
		}
	}

	//���������ѭ���������˵���˴�λ����Ҫ�����ַ�

	for (char i = '1'; i <= '9'; i++)//ѭ�������ַ�
	{
		if (JudgeNum(board, row, col, i))//�ж��Ƿ��ܹ�����
		{
			board[row][col] = i;//��������

			int num = GetNum(board, row, col + 1);//��һ��λ�ü�����д

			if (num)//����ˣ��������ֶ���������
			{
				return 1;
			}
			else//��λ�ò������룬����������д�ַ�
			{
				board[row][col] = '.';//����'
			}
		}
		else
			continue;//��ǰ�ַ��������룬��һ���ַ�   
	}
	//�����λ�ã�˵�������е��ַ����������룬����0
	return 0;
}


void solveSudoku(char** board, int boardSize, int* boardColSize){

	GetNum(board, 0, 0);

}