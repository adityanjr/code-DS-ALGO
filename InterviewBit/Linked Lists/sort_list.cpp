//  https://www.interviewbit.com/problems/sort-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* mergeLists(ListNode* A, ListNode* B) {
    if(!B)
        return A;
    if(!A)
        return B;
    
    ListNode* head, *temp;
    if(A->val < B->val) {
        head = A;
        A = A->next;
    }
    else {
        head = B;
        B = B->next;
    }
    temp = head;
    
    while(A && B) {
        if(A->val < B->val) {
            temp->next = A;
            temp = A;
            A = A->next;
        }
        else {
            temp->next = B;
            temp = B;
            B = B->next;
        }
    }
    if(!A) {
        temp->next = B;
    }
    
    if(!B) {
        temp->next = A;
    }
    return head;
} 

ListNode* Solution::sortList(ListNode* A) {
    
    if(!A || !A->next)
        return A;
    
    ListNode* p1 = A;
    ListNode* p2 = A->next;
    
    while(p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    
    p2 = p1->next;
    p1->next = NULL;
    
    return mergeLists(sortList(A), sortList(p2));
    
}

