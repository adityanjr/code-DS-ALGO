//  https://www.interviewbit.com/problems/partition-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    
    if(!A || !A->next)
        return A;
        
    vector<int> values;
    
    ListNode* temp = A;
    while(temp) {
        values.push_back(temp->val);
        temp = temp->next;
    }
    
    vector<int> s_values;
    
    for(int i=0;i<values.size();i++) {
        if(values[i]<B) {
            s_values.emplace_back(values[i]);
            values[i] = INT_MAX;
        }
    }
    
    for(int i=0;i<values.size();i++)
        if(values[i]!=INT_MAX)
            s_values.emplace_back(values[i]);
            
    reverse(s_values.begin(), s_values.end());
    
    ListNode* head = new ListNode(s_values[0]);
    
    for(int i=1;i<s_values.size();i++) {
        ListNode* node = new ListNode(s_values[i]);
        node->next = head;
        head = node;
    }
            
    
    return head;
}
