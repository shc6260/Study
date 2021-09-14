#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
typedef struct manage//상품 추가
{
 char name[10];
 int number;
 int price;
} MANAGE;
int passw = 8260;
void manshape (void);
void shape (int money,MANAGE item[6]);//틀
int moneyin (void);//돈 삽입
int option (int * money,MANAGE * pitem);//메뉴 선택
void drink (void);
void selete (MANAGE * item,int **money);
MANAGE managermod (void);
int main (void)
{
 int money=0,A;
 MANAGE item[6]={{"비었음",0,-1},{"비었음",0,-1},{"비었음",0,-1},{"비었음",0,-1},{"비었음",0,-1},{"비었음",0,-1}};
 system("mode con: cols=100 lines=30");
 while(1)
 {
  shape(money,item);
  A=option(&money,item);
  getchar();
  system("cls");
  if(A!=1)
   break ;
 }
 return 0;
}
void shape (int money,MANAGE item[6])
{
 printf("\n                                          자판기                                             \n\n");
 printf("              %6d      %6d      %6d      %6d      %6d      %6d              │ \n",1,2,3,4,5,6);
 printf("┌───┬──────────────────────────────────────────┐\n");
 printf("│ 상품 │    %6s      %6s      %6s      %6s      %6s      %6s              │ \n",item[0].name,item[1].name,item[2].name,item[3].name,item[4].name,item[5].name);
 printf("├───┼──────────────────────────────────────────┤\n");
 printf("│ 재고 │    %6d      %6d      %6d      %6d      %6d      %6d              │ \n",item[0].number,item[1].number,item[2].number,item[3].number,item[4].number,item[5].number);
 printf("├───┼──────────────────────────────────────────┤\n");
 printf("│ 가격 │    %6d      %6d      %6d      %6d      %6d      %6d              │ \n",item[0].price,item[1].price,item[2].price,item[3].price,item[4].price,item[5].price);
 printf("├───┴──────────────────────────────────────────┤\n");
 printf("│                                                                  잔액 : %6d             │\n",money);
 printf("│                                                              ┌──────────────┤\n");
 printf("│                                                              │   1.   돈 삽입             │\n");
 printf("│                                                              │   2.   음료 선택           │\n");
 printf("│                                                              │   3.   돈 반환 & 탈출      │\n");
 printf("│                                                              │   4.   관리자 모드         │\n");
 printf("│                                                              │                            │\n");
 printf("└───────────────────────────────┴──────────────┘\n");
}
int moneyin (void)
{
 int won;
 printf("\n\n\n\n\n\n\n\n\n\n돈을 넣어주세요.\n");
 scanf("%d",&won);
 system("cls");
 return won;
}
int option (int * money,MANAGE * pitem)
{
 int op=0,pass=0,i=0,opt=0,add=0;
 printf("선택 : ");
 scanf("%d",&op);
 switch(op)
 {
 case 1:
  *money += moneyin();
  return 1;
 case 2:
  selete(pitem,&money);
  return 1;
 case 3:
  system("cls");
  printf(" %d원 반환\n",*money);
  Sleep(1000);
  return 0;
 case 4://관리자 모드
  printf("비밀번호 입력 : "); scanf("%d",&pass);
  if(passw!=pass)
  {
   system("cls");
   printf("비밀번호가 틀렸습니다\n");
   return 1;
  }
  while(1)
  {
   system ("cls");
   manshape(); scanf("%d",&opt);
   if(opt==1)
   {
    printf("슬롯 선택 : "); scanf("%d",&i);
	getchar();
    pitem[i-1] = managermod();
    break ;
   }
   else if (opt == 2)
   {
    printf("슬롯 선택 : "); scanf("%d",&i);
    printf("추가할 수량 : "); scanf("%d",&add);
    pitem[i-1].number += add;
    break ; 
   }
   else if (opt == 3)
   {
    printf("슬롯 선택 : "); scanf("%d",&i);
    printf("변경할 가격 : "); scanf("%d",&pitem[i-1].price);
    break ;
   }
   else if (opt == 4)
   {
    return 1;
   }
   else
     return 1;
  }
 default:
  opt=0;
  return 1;
 } 
}
MANAGE managermod (void)
{
 MANAGE item;
 printf("음료 종류 입력 : "); scanf("%s",&item.name);
 printf("갯수 입력 : "); scanf("%d",&item.number);
 printf("가격 입력 : "); scanf("%d",&item.price);
 system("cls");
 return item;
}
void manshape (void)
{
 printf("┌─────────────────────┐\n");
 printf("│                                          │\n");
 printf("│  1.음료 삽입                             │\n");
 printf("│                                          │\n");
 printf("│  2.재고 추가                             │\n");
 printf("│                                          │\n");
 printf("│  3.가격 변경                             │\n");
 printf("│                                          │\n");
 printf("│  4.관리자 모드 나가기                    │\n");
 printf("│    (아무거나 입력해도 종료)              │\n");
 printf("└─────────────────────┘\n");
}
void selete (MANAGE * tpitem,int ** money)
{
 int op,i;
 printf("선택 : "); scanf("%d",&op);
 if(tpitem[op-1].price == -1)
  printf("빈슬롯 입니다 \n");
 else
  if(tpitem[op-1].number>0)
   if(**money >= tpitem[op-1].price)
   {
    tpitem[op-1].number -= 1;
    **money -= tpitem[op-1].price;
    printf("(%s) \n",tpitem[op-1].name);
   }
   else
    printf("돈이 모자랍니다. 돈을 넣어주세요!! \n");
  else if(tpitem[op-1].number<=0 && **money < tpitem[op-1].price)
   printf("돈과 상품의 재고가 모자랍니다. \n");
  else
   printf("상품의 재고가 없습니다. \n");
  printf("엔터키를 눌러주세요"); fgetc(stdin);
}