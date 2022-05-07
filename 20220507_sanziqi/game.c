#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void Initboard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			board[i][j] = ' ';
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)	//��x��y�е�չʾ��x,y�ɱ�
{
	for (int i = 0; i < row; i++)
	{
		//1.��ӡһ�е�����
		for (int j = 0; j < col; j++)
		{
			if (j < col - 1)
				printf(" %c |", board[i][j]);
			else
				printf(" %c\n", board[i][j]);
		}
		//2.��ӡ�ָ���
		if(i<row-1)
			for (int n = 0; n < row; n++)
			{
				if (n < row - 1)
					printf("---|");
				else
					printf("---\n");
			}
	}
}

//void DisplayBoard(char board[ROW][COL], int row, int col)	//�򵥵�ֻ���3��3�е�չʾ
//{
//	for (int i = 0; i < row; i++)
//	{
//		//1.��ӡһ�е�����
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		//2.��ӡ�ָ���
//		if (i < row - 1)
//			printf("---|---|---\n");
//	}
//}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����:>\n");

	while (1)
	{
		printf("��������Ҫ�µ�Ŀ�꣺>");
		scanf("%d%d", &x, &y);
		//�ж�xy����ĺϷ���
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;	//����whileѭ��
			}
			else
			{
				printf("�����걻ռ��\n");
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������\n");

	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
		}
		break;
	}
}

int IsNull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;	//��������
}
char IsWin(char board[ROW][COL], int row, int col)
{
	//������
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//������
	for (int j = 0; j < row; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	//�ж��Ƿ�ƽ��
	if (1 == IsNull(board, ROW, COL))
	{
		return 'Q';
	}
	else
		return 'C';
}