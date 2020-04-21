//  https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(A==NULL || A->next==NULL)
        return A;
    ListNode* temp = A;
    ListNode* dup_node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* next_next, *prev_node = NULL;
    next_next = (ListNode*)malloc(sizeof(ListNode));
    while(temp->next != NULL)
    {
        if(temp->val == temp->next->val)
        {
            while(temp->val == temp->next->val)
            {
                next_next = temp->next->next;
                free(temp->next);
                temp->next = next_next;
                if(temp->next == NULL)
                    break;
            }
            if(temp->next==NULL && prev_node==NULL)
            {
                A = NULL;
                break;
            }
            else if(temp->next == NULL && prev_node!=NULL)
            {
                //free(temp);
                prev_node->next = temp->next;
            }
            else
            {
                dup_node = temp;
                temp = temp->next;
                free(dup_node);
                if(prev_node != NULL)
                    prev_node->next = temp;
                else
                    A = temp;
            }
        }
        else
        {
            prev_node = temp;
            temp = temp->next;
        }
    }
    return A;
}



########## OR ###################


ListNode* Solution::deleteDuplicates(ListNode* A) {
    if(!A || !A->next)
        return A;
    ListNode* n1, *n2, *temp, *h=NULL;
    int cval;
    n1 = A;
    n2 = A->next;
    
    while(n2) {
        if(n1->val==n2->val) {
            cval = n1->val;
            //cout << cval << endl;
            while(n1->val==cval) {
                temp = n1;
                n1 = n1->next;
                free(temp);
                if(n1==NULL)
                    break;
            }
            if(n1==NULL)  {
                if(h) {
                    h->next = n1;
                    return A;
                }
                else
                    return h;
            }
            else{
                if(h)
                    h->next = n1;
                else
                    A = n1;
                if(n1->next)
                    n2 = n1->next;
                else
                    return A;
            }
        }
        else {
            h = n1;
            //cout << h->val << endl;
            n1 = n2;
            n2 = n2->next;
        }    
    }
    return A;    
}
