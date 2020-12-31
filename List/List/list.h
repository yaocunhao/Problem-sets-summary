#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <windows.h>
#include <assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode *prev;
	struct ListNode *next;
	LTDataType data;
}ListNode;


ListNode* ListInit(ListNode *pphead);//��ʼ��
ListNode* BuyListNode(LTDataType data);//�����ڵ�
void ListInsert(ListNode *pos, LTDataType data);//��posǰ�����
ListNode* ListFind(ListNode *pphead, LTDataType data);//Ѱ�ҽڵ�
void ListErase(ListNode *pos);//ɾ��
void ListPushBack(ListNode *pphead, LTDataType data);//β��
void ListPushFront(ListNode *pphead, LTDataType data);//ͷ��
void ListPopBack(ListNode *pphead);//βɾ
void ListPopFront(ListNode *pphead);//ͷɾ
void ListPrint(ListNode *pphead);//��ӡ
void ListClear(ListNode *pphead);//���
void ListDestory(ListNode **pphead);//����






#endif