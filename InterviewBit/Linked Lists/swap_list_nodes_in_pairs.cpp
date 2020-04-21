//  https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    
    if(!A || !A->next)
        return A;
    
    ListNode *curr, *prev, *pprev, *temp;
    pprev = NULL;
    prev = A;
    curr = A->next;
    temp = A->next->next;
    A = A->next;
    
    while(1) {
        prev->next = temp;
        curr->next = prev;
        
        if(pprev)
            pprev->next = curr;
        
        if(!temp || !temp->next)
            break;
        
        pprev = prev;
        prev = temp;
        curr = temp->next;
        temp = curr->next;
    }
    return A;
}

