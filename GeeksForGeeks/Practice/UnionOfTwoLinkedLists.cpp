/*
structure of the node is as
struct node
{
	int data;
	struct node* next;
};
*/
struct node* makeUnion(struct node* head1, struct node* head2)
{
    // code here
    map<int, bool> m;
    
    while(head1){
        m[head1->data] = true;
        
        head1 = head1->next;
    }
    
    while(head2){
        m[head2->data] = true;
        
        head2 = head2->next;
    }
    
    map<int, bool> :: iterator it = m.begin();
    
    node* head = NULL, *temp = NULL;
    
    while(it != m.end()){
        node* t = new node();
        t->data = it->first;
        t->next = NULL;
        
        if(!head){
            head = t;
            temp = head;
        }
        else{
            temp->next = t;
            temp = t;
        }
        
        it++;
    }
    
    return head;
}
