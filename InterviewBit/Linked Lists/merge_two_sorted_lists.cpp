//  https://www.interviewbit.com/problems/merge-two-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    
    if(!A)  
        return B;
    if(!B)
        return A;
        
    ListNode* head, *temp;
    
    head = temp = NULL;
    
    while(A && B) {
        if(A->val < B->val) {
            if(temp)
                temp->next = A;
            temp = A;
            A = A->next;
            if(!head)
                head = temp;
        } else {
            if(temp)
                temp->next = B;
            temp = B;
            B = B->next;
            if(!head)
                head = temp;
        }
    }
    
    if(A)
        temp->next = A;
    else
        temp->next = B;
    return head;
}

