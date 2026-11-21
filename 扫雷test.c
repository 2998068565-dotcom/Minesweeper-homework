#include "扫雷game.h"



void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	init(mine,'0');
	init(show,'*');
	setmine(mine, ROW, COL);
	//print(mine,ROW,COL);
	//print(show,ROW, COL);
	play(mine,show,ROW,COL);
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 2:
			printf("退出游戏\n");
			input = 0;
			break;
		default:
			printf("非法输入，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}