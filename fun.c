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
void SListInit(SListNode* pHead)
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