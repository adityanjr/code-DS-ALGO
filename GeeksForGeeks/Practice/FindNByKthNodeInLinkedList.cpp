/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of the node is
struct node
{
    int data;
    struct node *next;
};*/
int fractional_node(struct node *head, int k)
{
// your code here
    node* curr = head;
    
    int len = 0;
    
    while(curr){
        len++;
        curr = curr->next;
    }
    
    int num = len/k;
    num--;
    if(len%k){
        num++;
    }
    
    curr = head;
    
    while(num){
        curr = curr->next;
        num--;
    }
    
    return curr->data;
}
