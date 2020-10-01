#include<iostream>
#include<cmath>
using namespace std ;
class Node {
    public:
    int data;
    struct Node* next; // Pointer to next node in DLL
    struct Node* prev; // Pointer to previous node in DLL
    Node(int data)
    {
        this->data = data ;
        next = NULL ;
        prev = NULL ;
    }
};
void print(Node* head)
{
    Node* temp = head ;
    cout<<temp->data<<" ";
    temp = temp->next ;
    while(temp != head)
    {
        cout<<temp->data<<" ";
        temp = temp->next ;
    }
}
Node* Swap_Nodes(Node* head , int i , int j)
{
    if(head == NULL)
        return NULL ;
    Node* a = head ;
    Node* b = head ;
    for(int k=0;k<i;k++)
    {
        a = a->next ;
    }
    for(int k=0;k<j;k++)
    {
        b = b->next ;
    }
    if(i==j)
        return head ;


    if(abs(i-j) == 1)
    {
        Node* z = a->prev ;
        a->prev->next = b ;
        a->next = b->next ;
        a->prev = b ;
        b->next = a ;
        a->next->prev = a ;
        b->prev = z ;
    }

    else{



    Node* x = a->prev ;
    Node* y = a->next ;
    a->prev->next = b ;
    a->next->prev = b ;
    a->prev = b->prev ;
    a->next = b->next ;
    b->prev->next = a ;
    b->next->prev = a ;
    b->prev = x ;
    b->next = y ;
    }
    if(i==0)
       head = b ;
    if(j==0)
       head = a ;
    return head ;
}
int main()
{
    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);
    a->next = b ;
    b->next = c ;
    c->next = d ;
    d->next = e ;
    e->next = f ;
    f->next = a ;
    a->prev = f ;
    b->prev = a ;
    c->prev = b ;
    d->prev = c ;
    e->prev = d ;
    f->prev = e ;
    cout<<"Original List : ";
    print(a) ;
    cout<<endl ;
    int x,y;
    cout<<"Enter positions at which you want the Nodes to be Swapped (positon < 6): ";
    cin>>x>>y;
    a = Swap_Nodes(a,x,y);
    cout<<"List After Swapping at Position "<<x<<" and "<<y<<" is : ";
    print(a);
    cout<<endl ;
    return 0 ;
}
