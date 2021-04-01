#ifndef _SLIST_H_
#define _SLIST_H_

#include <stdio.h>
#include <windows.h>
#include <assert.h>
typedef int SListDataType;

typedef struct SlistNode
{
	SListDataType data;
	struct SlistNode *next;
}SListNode;

SListNode *BuySListNode(SListDataType x);//����ڵ�
void SListPrint(SListNode *phead);//��ӡ
void SListPushBack(SListNode **pphead,SListDataType x);//β��
void SListPopBack(SListNode **pphead);//βɾ
void SListPushFront(SListNode **pphead, SListDataType x);//ͷ��
void SListPopFront(SListNode **pphead);//ͷɾ
SListNode* SListFind(SListNode *pphead, SListDataType x);//����
void SListInsertAfter(SListNode *pos,SListDataType x);//pos֮�����
void SListEraseAfter(SListNode* pos);//pos֮��ɾ��
void SListDestory(SListNode **pList);//����

#endif 