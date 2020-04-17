//  https://www.interviewbit.com/problems/convert-sorted-list-to-binary-search-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* balancedBST(ListNode* head, ListNode* tail) {
    if(head==tail)
        return NULL;
    
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast!=tail && fast->next!=tail) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    TreeNode* root = new TreeNode(slow->val);
    root->left = balancedBST(head, slow);
    root->right = balancedBST(slow->next, tail);
    
    return root;
}
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    ListNode* tail, *temp = A;
    while(temp->next) {
        temp = temp->next;
    }
    tail = temp->next;
    
    return balancedBST(A, tail);
}

