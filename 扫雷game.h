#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define ROWS 11
#define COL 9
#define COLS 11
#define NUM_MINE 10
#define WIN (COL*ROW - NUM_MINE)


//游戏执行函数
void game();

//菜单
void menu();

//初始化布局
void init(char arr[ROWS][COLS],char ch);

//打印布局
void print(char arr[ROWS][COLS],int row,int col);

//埋雷函数
void setmine(char mine[ROWS][COLS], int row, int col);

//数雷延展函数
void expand(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);

//进行操作
void play(char mine[ROWS][COLS], char show[ROWS][COLS],int row,int col);

//标记胜利条件
int Pwin(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);

//数格子函数
int cutting(char show[ROWS][COLS], int row, int col);