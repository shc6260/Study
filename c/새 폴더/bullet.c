#include <stdio.h>
#include<Windows.h>
#include "bullet.h"

void bulletInit(List * plist)
{
	int i;
	(plist->numOfData) = 0;
	(plist->curPosition) = -1;
	for(i=0 ; i<7 ; i++)
		plist->arr[i].X=0 , plist->arr[i].Y=0;
}

void bulletInsert(List * plist, COORD data)
{
	if(plist->numOfData > LIST_LEN) 
	{
		return;
	}

	plist->arr[plist->numOfData] = data; //유닛의 현재위치를 저장
	(plist->numOfData)++;
}


int bullethit(List * Plist, COORD ** enemy,int G)
{
	int i;

	if(Plist->arr[G].X == (*enemy)->X && Plist->arr[G].Y == (*enemy)->Y)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Plist->arr[G]);
		printf(" ");

		for(i=G; i< Plist->numOfData-1; i++)
			Plist->arr[i] = Plist->arr[i+1];

		Plist->arr[Plist->numOfData].X=0 , Plist->arr[Plist->numOfData].Y=0;
		Plist->numOfData--;

		(*enemy)->X = 0;
		(*enemy)->Y = 0;

		return 1;
	}

}

void bulletend(List * plist)
{
	int rpos = 0;
	int i;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),plist->arr[0]);
	printf(" ");

	for(i=rpos; i< plist->numOfData-1; i++)
		plist->arr[i] = plist->arr[i+1];

	plist->arr[6].X=0 , plist->arr[6].Y=0;

	(plist->numOfData)--;
	return ;
}
