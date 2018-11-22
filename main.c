#include "link.h"

int main()
{
	DataType data;
	SListNode* pHead = NULL;
	//SListNode* pHead = &pHead_1;
	SListInit(&pHead); 
	//SListPushFront(&pHead,9);
	//SListPopFront(&pHead);
	//SListInsert(&pHead, 3);
	//Print(pHead);
	//SListErase(&pHead, 3);
	//printf("%d\n",SListSize(&pHead));
	//SListRemove(&pHead, 3);
	//RemoveAll(&pHead,3);
	//printf("%d\n", Back(&pHead));
	//SListDestroy(&pHead);
	//SListFind(&pHead,6)->data);
	SListBubbleSort(&pHead);
	Print(pHead);


	system("pause");
	return 0;
}