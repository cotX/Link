#include "link.h"


/*��ӡ����*/
void Print(SListNode* pList)
{
	for (;pList;pList=pList->Next)
	{
		printf("%d->", pList->data);
	}
	printf("NULL\n");
}
/*�����½ڵ�*/
SListNode* BuySListNode(DataType data)
{
	SListNode* pNewNode = (SListNode*)malloc(sizeof(SListNode));
	if (NULL == pNewNode)
		exit(1);
	pNewNode->data = data;
	pNewNode->Next = NULL;
	return pNewNode;
}
/*�����ʼ��*/
void SListInit(SListNode** pHead)
{
	SListPushBack(pHead, 1);
	SListPushBack(pHead, 2);
	SListPushBack(pHead, 3);
	SListPushBack(pHead, 4);
	SListPushBack(pHead, 5);
}
/*β��*/
void SListPushBack(SListNode* pHead, DataType data)
{
	SListNode* pCur=pHead;
	SListNode* pNewNode=BuySListNode(data);
		while (pCur->Next)
		{
			pCur = pCur->Next;
		}
	pCur->Next = pNewNode;	
}
/*βɾ*/
void SListPopBack(SListNode* pHead)
{
	SListNode* pfast=pHead;
	SListNode* psolw=pHead;
	if (NULL == pfast->Next) { 
		pfast = NULL; 
		return;
	}
	pfast = pfast->Next;
	while (pfast->Next)
	{
		pfast = pfast->Next;
		psolw = psolw->Next;
	}
	psolw->Next = NULL;
}
/*ͷ��*/
void SListPushFront(SListNode* pHead,DataType data)
{
	SListNode* pCur = pHead;
	SListNode* pNewNode = BuySListNode(data);
	pNewNode->Next=pCur->Next;
	pCur->Next = pNewNode;
}
/*ͷɾ*/
void SListPopFront(SListNode* pHead)
{
	SListNode* pCur = &(pHead->Next);
	pHead->Next=pHead->Next->Next;
	pCur=NULL;
}
/*����data*/
SListNode* SListFind(SListNode* pHead, DataType data) 
{
	SListNode *pCur = pHead;
	for (; pCur->Next; pCur = pCur->Next)
	{
		if (data == pCur->data)
		{
			return pCur;
		}
	}
	
}
/*������λ�ò���*/
void SListInsert(SListNode* pHead, DataType data)
{
	DataType _data;
	SListNode* pNewNode = BuySListNode(data);
	Print(pHead->Next);
	printf("���������ĸ����ֺ���루��һ��ǰ���밴0����");
	scanf("%d", &_data);
	if (0 == _data)
	{
		SListPushFront(pHead, data);
		return ;
	}
	pNewNode->Next = SListFind(pHead, _data)->Next;
	SListFind(pHead, _data)->Next = pNewNode;
}
/*ɾ������ڵ�*/
void SListErase(SListNode* pHead, DataType data)
{
	SListNode *pCur = pHead;
	if (NULL == pCur)
	{
		return ;
	}
	while (pCur->Next)
	{
		if (data == pCur->Next->data)
		{
			SListNode* pDel = pCur->Next;
			pCur->Next = pCur->Next->Next;
			pDel = NULL;
			free(pDel);
			break;
		}
	}
}
/*���ٱ�*/
void SListDestroy(SListNode* pHead)
{
	SListNode* pCur = pHead->Next;
	while (pCur)
	{
		SListNode* pDel = pCur;
		pCur = pCur->Next;
		free(pDel);
	}
}
/*���нڵ����*/
int SListSize(SListNode* pHead)
{
	int size=0;
	if (NULL == pHead){
		return size;
	}
	SListNode* pCur = pHead->Next;
	while (pCur)
	{
		size++;
		pCur = pCur->Next;
	}
	return size;
}
/*�п�*/
int SListempty(SListNode* pHead)
{
	if (NULL == pHead->Next)
		return 0;
	else return 1;
}
/*���ص�һ���ڵ��е���*/
DataType Front(SListNode* pHead)
{
	if (NULL == pHead)
		return NULL;
	return pHead->Next->data;
}
/*�������һ���ڵ��е���*/
DataType Back(SListNode* pHead)
{
	if (NULL == pHead)
		return NULL;
	while (pHead->Next)
	{
		pHead = pHead->Next;
	}
	return pHead->data;
}
/*ɾ����һ��ֵΪdata�Ľڵ�*/
void SListRemove(SListNode* pHead,DataType data)
{
	while (pHead->Next)
	{
		if (data == pHead->Next->data){
			SListNode* pCur = pHead->Next;
			pHead->Next = pHead->Next->Next;
			free(pCur);
			break;
		}
		pHead = pHead->Next;
	}
}
/*ɾ������data*/
void RemoveAll(SListNode* pHead,DataType data)
{
	SListNode *pCur = pHead;
	if (NULL == pCur)
	{
		return;
	}
	while (pCur->Next)
	{
		if (data == pCur->Next->data)
		{
			SListNode* pDel = pCur->Next;
			pCur->Next = pCur->Next->Next;
			pDel = NULL;
			free(pDel);
			if (NULL == pCur->Next)
				break;
		}
		if (data != pCur->Next->data)
			pCur = pCur->Next;
	}
}
/*ð������*/
void SListBubbleSort(SListNode* pHead)
{
	int size = SListSize(pHead);
	SListNode* pCur = pHead;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size-1-i; j++)
		{
			if (pCur->Next->data>pCur->Next->Next->data)
			{

			}
		}
	}
}

