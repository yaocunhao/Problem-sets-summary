#include "SList.h"


int main()
{
	SListNode *pList = NULL;
	SListPushBack(&pList, 200);//β��
	SListPushBack(&pList, 300);
	SListPushBack(&pList, 400);
	SListPrint(pList);//��ӡ
    SListPopBack(&pList);
	SListPushFront(&pList, 100);
	SListPrint(pList);//��ӡ
	SListPopFront(&pList);
	SListPrint(pList);//��ӡ
	//printf("%d\n",SListFind(pList,200)->data);
	SListInsertAfter(SListFind(pList, 200),250);
	SListPrint(pList);//��ӡ
	SListEraseAfter(SListFind(pList, 250));
	SListPrint(pList);//��ӡ
	SListDestory(&pList);//����
	SListPrint(pList);//��ӡ
	system("pause");
	return 0;
}