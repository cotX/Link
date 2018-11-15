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
void SListInit(SListNode* pHead)
{
	SListPushBack(pHead, 1);
	SListPushBack(pHead, 2);
	SListPushBack(pHead, 3);
	SListPushBack(pHead, 4);
	SListPushBack(pHead, 5);
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