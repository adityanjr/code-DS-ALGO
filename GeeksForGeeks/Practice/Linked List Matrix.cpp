/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*structure of the node of the linked list is as
struct Node
{
	int data;
	Node* right, *down;
};*/
// n is the size of the matrix
// function must return the pointer to the first element 
// of the in linked list i.e. that should be the element at arr[0][0]
Node* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    // code here
    Node* head = NULL, *prev = NULL;
    
    vector<Node*> top(n);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            Node* node = new Node();
            node->data = mat[i][j];
            node->right = NULL;
            node->down = NULL;
            
            if(!head){
                head = node;
            }
            
            if(i > 0){
                top[j]->down = node;
            }
            if(j > 0 && prev){
                prev->right = node;
            }
            
            top[j] = node;
            prev = node;
        }
        
        prev = NULL;
    }
    
    
    return head;
}
