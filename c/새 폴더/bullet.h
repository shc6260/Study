#include<Windows.h>  

#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__


#define TRUE	1
#define FALSE	0

#define LIST_LEN	7

typedef struct __ArrayList
{
	COORD arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList;


typedef ArrayList List;

void bulletInit(List * plist);
void bulletInsert(List * plist, COORD data);
int bullethit(List * Plist, COORD ** enemy, int G);
void bulletend(List * plist);

#endif