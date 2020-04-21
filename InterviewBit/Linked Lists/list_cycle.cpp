//  https://www.interviewbit.com/problems/list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL)
        return A;
    ListNode* slow = A;
    ListNode* fast = A;
    
    while(slow && fast && fast->next) {
        //cout << slow->val << " " << fast->val << endl;
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow==fast)
            break;
    }
    if(slow==NULL || fast==NULL || fast->next==NULL)
        return NULL;
    ListNode* temp = A;
    while(temp!=slow) {
        temp = temp->next;
        slow = slow->next;
    }
    return slow;
}

