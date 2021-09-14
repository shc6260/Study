#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef struct grade 
{
	int n;
	int s;
	int	b;
	int x;
}Grade;

int rule (void);//숫자 갯수
void random (int * num,int count);//숫자받음
int play (int * player,int count);//플레이어
int sbout (char * test , int num[10] , int player[10],int count);//판단
void referee (char test[10],int count,Grade * pscore,int op);//심판
//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos); 좌표 함수
int main (void)
{
	int count,i,end,op=-1,j,opt;
	COORD pos,sc={40,2};
	int num[10],player[10];
	char test[10];
	Grade score[50];
	system("mode con: cols=40 lines=5");
	count=rule();
	random(num,count);

	system("mode con: cols=70 lines=55");
	for(;;)
	{
		op += 1;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),sc);
		printf("★점       수        판★");

		for(i=1 ; i<=54 ;i++)
		{
			pos.X=34; pos.Y=i;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
			printf("│\n");
		}
		for(i=1; i<=op ; i++)
		{
			pos.X=36; pos.Y=i+3;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);

			printf("%2dSET : ",i);
			if(player[0]==0 && count>=2)
				printf("0");
			printf("%d │ %dS %dB %dOUT",score[i-1].n,score[i-1].s,score[i-1].b,score[i-1].x);
		}

		if(op == 50)
		{
			system("cls");
			printf("정답 : ");
			for(i=1 ; i<=count ; i++)
				printf("%d",num[i-1]);
			printf("\n");
			printf("GAMEOVER\n");
			break ;
		}

		pos.X=0; pos.Y=0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
		
		score[op].n=play(player,count);
		end=sbout(test,num,player,count);
		if(end == count)
		{
			system("cls");
			printf("스트라이크\n");
			break;
		}
		
		referee(test,count,score,op);
		system("cls");
	}
	return 0;
}

int rule (void)//숫자 갯수
{
	int count;

	for(;;)
	{
		printf("숫자 갯수 입력 (1-10) : "); scanf("%d",&count);
		if(count>=1 && count<=10)
			break;
		else
		{
			system("cls");
			printf("다시 입력해 주세요.\n");
			getchar();
		}
	}
	return count;
}

void random (int * num,int count)//숫자받음
{
	int i,op,sun=10;
	int su[10]={0,1,2,3,4,5,6,7,8,9};

	srand((unsigned)time(NULL));
	for(i=1;i<=count;i++)
	{
		op=rand()%sun;
		num[i-1]=su[op];
		su[op]=su[sun-1];
		sun-=1;
	}
}
int play (int * player,int count)//플레이어
{
	int i,j,num,A,ten=1,re=0;

	printf("한자리씩 입력 \n");
		for(i=1 ; i<=count ; i++)
		{
			printf("%d자리 : ",i); scanf("%d",&num);
			if(num>=10 || num <= -1)
			{
				printf("\r다시 입력하세요.\n");
				getchar();
				i--;
			}
			else
			{
				for(j=1 ; j<i ; j++)
				{
					if(num==player[j-1])
					{
						printf("중복된 숫자 입니다. \n");
						i--;
						break;
					}
				}
				player[i-1]=num;
			}

		}
	for(i=1 ; i <= count ; i++)
	{
		for(j=1 ; j <= count-i ; j++)
			ten*=10;
		A=ten*player[i-1];
		re+=A;
		ten=1;
	}
	return re;
}

int sbout (char * test , int num[10] , int player[10],int count)//판정
{
	int i,j,end=0;

	for(i=1 ; i<=count ; i++)
				test[i-1] = num[i-1] == player[i-1] ? 's' : 'x';
			for(i=1 ; i<=count ; i++)
			{
				if(test[i-1]=='s')
				{
					end+=1;
					continue;
				}
				for(j=1 ; j<=count ; j++)
				{
					if(num[i-1] == player[j-1])
					{
						test[i-1]='b';
						break;
					}
				}
			}
	return end;
}

void referee (char test[10],int count,Grade * pscore,int op)//심판
{
	int i;

	pscore[op].b=0;
	pscore[op].s=0;
	pscore[op].x=0;

	for(i=1 ; i<=count ; i++)
	{

		if(test[i-1]=='s')
			pscore[op].s +=1;
		else if(test[i-1]=='b')
			pscore[op].b +=1;
		else if(test[i-1]=='x')
			pscore[op].x +=1;
	}
}