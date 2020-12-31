#include"list.h"

void test1()
{
	ListNode *pphead = NULL;
	pphead=ListInit(pphead);
	//ListInit(&pphead);

	ListPushBack(pphead, 1);
	ListPushBack(pphead, 2);
	ListPushBack(pphead, 3);
	ListPushBack(pphead, 4);
	ListPrint(pphead);


	ListPopBack(pphead);
	ListPopFront(pphead);
	ListPrint(pphead);


	ListNode *node = ListFind(pphead,2);
	ListErase(node);
	ListPrint(pphead);

	//ListClear(pphead);
	ListDestory(&pphead);
	ListPrint(pphead);

}



int main()
{
	test1();
	system("pause");
	return 0;
}