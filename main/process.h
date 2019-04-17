#ifndef _process_game
#define  _process_game
#include<stdio.h>
#include<conio.h>
#include<console.h>
#include<time.h>
#include<windows.h>
#include<stdio.h>
#include<string>
#include<iostream>
#include<fstream>
enum TrangThai{LEFT,RIGHT,UP,DOWN};
struct Tao_Do 
{
	int x;
	int y;
};
struct Snake
{
	int n;
	Tao_Do than[200];
	TrangThai tt;
};
void pausegame();
void logogame();
void wait();
void xoaO(Snake snake);
void map();
int endgame(Snake snake);
int endgamesnake(Snake snake);
void FooD(Tao_Do &Food,Snake snake);
void artfood(Tao_Do food);
void artscore(int score);
void artuse();
void coChe(Snake &snake);
void veRan(Snake snake);
int eatfood(Snake &snake,Tao_Do food,int &score);
void chinh (Snake snake,char &traloi);

#endif // !_process_game
