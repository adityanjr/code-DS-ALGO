//  https://www.interviewbit.com/problems/palindrome-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    vector<int> data;
    
    ListNode* temp = A;
    
    while(temp!=NULL) {
        data.push_back(temp->val);
        temp = temp->next;
    }
    int n = data.size();
    
    for(int i=0;i<n/2;i++) {
        if(data[i]!=data[n-1-i])
            return 0;
    }
    return 1;
    
}

