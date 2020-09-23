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
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *temp1=new ListNode;
        ListNode *temp2 =new ListNode;
        ListNode *init=new ListNode;
        temp1=head;
        temp2=head;
        if(temp1==NULL || temp1->next==NULL)
        {
            return head;
        }
        temp2=temp2->next;
        init=temp2;
        if(temp2->next==NULL)
        {
            return head;
        }
        //cout<<"here ";
        temp1->next=temp2->next;
        temp1=temp1->next;
        while(temp1!=NULL && temp2!=NULL && temp1->next!=NULL && temp2->next!=NULL)
        {
           // cout<<temp1->val<<" ";
            temp2->next=temp1->next;
            temp2=temp2->next;

            temp1->next=temp2->next;
            if(temp1->next!=NULL)
            {
            temp1=temp1->next;
            }
        }
        temp2->next=NULL;

        temp1->next=init;
        ListNode *temp=new ListNode;
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        return head;
    }
};
