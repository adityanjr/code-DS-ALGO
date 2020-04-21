// https://www.interviewbit.com/problems/k-reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int findLength(ListNode* A) {
    int c = 0;
    while(A) {
        c++;
        A = A->next;
    }
    return c;
}
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(!A || !A->next || B==1)
        return A;
        
    ListNode* temp, *head, *tA, *ttA;
    
    int length = findLength(A);
    int n = length/B;
    
    for(auto i=1;i<=n;i++) {
        int k = 1;
        temp = A;
        tA = A;
        ListNode *curr = temp, *nxt = temp->next;
        while(k<B && temp) {
            k++;
            temp = temp->next;
        }
        ListNode* prev = temp->next;
        if(temp->next)
            A = temp->next;
        
        ListNode* start = temp;
        while(curr!=start) {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        curr->next = prev;
    
        if(i!=1)
            ttA->next = curr;
        if(i==1)
            head = curr;
        ttA = tA;
    }
        
    return head;
}

