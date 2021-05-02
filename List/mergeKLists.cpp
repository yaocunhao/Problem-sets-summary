/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

template<class T>
 class Less
 {
public:
    bool operator ()(ListNode* ls1,ListNode *ls2)
    {
        return ls1->val>ls2->val;
    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head=NULL;
        ListNode *cur=head;

        priority_queue<ListNode*,vector<ListNode*>,Less<ListNode*>> q;

        for(int i=0;i<lists.size();i++)//将所有节点放入优先级队列之中
        {
            ListNode *newhead=lists[i];
            while(newhead)
            {
                ListNode *next=newhead->next;
                newhead->next=NULL;
                q.push(newhead);
                newhead=next;
            }
        }

        while(!q.empty())
        {
            if(cur==NULL)
            {
                cur=q.top();
                head=cur;
            }
            else
            {
                cur->next=q.top();
                cur=cur->next;
            }

            q.pop();
        }

        return head;


    }
};