剑指 Offer 36. 二叉搜索树与双向链表

class Solution {
public:
    Node *head=NULL;


    void Insert(Node *root)
    {
        if(root==NULL)
        return ;

        Insert(root->left);
        Node *next=root->right;//保存一份，当前节点的右子树

        if(head==NULL)
        {
            head=root;//得到头结点
            head->left=head;
            head->right=head;
        }
    else
    {
        Node *tail=head->left;//最后一个节点
  
        tail->right=root;
        root->left=tail;
        root->right=head;
        head->left=root;
    }

        Insert(next);

    }
    Node* treeToDoublyList(Node* root) {
        //先拿到头节点，然后进行尾插
        Insert(root);
          return head;
        
    }
};