//  https://www.interviewbit.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* head = NULL;
    priority_queue<int, vector<int>, greater<int> > pq;
    ListNode* temp;
    int n = A.size();
    
    if(n==0)
        return head;
        
    for(int i=0;i<A.size();i++) {
        temp = A[i];
        while(temp) {
            pq.push(temp->val);
            temp = temp->next;
        }
    }
    
    temp = NULL;
    while(!pq.empty()) {
        ListNode* node = new ListNode(pq.top());
        if(temp==NULL) {
            head = node;
            temp = head;
        }
        else {
            temp->next = node;
            temp = node;   
        }
        pq.pop();
    }
    
    
    return head;
}

