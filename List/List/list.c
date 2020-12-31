#include "list.h"

ListNode* ListInit(ListNode *pphead)//��ʼ��
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

 ListNode* BuyListNode(LTDataType data)//�����ڵ�
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	assert(node);

	node->next = node->prev = NULL;
	node->data = data;
	return node;
}

 void ListInsert(ListNode *pos,LTDataType data)//��Posǰ�����
 {
	 assert(pos);
	 ListNode *node = BuyListNode(data);
	 ListNode *prev = pos->prev;//posǰ��Ľڵ�
	//��posǰ��ڵ�����
	 prev->next = node;
	 node->prev = prev;
	 //��pos����
	 node->next = pos;
	 pos->prev = node;
 }

 ListNode* ListFind(ListNode *pphead, LTDataType data)//Ѱ�ҽڵ�
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

 void ListErase(ListNode *pos)//ɾ��
 {
	 assert(pos);
	 //posǰ��ڵ�
	 ListNode *prev = pos->prev;
	 ListNode *next = pos->next;
	 //ǰ��ڵ�����
	 prev->next = next;
	 next->prev = prev;

	 free(pos);
	 pos = NULL;//û�ж�����壬��Ϊ����������ͷ��ʲ�����
 }

 void ListPushBack(ListNode *pphead,LTDataType data)//β��
 {
	 assert(pphead);
	 //ListInsert(pphead, data);

	 ListNode *node = BuyListNode(data);
	 ListNode *tail = pphead->prev;//���һ���ڵ�
	 //��������ڵ�����
	 tail->next = node;
	 node->prev = tail;
	 //��ͷ����
	 pphead->prev = node;
	 node->next = pphead;
	 
 }

 void ListPushFront(ListNode *pphead, LTDataType data)//ͷ��
 {
	 assert(pphead);
	 //ListInsert(pphead->next, data);

	 ListNode *node = BuyListNode(data);
	 ListNode *next = pphead->next;//δ����ǰ�ĵ�һ���ڵ�
	 //����Ľӵ�ͺ���Ľ�������
	 node->next = next;
	 next->prev = node;
	 //ͷ����
	 pphead->next = node;
	 node->prev = pphead;
 }

 void ListPopBack(ListNode *pphead)//βɾ
 {
	 assert(pphead);
	 assert(pphead->next != pphead);//ͷ����ɾ
	 //ListErase(pphead->prev);

	 ListNode *tail = pphead->prev;//β
	 ListNode *tailPrev = tail->prev;

	 pphead->prev = tailPrev;
	 tailPrev->next = pphead;

	 free(tail);
 }

 void ListPopFront(ListNode *pphead)//ͷɾ
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

 void ListPrint(ListNode *pphead)//��ӡ
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