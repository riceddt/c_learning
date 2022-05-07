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

void DisplayBoard(char board[ROW][COL], int row, int col)	//对x行y列的展示，x,y可变
{
	for (int i = 0; i < row; i++)
	{
		//1.打印一行的数据
		for (int j = 0; j < col; j++)
		{
			if (j < col - 1)
				printf(" %c |", board[i][j]);
			else
				printf(" %c\n", board[i][j]);
		}
		//2.打印分割行
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

//void DisplayBoard(char board[ROW][COL], int row, int col)	//简单的只针对3行3列的展示
//{
//	for (int i = 0; i < row; i++)
//	{
//		//1.打印一行的数据
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		//2.打印分割行
//		if (i < row - 1)
//			printf("---|---|---\n");
//	}
//}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走:>\n");

	while (1)
	{
		printf("请输入想要下的目标：>");
		scanf("%d%d", &x, &y);
		//判断xy坐标的合法性
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;	//跳出while循环
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走\n");

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
	return 1;	//棋盘满了
}
char IsWin(char board[ROW][COL], int row, int col)
{
	//横三行
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//竖三列
	for (int j = 0; j < row; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	//判断是否平局
	if (1 == IsNull(board, ROW, COL))
	{
		return 'Q';
	}
	else
		return 'C';
}