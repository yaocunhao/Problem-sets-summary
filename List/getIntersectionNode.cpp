输入两个链表，找出它们的第一个公共节点。


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode *listA=headA;
        ListNode *listB=headB;

        while(listA!=listB)
        { 
            if(listA!=NULL)
            listA=listA->next;
            else
            listA=headB;

            if(listB!=NULL)
            listB=listB->next;
            else
            listB=headA;

        }
        return listA;
     
    }
};