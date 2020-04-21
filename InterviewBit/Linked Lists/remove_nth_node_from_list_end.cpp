//  https://www.interviewbit.com/problems/remove-nth-node-from-list-end/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int findLen(ListNode* A) {
    int c=0;
    while(A!=NULL) {
        c++;
        A= A->next;
    }
    return c;
}
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    if(B==0)
        return A;
    int m = findLen(A);
    int n = m-B;

    if(B>m || n==0)
        return A->next;
    
    ListNode* temp = A, *prev;
    for(int i=0;i<n;i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    return A;
}

