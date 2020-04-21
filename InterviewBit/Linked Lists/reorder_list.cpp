//  https://www.interviewbit.com/problems/reorder-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    
    ListNode* temp = A;
    if(temp==NULL)
        return temp;
        
    vector<int> values;
    while(temp!=NULL) {
        values.push_back(temp->val);
        temp = temp->next;
    }
    
    vector<int> newList;
    int n = values.size();
    
    for(int i=0;i<n/2;i++) {
        newList.push_back(values[i]);
        newList.push_back(values[n-1-i]);
    }
    if(n%2!=0)
        newList.push_back(values[n/2]);
    

    
    ListNode* head = new ListNode(newList[0]);
    temp = head;
    
    for(int i=1;i<n;i++) {
        ListNode* node = new ListNode(newList[i]);
        temp->next = node;
        temp = node;
    }
    
    return head;
}

