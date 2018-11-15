#ifndef __TEST__
#define __TEST__

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning(disable:4996)

typedef int DataType;

typedef struct SListNode
{
	struct SListNode *Next;
	DataType data;
}SListNode;

void Print(SListNode* pList);
SListNode* BuySListNode(DataType data);
void SListInit(SListNode* pHead);
void SListPushBack(SListNode* pHead, DataType data);
void SListpopBack(SListNode* pHead);


#endif

