#include "扫雷game.h"


//菜单
void menu()
{
	printf("**************************************\n");
	printf("*****************扫雷*****************\n");
	printf("**************************************\n");
	printf("**************************************\n");
	printf("************    1.Play    ************\n");
	printf("************    2.Exit    ************\n");
	printf("**************************************\n");
}


//初始化布局
void init(char arr[ROWS][COLS],char ch)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			arr[i][j] = ch;
		}
	}
}


//打印布局
void print(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("---------------------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
	printf("---------------------\n");
}


//埋雷函数
void setmine(char mine[ROWS][COLS], int row, int col)
{
	int count = NUM_MINE;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (x >= 1 && x <= row && y >= 1 && y <= col && mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}


//判断3*3范围内雷的数量,并进行延展
void expand(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	if (x < 1 || x > ROW || y < 1 || y > COL || show[x][y] != '*' || mine[x][y] == '1')
	{
		return;
	}
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			if (mine[x + i][y + j] == '1')
			{
				count++;
			}
		}
	}
	show[x][y] = '0' + count;
	if (count == 0)
	{
		expand(mine, show, x - 1, y - 1);
		expand(mine, show, x - 1, y);
		expand(mine, show, x - 1, y + 1); 
		expand(mine, show, x, y - 1);
		expand(mine, show, x, y + 1);
		expand(mine, show, x + 1, y - 1);
		expand(mine, show, x + 1, y);
		expand(mine, show, x + 1, y + 1);
	}
}


//标记胜利函数
int Pwin(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '+' && mine[i][j] == '1')
			{
				count++;
			}
		}
	}
	if (count == NUM_MINE)
	{
		return 1;
	}
	return 0;
}


//数格子函数
int cutting(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] != '*')
			{
				count++;
			}
		}
	}
	return count;
}

//操作函数
void play(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 1;
	int y = 1;
	char point = ' ';
	int count = WIN;//胜利条件1
	int cut = 0;
	while (count - cut)
	{
		print(show, ROW, COL);
		printf("请输入你要判断的坐标，杂鱼~~~\n记得+是标记-是扫雷哦~~~~\n");
		scanf("%d %d %c", &x, &y, &point);
		if (x < 1 || x > row || y < 1 || y > col)
		{
			printf("坐标非法！请输入1~%d之间的数，杂鱼~~~\n", row);
			continue;
		}
		if (show[x][y] == '*' && point == '+')
		{
			show[x][y] = '+';
			int ret = Pwin(mine, show, row, col);
			if (ret)
			{
				count = 0;
				cut = 0;
			}
		}
		else if (show[x][y] == '*' && point == '-')
		{
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				if (mine[x][y] != '1')
				{
					expand(mine, show, x, y);
				}
				else
				{
					printf("你被炸死了，你这个杂鱼可真是没用呢~~~~~~~~~~\n");
					printf("你被炸死了，你这个杂鱼可真是没用呢~~~~~~~~~~\n");
					printf("你被炸死了，你这个杂鱼可真是没用呢~~~~~~~~~~\n");
					printf("退出游戏\n");
					print(mine, ROW, COL);
					break;
				}
			}
			else
				printf("非法输入，please重新输入，你个杂鱼连输入都不会~~~\n");
		}
		else
			printf("这个格子已经点过了！别瞎点，杂鱼~~~\n");
		cut = cutting(show, row, col);
	}
	if (count - cut == 0)
	{
		printf("你肯定是侥幸赢的！\n我不服，我们再来一把，你个臭杂鱼！！！\n");
		printf("你肯定是侥幸赢的！\n我不服，我们再来一把，你个臭杂鱼！！！\n");
		printf("你肯定是侥幸赢的！\n我不服，我们再来一把，你个臭杂鱼！！！\n");
	}
}


