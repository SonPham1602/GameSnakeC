#include"process.h"
void pausegame()
{
	getch();
}
void logogame()
{
	char key;
	int ktphim=0;
	while(ktphim==0)
	{
		clrscr();
		for(int i=1;i<15;i++)
		{
			TextColor(i+1);
			for(int i=0;i<36;i++)
			{   
				printf("=");
				Sleep(10);

			}
			TextColor(i);
			printf("\n");
			printf("@@@@@@@@\n");
			printf("@         @@@@@   @@@   @   @ @@@@@\n");
			printf("@@@@@@@@  @   @  @   @  @  @  @\n");
			printf("       @  @   @  @@@@@  @@@   @@@@\n");
			printf("@      @  @   @  @   @  @  @  @\n");
			printf("@@@@@@@@  @   @  @   @  @   @ @@@@@\n");
			Sleep(30);
			TextColor(i+1);
			for(int i=35;i>=0;i--)
			{
				gotoXY(i,7);
				printf("=");
				Sleep(10);
			}
			TextColor(7);
			gotoXY(0,8);
			printf("   NHAP PHIM BAT KI DE VAO GAME");
			gotoXY(0,0);
			if(_kbhit())
			{

				ktphim=1;
				break;
			}
		}	
	}	
	getch();
}
void wait()
{
	getch();
}	
void xoaO(Snake snake)
{
	gotoXY(snake.than[snake.n-1].x,snake.than[snake.n-1].y);
	printf(" ");

}
void map()
{

	TextColor(17);
	printf("                                   \n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("  ");TextColor(7);printf("                               ");TextColor(17);printf("  ");printf("\n");
	printf("                                   \n");
	TextColor(7);									
}
int endgame(Snake snake)
{
	int endgame;
	endgame=0;
	if(snake.than[0].y==0 || snake.than[0].y==22 || snake.than[0].x==1 || snake.than[0].x==33)
	{
		endgame=1;
	}
	return endgame;

}
int endgamesnake(Snake snake)
{
	int endgame;
	endgame=0;
	for(int i=2;i<snake.n;i++)
	{
		if(snake.than[0].x==snake.than[i].x && snake.than[0].y==snake.than[i].y)
			endgame=1;
	}
	return endgame;
}
void FooD(Tao_Do &Food,Snake snake)
{
	int giong;
	giong=1;
	while(giong==1)
	{
		Food.x=2+rand()%31;
		Food.y=1+rand()%21;
		for(int i=0;i<snake.n;i++)
		{
			if(snake.than[i].x!=Food.x && snake.than[i].y!=Food.y)
			{
				giong=0;break;
			}
		}	
	}
}
void artfood(Tao_Do food)
{
	gotoXY(food.x,food.y);
	TextColor(4);
	printf("*");
	TextColor(7);
}
void artscore(int score)
{
	gotoXY(36,1);
	printf("SCORE=%d",score);

}
void artuse()
{
	gotoXY(2,24);
	printf("Navigation key: A,W,S,D press Space to pause ");

}
void coChe(Snake &snake)
{
	for(int i=snake.n-1;i>0;i--)
	{
		snake.than[i].x=snake.than[i-1].x;
		snake.than[i].y=snake.than[i-1].y;
	}
}
void veRan(Snake snake)
{
	for(int i=0;i<snake.n;i++)
	{
		gotoXY(snake.than[i].x,snake.than[i].y);
		if(i==0)
		{
			TextColor(5);
			printf("@");
		}
		else
		{
			TextColor(3);
			printf("0");
		}


	}
}
int eatfood(Snake &snake,Tao_Do food,int &score)
{
	int kq=0; 
	if(snake.than[0].x==food.x && snake.than[0].y==food.y )
	{
		snake.n++;
		kq=1;
		score++;
	}
	return kq;
}
void chinh (Snake snake,char &traloi)
{
	Tao_Do food;
	int End;
	End=0;
	int score;
	score=0;
	char key;
	srand ( (unsigned int)time(NULL) );
	FooD(food,snake);
	map();
	artfood(food);
	artscore(score);
	artuse();
	veRan(snake);
	xoaO(snake);
	getch();
	while (End==0)
	{

		artfood(food);
		artscore(score);
		artuse();
		if(eatfood(snake,food,score)==1)
		{
			FooD(food,snake);
		}
		if(kbhit())
		{
			key=getch();
			if(key==32)
			{
				pausegame();
			}
			if((key=='a'||key=='A' )&& snake.tt!=RIGHT)
			{
				snake.tt=LEFT;
			}
			if((key=='w'|| key=='W')&& snake.tt!=DOWN)
			{
				snake.tt=UP;
			}
			if((key=='d'||key=='D')&& snake.tt!=LEFT )
			{
				snake.tt=RIGHT;
			}
			if((key=='s'|| key=='S') && snake.tt!=UP)
			{
				snake.tt=DOWN;
			}
		}
		coChe(snake);
		switch(snake.tt)
		{
		case UP: snake.than[0].y--;break;
		case DOWN:snake.than[0].y++;break;
		case LEFT: snake.than[0].x--;break;
		case RIGHT:snake.than[0].x++;break;
		}
		veRan(snake);
		xoaO(snake);

		if(endgame(snake)==1)
		{
			End=1;
		}
		if(endgamesnake(snake)==1)
		{
			End=1;
		}

		Sleep(100);
		gotoXY(0,0);
	}
	if(End==1)
	{
		gotoXY(36,3);
		TextColor(5);
		printf("Game Over");
		TextColor(7);
		gotoXY(36,4);
		printf("Nhan ENTER de choi lai, ESC de thoat!!!!!");
		traloi=getch();
	}
}