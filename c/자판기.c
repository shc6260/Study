#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
typedef struct manage//��ǰ �߰�
{
 char name[10];
 int number;
 int price;
} MANAGE;
int passw = 8260;
void manshape (void);
void shape (int money,MANAGE item[6]);//Ʋ
int moneyin (void);//�� ����
int option (int * money,MANAGE * pitem);//�޴� ����
void drink (void);
void selete (MANAGE * item,int **money);
MANAGE managermod (void);
int main (void)
{
 int money=0,A;
 MANAGE item[6]={{"�����",0,-1},{"�����",0,-1},{"�����",0,-1},{"�����",0,-1},{"�����",0,-1},{"�����",0,-1}};
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
 printf("\n                                          ���Ǳ�                                             \n\n");
 printf("              %6d      %6d      %6d      %6d      %6d      %6d              �� \n",1,2,3,4,5,6);
 printf("������������������������������������������������������������������������������������������������\n");
 printf("�� ��ǰ ��    %6s      %6s      %6s      %6s      %6s      %6s              �� \n",item[0].name,item[1].name,item[2].name,item[3].name,item[4].name,item[5].name);
 printf("������������������������������������������������������������������������������������������������\n");
 printf("�� ��� ��    %6d      %6d      %6d      %6d      %6d      %6d              �� \n",item[0].number,item[1].number,item[2].number,item[3].number,item[4].number,item[5].number);
 printf("������������������������������������������������������������������������������������������������\n");
 printf("�� ���� ��    %6d      %6d      %6d      %6d      %6d      %6d              �� \n",item[0].price,item[1].price,item[2].price,item[3].price,item[4].price,item[5].price);
 printf("������������������������������������������������������������������������������������������������\n");
 printf("��                                                                  �ܾ� : %6d             ��\n",money);
 printf("��                                                              ��������������������������������\n");
 printf("��                                                              ��   1.   �� ����             ��\n");
 printf("��                                                              ��   2.   ���� ����           ��\n");
 printf("��                                                              ��   3.   �� ��ȯ & Ż��      ��\n");
 printf("��                                                              ��   4.   ������ ���         ��\n");
 printf("��                                                              ��                            ��\n");
 printf("������������������������������������������������������������������������������������������������\n");
}
int moneyin (void)
{
 int won;
 printf("\n\n\n\n\n\n\n\n\n\n���� �־��ּ���.\n");
 scanf("%d",&won);
 system("cls");
 return won;
}
int option (int * money,MANAGE * pitem)
{
 int op=0,pass=0,i=0,opt=0,add=0;
 printf("���� : ");
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
  printf(" %d�� ��ȯ\n",*money);
  Sleep(1000);
  return 0;
 case 4://������ ���
  printf("��й�ȣ �Է� : "); scanf("%d",&pass);
  if(passw!=pass)
  {
   system("cls");
   printf("��й�ȣ�� Ʋ�Ƚ��ϴ�\n");
   return 1;
  }
  while(1)
  {
   system ("cls");
   manshape(); scanf("%d",&opt);
   if(opt==1)
   {
    printf("���� ���� : "); scanf("%d",&i);
	getchar();
    pitem[i-1] = managermod();
    break ;
   }
   else if (opt == 2)
   {
    printf("���� ���� : "); scanf("%d",&i);
    printf("�߰��� ���� : "); scanf("%d",&add);
    pitem[i-1].number += add;
    break ; 
   }
   else if (opt == 3)
   {
    printf("���� ���� : "); scanf("%d",&i);
    printf("������ ���� : "); scanf("%d",&pitem[i-1].price);
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
 printf("���� ���� �Է� : "); scanf("%s",&item.name);
 printf("���� �Է� : "); scanf("%d",&item.number);
 printf("���� �Է� : "); scanf("%d",&item.price);
 system("cls");
 return item;
}
void manshape (void)
{
 printf("����������������������������������������������\n");
 printf("��                                          ��\n");
 printf("��  1.���� ����                             ��\n");
 printf("��                                          ��\n");
 printf("��  2.��� �߰�                             ��\n");
 printf("��                                          ��\n");
 printf("��  3.���� ����                             ��\n");
 printf("��                                          ��\n");
 printf("��  4.������ ��� ������                    ��\n");
 printf("��    (�ƹ��ų� �Է��ص� ����)              ��\n");
 printf("����������������������������������������������\n");
}
void selete (MANAGE * tpitem,int ** money)
{
 int op,i;
 printf("���� : "); scanf("%d",&op);
 if(tpitem[op-1].price == -1)
  printf("�󽽷� �Դϴ� \n");
 else
  if(tpitem[op-1].number>0)
   if(**money >= tpitem[op-1].price)
   {
    tpitem[op-1].number -= 1;
    **money -= tpitem[op-1].price;
    printf("(%s) \n",tpitem[op-1].name);
   }
   else
    printf("���� ���ڶ��ϴ�. ���� �־��ּ���!! \n");
  else if(tpitem[op-1].number<=0 && **money < tpitem[op-1].price)
   printf("���� ��ǰ�� ��� ���ڶ��ϴ�. \n");
  else
   printf("��ǰ�� ��� �����ϴ�. \n");
  printf("����Ű�� �����ּ���"); fgetc(stdin);
}