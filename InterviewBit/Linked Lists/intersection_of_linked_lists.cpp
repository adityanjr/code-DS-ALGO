//  https://www.interviewbit.com/problems/intersection-of-linked-lists/

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
    while(A!=NULL) {
        c++;
        A = A->next;
    }
    return c;
}
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m = findLength(A);
    int n = findLength(B);
    
    if(m==0)
        return A;
    if(n==0)
        return B;
    
    if(n>m) {
        ListNode* temp = A;
        A = B;
        B = temp;
        m = findLength(A);
        n = findLength(B);
    }
    
    int d = m-n;
    for(int i=0;i<d;i++)
        A = A->next;
    
    while(A!=NULL && B!=NULL) {
        if(A == B)
            return A;
        A = A->next;
        B = B->next;
    }
    
    return NULL;
}

