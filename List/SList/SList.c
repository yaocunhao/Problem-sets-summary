#include "SList.h"

SListNode *BuySListNode(SListDataType x)
{
	SListNode *NewNode = (SListNode*)malloc(sizeof(SListNode));//����һ���ڵ����
	if (NewNode == NULL)
	{
		printf("����ʧ��\n");
		exit(-1);
	}
	else
	{
		NewNode->data = x;
		NewNode->next=NULL;
	}
	return NewNode;//�����½ڵ�ĵ�ַ
}
void SListPrint(SListNode *phead)
{
	while (phead!= NULL)
	{
		printf("%d->", phead->data);
		phead = phead->next;
	}
	printf("NULL\n");
}
void SListPushBack(SListNode **pphead, SListDataType x)//β��
{
	SListNode *tail = *pphead;
	if (tail == NULL)
	{
		*pphead = BuySListNode(x);
	}
	else
	{
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = BuySListNode(x);

	}
}
void SListPopBack(SListNode **pphead)//βɾ
{
	SListNode *tail = *pphead;
	SListNode *pre = NULL;
	if (*pphead == NULL)
	{
		return;
	}
	if (tail->next == NULL)//ֻ��һ���ڵ�
	{
		free(tail);
		*pphead = NULL;
	}
	else
	{
		while (tail->next != NULL)
		{
			pre = tail;
			tail = tail->next;
		}
		free(tail);
		pre->next = NULL;
	}
}
void SListPushFront(SListNode **pphead,SListDataType x)//ͷ��
{
	SListNode *head = BuySListNode(x);
	head->next = *pphead;
	*pphead = head;
}

void SListPopFront(SListNode **pphead)//ͷɾ
{
	SListNode *head = *pphead;
	*pphead = (*pphead)->next;
	free(head);
}

SListNode *SListFind(SListNode *pphead, SListDataType x)//����
{
	while (pphead!=NULL)
	{
		if (pphead->data == x)
		{
			return pphead;
		}
		pphead = pphead->next;
	}
	return NULL;
}

void SListInsertAfter(SListNode *pos, SListDataType x)//����
{
	SListNode *temp=BuySListNode(x);
	temp->next = pos->next;
	pos->next = temp;
}
void SListEraseAfter(SListNode* pos)//pos֮������
{
	SListNode *temp = pos->next;
	pos->next = temp->next;
	free(temp);
}
void SListDestory(SListNode **pList)
{
	SListNode *plist = *pList;
	SListNode *prev = NULL;
	while (plist!= NULL)
	{
		prev = plist->next;
		free(plist);
		plist = prev;
	}
	*pList = NULL;
	printf("���ٳɹ�\n");
}