//  https://www.interviewbit.com/problems/rotate-list/

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
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(A==NULL || A->next==NULL)
        return A;
    int n = findLength(A);
    B = B%n;
    if(B==0)
        return A;
    int m = n-B;
    
    ListNode* temp = A;
    // Make the list circular
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = A;
    
    for(int i=0;i<m;i++) {
        temp = A;
        A = A->next;
    }
    temp->next = NULL;
    return A;
}

