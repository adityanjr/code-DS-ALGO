//  https://www.interviewbit.com/problems/add-two-numbers-as-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int findLen(ListNode* A) {
    int c = 0;
    while(A!=NULL) {
        c++;
        A = A->next;
    }
    return c;
}
void swap(int& x, int& y) {
    x ^= y;
    y ^= x;
    x ^= y;
}
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    
    int n = findLen(A);
    int m = findLen(B);
    
    if(n==0)
        return B;
    if(m==0)
        return A;
    ListNode* temp;
    if(m>n) {
        temp = A;
        A = B;
        B = temp;
        swap(n, m);
    }
    int carry = 0;
    int d = A->val+B->val;
    ListNode* head = new ListNode(d%10);
    carry = d/10;
    A = A->next;
    B = B->next;
    temp = head;
    
    while(B!=NULL) {
        d = A->val+B->val+carry;
        carry = d/10;
        ListNode* node = new ListNode(d%10);
        temp->next = node;
        temp = node;
        A = A->next;
        B = B->next;
    }
    
    while(A!=NULL) {
        d = A->val+carry;
        carry = d/10;
        ListNode* node = new ListNode(d%10);
        temp->next = node;
        temp = node;
        A = A->next;
    }
    
    while(carry>0) {
        ListNode* node = new ListNode(carry%10);
        temp->next = node;
        temp = node;
        carry /= 10;
    }
    
    return head;
}


