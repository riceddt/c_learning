# 关于三子棋游戏程序的解释

## test.c	主程序

int main()	主函数

void test()	主函数通过调用test()来实现进入游戏或退出游戏。

void game()	调用各个游戏子函数来实现整个游戏算法。

void menu()	作为进入游戏的初始界面，提示选择进入游戏还是退出。

## game.c	游戏程序

void Initboard()	用于棋盘的初始化函数

void DisplayBoard()	棋盘的展示函数

void PlayerMove()	玩家棋子控制函数

void ComputerMove()	电脑棋子控制函数

int IsNull()	判断棋盘是否填满，用于平局的判断

char IsWin()	结果判断函数

## game.h

用于game.c程序中函数的声明以及调用的库函数的头文件引用

## 随机数产生

	//用时间戳来设置随机数的生成起始点
	srand((unsigned int)time(NULL));
	int ret = rand()%100+1;//生成1-100之间的随机数，使用库函数需要引用头文件，可通过MSDN查到头文件

在实际使用时不要将srand和rand放在同一个最小语句块内，srand生成一个种子就够。不然生成的随机数是递增的，并不是乱序。



