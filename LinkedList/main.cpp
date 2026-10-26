#include "LinkedList.h"

int main(void)
{
	LinkList L;
	CreateList(L, 12);
	cout << ListLength(L) << endl;
	cout << ListEmpty(L) << endl;
	ListInsert(L, 1, 2);
	ListTraverse(L);
	int e;
	ListDelete(L, 2, e);
	ListTraverse(L);
	return 0;
}