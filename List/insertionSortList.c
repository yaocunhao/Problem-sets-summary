//��������ĵڶ��ֽⷨ��ȡ��һ���ڵ㵱ͷ�����������Ľڵ���бȽ�


truct ListNode* insertionSortList(struct ListNode* head){
	if (head == NULL)
		return head;
	//�ڱ�λ
	struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
	newhead->next = head;
	struct ListNode* cur = head->next;
	newhead->next->next = NULL;

	while (cur)
	{
		struct ListNode* qsort = newhead->next;//ȡ��ͷָ��
		struct ListNode* qsort_prev = newhead;

		while (qsort)
		{
			if (cur->val <= qsort->val)//����ǰ��
			{
				//��������
				struct ListNode* next = cur->next;//�������Ľڵ�
				cur->next = qsort;
				qsort_prev->next = cur;
				cur = next;//����
				break;
			}
			//�ź����������к���
			qsort_prev = qsort;
			qsort = qsort->next;
		}
		if (qsort == NULL)//Ҫ����Ľڵ�����нڵ㶼��
		{
			qsort_prev->next = cur;
			struct ListNode* next = cur->next;//�������Ľڵ�
			cur->next = NULL;//���ڵ��е�ָ���ÿ�
			cur = next;
		}

	}
	struct ListNode* ret_head = newhead->next;
	free(newhead);
	return ret_head;
};