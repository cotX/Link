#include "link.h"


int main()
{
	DataType data;
	SListNode* pHead = NULL;
	//SListNode* pHead = &pHead_1;
	SListInit(&pHead); 
	SListpopBack(&pHead);
	SListpopBack(&pHead);
	SListpopBack(&pHead);
	SListpopBack(&pHead);
	SListpopBack(&pHead);
	Print(pHead);

	system("pause");
	return 0;
}