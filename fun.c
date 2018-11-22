#include "link.h"


/*打印链表*/
void Print(SListNode* pList)
{
	for (;pList;pList=pList->Next)
	{
		printf("%d->", pList->data);
	}
	printf("NULL\n");
}
/*建立新节点*/
SListNode* BuySListNode(DataType data)
{
	SListNode* pNewNode = (SListNode*)malloc(sizeof(SListNode));
	if (NULL == pNewNode)
		exit(1);
	pNewNode->data = data;
	pNewNode->Next = NULL;
	return pNewNode;
}
/*链表初始化*/
void SListInit(SListNode** pHead)
{
	SListPushBack(pHead, 1);
	SListPushBack(pHead, 3);
	SListPushBack(pHead, 5);
	SListPushBack(pHead, 2);
	SListPushBack(pHead, 4);
}
/*尾插*/
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
/*尾删*/
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
/*头插*/
void SListPushFront(SListNode* pHead,DataType data)
{
	SListNode* pCur = pHead;
	SListNode* pNewNode = BuySListNode(data);
	pNewNode->Next=pCur->Next;
	pCur->Next = pNewNode;
}
/*头删*/
void SListPopFront(SListNode* pHead)
{
	SListNode* pCur = &(pHead->Next);
	pHead->Next=pHead->Next->Next;
	pCur=NULL;
}
/*查找data*/
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
/*在任意位置插入*/
void SListInsert(SListNode* pHead, DataType data)
{
	DataType _data;
	SListNode* pNewNode = BuySListNode(data);
	Print(pHead->Next);
	printf("请输入在哪个数字后插入（第一个前插入按0）：");
	scanf("%d", &_data);
	if (0 == _data)
	{
		SListPushFront(pHead, data);
		return ;
	}
	pNewNode->Next = SListFind(pHead, _data)->Next;
	SListFind(pHead, _data)->Next = pNewNode;
}
/*删除任意节点*/
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
/*销毁表*/
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
/*表中节点个数*/
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
/*判空*/
int SListempty(SListNode* pHead)
{
	if (NULL == pHead->Next)
		return 0;
	else return 1;
}
/*返回第一个节点中的数*/
DataType Front(SListNode* pHead)
{
	if (NULL == pHead)
		return NULL;
	return pHead->Next->data;
}
/*返回最后一个节点中的数*/
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
/*删除第一个值为data的节点*/
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
/*删除所有data*/
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
/*冒泡排序*/
void SListBubbleSort(SListNode* pHead)
{
	int size = SListSize(pHead);
	SListNode* pCur = pHead->Next;
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size-1-i; ++j,pCur=pCur->Next)
		{
			if (pCur->data>pCur->Next->data)
			{
				DataType t;
				t = pCur->Next->data;
				pCur->Next->data = pCur->data;
				pCur->data = t;
			}
		}
	}
}

