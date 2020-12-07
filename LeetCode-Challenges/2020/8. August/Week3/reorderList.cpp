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
    void reverseList(ListNode** head) {
        ListNode* next;
        ListNode* prev = NULL;
        ListNode* curr = *head;
        
        while (curr) { 
            next = curr->next; 
            curr->next = prev; 
            prev = curr; 
            curr = next; 
        } 

        *head = prev;
    }
public:
    void reorderList(ListNode* head) {
        if(head == NULL) return;
        
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* head1 = head;
        ListNode* head2 = slow->next;
        
        slow->next = NULL;
        
        reverseList(&head2);
        
        head = new ListNode(0);
        
        ListNode* curr = head;
        
        while(head1 || head2) {
            
            if(head1) {
                curr->next = head1;
                curr = curr->next;
                head1 = head1->next;
            }
            
            if(head2) {
                curr->next = head2;
                curr = curr->next;
                head2 = head2->next;
            }
            
        }
        
        head = head->next;
    }
};