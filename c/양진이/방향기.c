#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>

//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);

int main()
{
	int nkey=0,MB[5]={0,0,0,0,0},op=0,opt[5]={0,0,0,0,0},i=0,s;
	COORD pos={35,50};
	COORD gun[5];
	clock_t start = clock();

	system("mode con: cols=70 lines=55");
	//CursorHide();

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
	printf("(^¿À^)");


	for( ; ; )
	{


		if(_kbhit())
		{

			nkey = getch();		
			op=1;
		}

		if(nkey == 'q')
		{
			break;
		}

		if(nkey==' ')
		{
			if(i>=5)
				i=0;
			opt[i]=1;
			i++;
		}

		for(s=0 ; s<=4 ; s++)
		{
			if(opt[i]==0)
				continue;

			if(MB[s]<3)
			{
				gun[s].X=pos.X+2;
				gun[s].Y=pos.Y-1;
				MB[s]=pos.Y;
			}
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),gun[s]);
			printf( " ");
			MB[s]--;
			gun[s].Y--;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),gun[s]);
			printf("¦¢");

			if(MB[s]<=2)
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),gun[s]);
				printf(" ");
				opt[i]=0;
			}
		}
		switch(nkey)
		{
		case 77 : 
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
				printf("      ");
				pos.X++;
				nkey = -1;
				break;
			}
		case 75:
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
				printf("      ");
				pos.X--;
				nkey = -1;
				break;
			}
		case 72:
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
				printf("      ");
				pos.Y--;
				nkey = -1;
				break;
			}
		case 80:
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
				printf("      ");
				pos.Y++;
				nkey = -1;
				break;
			}
		default :             
			{
				break;
			}
		}
		nkey=0;
		if(op==1)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
			printf("(^¿À^)");
			op=0;
		}
		Sleep(10);
	}
	return 0;
}