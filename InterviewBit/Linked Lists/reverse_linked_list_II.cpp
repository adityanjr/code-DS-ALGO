//  https://www.interviewbit.com/problems/reverse-link-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    
    if(!A || !A->next)
        return A;
    
    ListNode* curr, *prev, *j1, *j2, *temp, *head;
    head = A;
    int k = 1;
    curr = A;
    prev = NULL;
    
    while(k<B) {
        prev = curr;
        curr = curr->next;
        k++;
    }
    j1 = curr;
    
    while(k<C) {
        curr = curr->next;
        k++;
    }
    j2 = curr;
    
    if(prev)
        prev->next = j2;
    prev = j2->next;
    
    curr = j1;
    temp = j1->next;
    
    while(prev!=j2) {
        curr->next = prev;
        prev = curr;
        curr = temp;
        if(temp!=j2)
            temp = temp->next;
    }
    if(B==1)
        head = j2;
    return head;
}

