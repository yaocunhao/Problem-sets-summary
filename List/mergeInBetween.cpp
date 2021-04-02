1669.合并两个链表

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *newhead=list1;
        int count=0;//计数器

        ListNode* newhead2=list2;
        while(newhead2->next)
        {
            newhead2=newhead2->next;//找到最后一个节点
        }

        //保存节点
        ListNode *prev=NULL;
        ListNode *next=NULL;

        while(count<=b)
        {
            if(count+1==a)
            {
                prev=newhead;//保存a位置节点的前一个位置
            }
            if(count==b)
            {
                next=newhead->next;//你保存b位置节点的后一个位置
                break;
            }
            newhead=newhead->next;
            count++;
        }

        prev->next=list2;
        newhead2->next=next;

        return list1; 
    }
};

