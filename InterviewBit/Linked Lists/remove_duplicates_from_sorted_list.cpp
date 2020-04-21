//  https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL || A->next==NULL)
        return A;
    
    ListNode* prev = A;
    ListNode* curr = A->next;
    
    while(curr!=NULL) {
        while(curr->val==prev->val) {
            curr = curr->next;
            if(curr==NULL) {
                prev->next = curr;
                return A;
            }
        }
        prev->next = curr;
        prev = curr;
        curr = curr->next;
    }
    return A;
}

