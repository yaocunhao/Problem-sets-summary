//链表排序的第二种解法，取出一个节点当头，再用其他的节点进行比较


truct ListNode* insertionSortList(struct ListNode* head){
	if (head == NULL)
		return head;
	//哨兵位
	struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
	newhead->next = head;
	struct ListNode* cur = head->next;
	newhead->next->next = NULL;

	while (cur)
	{
		struct ListNode* qsort = newhead->next;//取得头指针
		struct ListNode* qsort_prev = newhead;

		while (qsort)
		{
			if (cur->val <= qsort->val)//插在前面
			{
				//进行链接
				struct ListNode* next = cur->next;//保存后面的节点
				cur->next = qsort;
				qsort_prev->next = cur;
				cur = next;//更新
				break;
			}
			//排好序的链表进行后移
			qsort_prev = qsort;
			qsort = qsort->next;
		}
		if (qsort == NULL)//要插入的节点比所有节点都大
		{
			qsort_prev->next = cur;
			struct ListNode* next = cur->next;//保存后面的节点
			cur->next = NULL;//将节点中的指针置空
			cur = next;
		}

	}
	struct ListNode* ret_head = newhead->next;
	free(newhead);
	return ret_head;
};