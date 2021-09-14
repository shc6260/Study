#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include<turboc.h>
#include"bullet.h"

typedef struct plane
{
	COORD pos;//죄표
	int gt;//총알 방향
	int GO;//총알 발사 할껀지
	int GS;//총알 간격
	List gun;//총알 7개
}Plane;

void Cplayer(COORD  pos)
{
	pos.X -= 3;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("┌┴┐");
}

void Dplayer(COORD  pos)
{
	pos.X -= 3;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("     ");

}

void keyboard(Plane* PL)
{
	if (GetAsyncKeyState(VK_UP) && 0x8000)
	{
		if (PL->pos.Y <= 10) PL->pos.Y++;
		PL->pos.Y--;
	}
	if (GetAsyncKeyState(VK_DOWN) && 0x8000)
	{
		if (PL->pos.Y >= 42) PL->pos.Y--;
		PL->pos.Y++;
	}
	if (GetAsyncKeyState(VK_LEFT) && 0x8000)
	{
		if (PL->pos.X <= 4) PL->pos.X++;
		PL->pos.X--;
	}
	if (GetAsyncKeyState(VK_RIGHT) && 0x8000)
	{
		if (PL->pos.X >= 64) PL->pos.X--;
		PL->pos.X++;
	}
	if (GetAsyncKeyState(VK_SPACE) && 0x8000)
	{
		PL->GO = 1;
	}
}

void bulletup(Plane* PL, COORD* enemy)
{
	int G, i = 0;

	if (PL->GO == 1 && PL->GS >= 7) //스페이스바가 눌렸는지 총알 갯수가 넘지 않았는지 비교
	{
		bulletInsert(&(PL->gun), PL->pos);//총알 리스트와 유닛 좌표
		PL->gun.arr[PL->gun.numOfData - 1].X -= 1; //커서가 유닛의 중앙에 있지 않기때문에 옮김
		PL->gun.arr[PL->gun.numOfData - 1].Y -= 1; //유닛 위 한칸에서 발사
		PL->GS = 0;
		PL->GO = 0;
	}
	for (G = 0; G < PL->gun.numOfData; G++) //총알 전체를 앞으로 보냄
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), PL->gun.arr[G]);
		printf(" ");
		PL->gun.arr[G].Y--;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), PL->gun.arr[G]);
		printf("│");
		i = bullethit(&(PL->gun), &enemy, G);
		if (i == 1)
			G--, i = 0;
	}
	if (PL->gun.arr[0].Y < 2)
		bulletend(&(PL->gun));
	PL->GS += 1;
}

void bulletdown(Plane* PL)
{//PL 유닛 구조체
	int G;

	if (PL->GO == 1 && PL->GS >= 7)
	{
		bulletInsert(&(PL->gun), PL->pos);
		PL->gun.arr[PL->gun.numOfData - 1].X -= 1;
		PL->gun.arr[PL->gun.numOfData - 1].Y -= 1;
		PL->GS = 0;
		PL->GO = 0;
	}
	for (G = 0; G < PL->gun.numOfData; G++)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), PL->gun.arr[G]);
		printf(" ");
		PL->gun.arr[G].Y++;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), PL->gun.arr[G]);
		printf("│");
	}
	if (PL->gun.arr[0].Y > 43)
		bulletend(&(PL->gun));
	PL->GS += 1;
}

void movgun(Plane* PL, COORD** enemy)
{
	if (PL->gt == 1)
	{
		if (PL->gun.arr[0].Y < 2 && PL->GO == 0)
			return;
		bulletup(PL, enemy);
	}

	if (PL->gt == 0)
	{
		if (PL->gun.arr[0].Y > 43 && PL->GO == 0)
			return;
		bulletdown(PL);
	}
}

int enmove(COORD ** en, int ECi) {
	srand(time(NULL));
	int enpoY ;// 적 좌표
	int enpoX ;// 적 좌표
	int i;

	for (i = 0; i <= ECi; i++) {
		enpoY = (rand() % 10) + 1;// 적 좌표
		enpoX = (rand() % 61) + 4;// 적 좌표

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *en[i]);
		printf(" ");

		en[i]->Y = enpoY;
		en[i]->X = enpoX;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), *en[i]);
		printf("ㅜ");
	}
}

int main()
{
	int EC = 0, ES = 10 ; //EC = 적유닛  카운트 , GS = 총알 간격
	Plane PL = { {35,40},1,0,7 };
	COORD QWE[10] = { 0,0 };
	bulletInit(&PL.gun);

	system("mode con: cols=70 lines=45");
	Cplayer(PL.pos);

	

	for (; ; )
	{
		ES += 1;

		if (ES >= 10) {
			enmove(&QWE, EC);
			EC += 1;

		}
		
		
		Dplayer(PL.pos);

		keyboard(&PL);

		movgun(&PL, &QWE);

		Cplayer(PL.pos);

		Sleep(20);

		if (EC > 10) {
			printf("Rmx");
		}

	}

	Sleep(10);

	return 0;
}
