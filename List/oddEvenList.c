//题目
给定一个单链表，请设定一个函数，讲链表的奇数位节点和偶数位节点分别放在一起，重排后输出。
注意是节点的编号而非节点的数值。




设置两个指针，先走奇指针，再走偶指针，将链表串联起来；
​链表的边界问题挺重要的，思路不难，主要是链表的边界问题；
​
​ ListNode* oddEvenList(ListNode* head) {
	if (head == NULL || head->next == NULL || head->next->next == NULL)//0,1个节点直接返回

	ListNode* odd = head;
	ListNode* even = head->next;
	ListNode* rat_even = even;
	ListNode* prev = odd;
	while (odd&&even)
	{
		prev = odd;
		odd->next = odd->next->next;
		odd = odd->next;
		if (even->next)
		{
			even->next = even->next->next;
			even = even->next;
		}
	}

	if (odd)
		odd->next = rat_even;
	else
		prev->next = rat_even;
	return head;
}