//����һ�����������е�ĳ���ڵ㣬��ɾ������ڵ㣬��Ҫ��ֻ�ܷ��ʸýڵ㡣
//���ýڵ�Ϊβ�ڵ㣬����false�����򷵻�true
//
//˼·��ͨ������������Ѱ�ҿ��Է��ʵĵ㣬������Է��ʾͽ���ɾ����ͨ����Ƿ���
//��Ǹýڵ��ǲ���β�ڵ�

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

		int lable = 1;//���б��
		while (cur)
		{
			if (cur->val)//���Է���
			{
				if (prev == NULL)
					prev = cur->next;
				else
					prev->next = cur;

				if (cur->next == NULL)//β�ڵ�
					lable = 0;

				free(cur);
				break;
			}
			prev = cur;
			cur = cur->next;//�����ƶ�
		}
		if (lable == 0)
			return false;
		return true;

	}
};