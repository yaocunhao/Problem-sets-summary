//给定一个单向链表中的某个节点，请删除这个节点，但要求只能访问该节点。
//若该节点为尾节点，返回false，否则返回true
//
//思路：通过遍历链表，来寻找可以访问的点，如果可以访问就将其删除，通过标记符号
//标记该节点是不是尾节点

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class Remove {
public:
	bool removeNode(ListNode* pNode) {
		if (pNode == NULL)
			return false;

		struct ListNode *prev = NULL;
		struct ListNode *cur = pNode;

		int lable = 1;//进行标记
		while (cur)
		{
			if (cur->val)//可以访问
			{
				if (prev == NULL)
					prev = cur->next;
				else
					prev->next = cur;

				if (cur->next == NULL)//尾节点
					lable = 0;

				free(cur);
				break;
			}
			prev = cur;
			cur = cur->next;//进行移动
		}
		if (lable == 0)
			return false;
		return true;

	}
};