/*
structure of the node is as
struct node
{
	int data;
	struct node* next;
};
*/
struct temp{
    int a, b;    
};

struct node* findIntersection(struct node* head1, struct node* head2)
{
    // code here
    map<int, temp> m;
    
    while(head1){
        map<int, temp> :: iterator it = m.find(head1->data);
        if(it == m.end()){
            temp t;
            t.a = 1;
            t.b = 0;
            m[head1->data] = t;
        }
        else{
            m[head1->data].a++;
        }
        head1 = head1->next;
    }
    
    while(head2){
        map<int, temp> :: iterator it = m.find(head2->data);
        if(it == m.end()){
            temp t;
            t.a = 0;
            t.b = 1;
            m[head2->data] = t;
        }
        else{
            m[head2->data].b++;
        }
        head2 = head2->next;
    }
    
    node* head = NULL, *temp1 = NULL;
    
    map<int, temp> :: iterator it = m.begin();
    
    while(it != m.end()){
        int mini = min((it->second).a, (it->second).b);
        while(mini){
            node* t = new node();
            t->data = it->first;
            t->next = NULL;
            
            if(!head){
                head = t;
                temp1 = head;
            }
            else{
                temp1->next = t;
                temp1 = t;
            }
            mini--;
        }
        
        it++;
    }
    
    return head;
}
