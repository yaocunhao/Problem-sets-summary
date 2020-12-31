#include "list.h"

ListNode* ListInit(ListNode *pphead)//初始化
{
	/*assert(pphead);
	
	*pphead = (ListNode *)malloc(sizeof(ListNode));
	assert(*pphead);
	
	(*pphead)->prev = (*pphead)->next = *pphead;
	(*pphead)->data = 0;*/


	pphead = (ListNode *)malloc(sizeof(ListNode));
	assert(pphead);

	pphead->prev =pphead->next = pphead;
	pphead->data = 0;
	return pphead;
}

 ListNode* BuyListNode(LTDataType data)//创建节点
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	assert(node);

	node->next = node->prev = NULL;
	node->data = data;
	return node;
}

 void ListInsert(ListNode *pos,LTDataType data)//早Pos前面插入
 {
	 assert(pos);
	 ListNode *node = BuyListNode(data);
	 ListNode *prev = pos->prev;//pos前面的节点
	//和pos前面节点链接
	 prev->next = node;
	 node->prev = prev;
	 //和pos链接
	 node->next = pos;
	 pos->prev = node;
 }

 ListNode* ListFind(ListNode *pphead, LTDataType data)//寻找节点
 {
	 assert(pphead);

	 ListNode *cur = pphead->next;
	 
	 while (cur!=pphead)
	 {
		 if (cur->data == data)
			 return cur;
		 cur = cur->next;
	 }
	 return NULL;
 }

 void ListErase(ListNode *pos)//删除
 {
	 assert(pos);
	 //pos前后节点
	 ListNode *prev = pos->prev;
	 ListNode *next = pos->next;
	 //前后节点链接
	 prev->next = next;
	 next->prev = prev;

	 free(pos);
	 pos = NULL;//没有多大意义，因为出了作用域就访问不到了
 }

 void ListPushBack(ListNode *pphead,LTDataType data)//尾插
 {
	 assert(pphead);
	 //ListInsert(pphead, data);

	 ListNode *node = BuyListNode(data);
	 ListNode *tail = pphead->prev;//最后一个节点
	 //最后两个节点链接
	 tail->next = node;
	 node->prev = tail;
	 //和头链接
	 pphead->prev = node;
	 node->next = pphead;
	 
 }

 void ListPushFront(ListNode *pphead, LTDataType data)//头插
 {
	 assert(pphead);
	 //ListInsert(pphead->next, data);

	 ListNode *node = BuyListNode(data);
	 ListNode *next = pphead->next;//未插入前的第一个节点
	 //插入的接点和后面的进行链接
	 node->next = next;
	 next->prev = node;
	 //头链接
	 pphead->next = node;
	 node->prev = pphead;
 }

 void ListPopBack(ListNode *pphead)//尾删
 {
	 assert(pphead);
	 assert(pphead->next != pphead);//头不能删
	 //ListErase(pphead->prev);

	 ListNode *tail = pphead->prev;//尾
	 ListNode *tailPrev = tail->prev;

	 pphead->prev = tailPrev;
	 tailPrev->next = pphead;

	 free(tail);
 }

 void ListPopFront(ListNode *pphead)//头删
 {
	 assert(pphead);
	 assert(pphead->next != pphead);
	 //ListErase(pphead->next);

	 ListNode *head= pphead->next;
	 ListNode *next = head->next;

	 pphead->next = next;
	 next->prev = pphead;

	 free(head);

 }

 void ListPrint(ListNode *pphead)//打印
 {
	 assert(pphead);
	 ListNode *cur = pphead->next;
	 while (cur!=pphead)
	 {
		 printf("%d ", cur->data);
		 cur = cur->next;
	 }
	 printf("\n");
 
 }

 void ListClear(ListNode *pphead)
 {
	 assert(pphead);
	 ListNode *cur = pphead->next;
	 while (cur!=pphead)
	 {
		 ListNode *next = cur->next;
		 free(cur);
		 cur = next;
	 }
	 pphead->prev = pphead->next = pphead;;
 }

 void ListDestory(ListNode **pphead)
 {
	 assert(pphead);
	 ListClear(*pphead);
	 free(*pphead);
	 *pphead = NULL;
 }