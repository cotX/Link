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


SListNode* BuySListNode(DataType data);
void Print(SListNode* pList);
void SListInit(SListNode** pHead);

void SListPushBack(SListNode* pHead, DataType data);
void SListPopBack(SListNode* pHead);
void SListPushFront(SListNode* pHead, DataType data);
void SListPopFront(SListNode* pHead);
void SListInsert(SListNode* pHead, DataType data);
void SListErase(SListNode* pHead, DataType data);
void SListDestroy(SListNode* pHead);
int SListSize(SListNode* pHead);
int SListempty(SListNode* pHead);
void SListRemove(SListNode* pHead, DataType data);
void RemoveAll(SListNode* pHead,DataType data);
DataType Front(SListNode* pHead);
DataType Back(SListNode* pHead);

SListNode* SListFind(SListNode* pHead, DataType data);


#endif

