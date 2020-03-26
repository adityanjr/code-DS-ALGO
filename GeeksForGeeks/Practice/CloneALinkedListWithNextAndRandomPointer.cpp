/*  the node structure is as follows 
struct Node
{
int data;
Node* next;
Node* arb;
};*/

// Should return the head of the copied linked list the 
//output will be 1 if successfully copied
Node * copyList(Node *head)
{
    unordered_map<Node*, Node*> m;
    
    Node* curr = head;
    
    while(curr != NULL){
        Node* newnode = new Node();
        newnode->data = curr->data;
        newnode->next = NULL;
        newnode->arb = NULL;
        m[curr] = newnode;
        curr = curr->next;
    }
    
    unordered_map<Node*, Node*> :: iterator it = m.begin();
    
    while(it != m.end()){
        unordered_map<Node*, Node*> :: iterator i = m.find((it->first)->arb);
        if(i != m.end()){
            (it->second)->arb = i->second;
        }
        unordered_map<Node*, Node*> :: iterator ii = m.find((it->first)->next);
        if(ii != m.end()){
            (it->second)->next = ii->second;
        }
        it++;
    }
    
    Node* newhead = m[head];
    
    return newhead;
}
