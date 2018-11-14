#ifndef __TEST__
#define __TEST__

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning(disable:4996)

typedef int DataType;

typedef struct SListNode
{
	struct SListNode *next;
	DataType data;
}SListNode;




#endif

