//  https://www.interviewbit.com/problems/insertion-sort-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    vector<int> data;
    
    ListNode* temp = A;
    
    while(temp!=NULL) {
        data.push_back(temp->val);
        temp = temp->next;
    }
    
    int n = data.size();
    for(int j=1;j<n;j++) {
        int key = data[j];
        int i = j-1;
        while(i>=0 && data[i]>key) {
            data[i+1] = data[i];
            i--;
        }
        data[i+1] = key;
    }
    
    
    
    ListNode* head = new ListNode(data[0]);
    temp = head;
    for(int i=1;i<n;i++) {
        ListNode* node = new ListNode(data[i]);
        temp->next = node;
        temp = node;
    }
    
    return head;
}

