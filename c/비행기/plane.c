#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<turboc.h>
#include"bullet.h"

typedef struct plane 
{
	COORD pos;//ÁËÇ¥
	int gt;//ÃÑ¾Ë ¹æÇâ
	int GO;//ÃÑ¾Ë ¹ß»ç ÇÒ²«Áö
	int GS;//ÃÑ¾Ë °£°Ý
	List gun;//ÃÑ¾Ë 7°³
}Plane;

void Cplayer(COORD  pos)
{
	pos.X -= 3;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	printf("¦£¦ª¦¤");
}

void Dplayer(COORD  pos)
{
	pos.X -= 3;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	printf("     ");

}

void keyboard(Plane * PL)
{
	if(GetAsyncKeyState(VK_UP) && 0x8000)
	{
		if(PL -> pos .Y<=10) PL->pos .Y++;
		PL->pos .Y--;
	}
	if(GetAsyncKeyState(VK_DOWN) && 0x8000) 
	{
		if(PL -> pos .Y>=42) PL->pos .Y--;
		PL -> pos .Y++;
	}
	if(GetAsyncKeyState(VK_LEFT) && 0x8000)
	{
		if(PL -> pos .X<=4) PL->pos .X++;
		PL -> pos .X--;
	}
	if(GetAsyncKeyState(VK_RIGHT) && 0x8000)
	{
		if(PL -> pos .X>=64) PL->pos .X--;
		PL -> pos .X++;
	}
	if(GetAsyncKeyState(VK_SPACE) && 0x8000) 
	{
		PL -> GO = 1;
	}
}

void bulletup (Plane * PL, COORD * enemy)
{
	int G,i=0;

	if(PL ->GO == 1 && PL->GS >= 7)
	{
		bulletInsert(&(PL->gun) , PL->pos);
		PL->gun.arr[PL->gun.numOfData -1].X -= 1;
		PL->gun.arr[PL->gun.numOfData -1].Y -= 1;
		PL->GS = 0;
		PL->GO = 0;
	}
	for(G=0 ;G < PL->gun.numOfData ; G++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),PL->gun.arr[G]);
		printf(" ");
		PL->gun.arr[G].Y--;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),PL->gun.arr[G]);
		printf("¦¢");
		i = bullethit(&(PL ->gun) ,&enemy,G);
		if(i == 1)
			G-- , i = 0;
	}
	if(PL->gun.arr[0].Y < 2)
		bulletend(&(PL -> gun));
	PL->GS+=1;
}

void bulletdown (Plane * PL)
{//PL À¯´Ö ±¸Á¶Ã¼
	int G;

	if(PL ->GO == 1 && PL->GS >= 7)
	{
		bulletInsert(&(PL->gun) , PL->pos);
		PL->gun.arr[PL->gun.numOfData -1].X -= 1;
		PL->gun.arr[PL->gun.numOfData -1].Y -= 1;
		PL->GS = 0;
		PL->GO = 0;
	}
	for(G=0 ;G < PL->gun.numOfData ; G++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),PL->gun.arr[G]);
		printf(" ");
		PL->gun.arr[G].Y++;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),PL->gun.arr[G]);
		printf("¦¢");
	}
	if(PL->gun.arr[0].Y > 43)
		bulletend(&(PL -> gun));
	PL->GS+=1;
}

void movgun(Plane * PL,COORD * enemy)
{
	if(PL->gt == 1)
	{
		if(PL->gun.arr[0].Y < 2 && PL -> GO ==0)
			return;
		bulletup(PL,enemy);
	}

	if(PL-> gt == 0)
	{
		if(PL->gun.arr[0].Y > 43 && PL -> GO ==0)
			return;
		bulletdown(PL);
	}
}

int main()
{
	int EC=0,GS=7,opt=0; //EC = ÀûÀ¯´Ö  Ä«¿îÆ® , GS = ÃÑ¾Ë °£°Ý
	Plane PL={{35,40},1,0,7};
	COORD QWE={35,10};
	bulletInit(&PL.gun);
	
	system("mode con: cols=70 lines=45");
	Cplayer(PL.pos);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),QWE);
	printf("¦ª");

	for( ; ; )
	{ 
		Dplayer(PL.pos);

		keyboard(&PL);

		movgun(&PL,&QWE);

		Cplayer(PL.pos);
	}

	Sleep(20);

	return 0;
} 
