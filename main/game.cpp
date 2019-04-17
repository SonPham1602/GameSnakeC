#include "process.h"
#include<stdio.h>
#include<conio.h>
#include<console.h>
#include<time.h>
#include<windows.h>
#include<stdio.h>
#include<string>
#include<iostream>
#include<fstream>
void main ()
{
	Snake snake;
	snake.n=5;
	int bien=8;
	char traloi=13;
	for(int i=0;i<snake.n;i++)
	{
		snake.than[i].y=5;
		snake.than[i].x=bien;
		bien--;
	}
	snake.tt=RIGHT;
	logogame();
	while(traloi==13)
	{
		clrscr();
		chinh(snake,traloi);
		if(traloi==27)
		{
			break;
		}
	}
	clrscr();
	system("cls");
	TextColor(9);
	printf("          SON PHAM                                                 \n");
	printf("CHUC CAC BAN CHOI VUI VE                                     \n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                               \n");								
	getch();
}