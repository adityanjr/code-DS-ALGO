//  https://www.interviewbit.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A) {
    ListNode* prevNode = NULL;
    ListNode* nextNode, *currNode = A;
    
    if(A==NULL || A->next==NULL)
        return A;
    
    while(currNode!=NULL) {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }    
    A = prevNode;
    return A;
}

