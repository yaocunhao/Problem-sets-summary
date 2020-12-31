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


ListNode* ListInit(ListNode *pphead);//初始化
ListNode* BuyListNode(LTDataType data);//创建节点
void ListInsert(ListNode *pos, LTDataType data);//在pos前面插入
ListNode* ListFind(ListNode *pphead, LTDataType data);//寻找节点
void ListErase(ListNode *pos);//删除
void ListPushBack(ListNode *pphead, LTDataType data);//尾插
void ListPushFront(ListNode *pphead, LTDataType data);//头插
void ListPopBack(ListNode *pphead);//尾删
void ListPopFront(ListNode *pphead);//头删
void ListPrint(ListNode *pphead);//打印
void ListClear(ListNode *pphead);//清空
void ListDestory(ListNode **pphead);//销毁






#endif