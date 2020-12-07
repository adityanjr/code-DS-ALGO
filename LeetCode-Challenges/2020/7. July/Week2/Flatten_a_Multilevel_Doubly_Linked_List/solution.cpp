/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL) return head;
        
        Node* current = head;
        
        while(current != NULL) {
            if(current->child == NULL) {
                current = current->next;
                continue;
            }
            
            Node* temp = current->child;
            
            while(temp->next != NULL) temp = temp->next;
            
            temp->next = current->next;
            if(current->next != NULL) current->next->prev = temp;
            current->next = current->child;
            current->child->prev = current;
            current->child = NULL;
        }
        
        return head;
    }
};