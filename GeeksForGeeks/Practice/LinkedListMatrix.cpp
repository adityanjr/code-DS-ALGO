/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*structure of the node of the linked list is as
struct Node
{
	int data;
	Node* right, *down;
};*/

Node* make(int mat[MAX][MAX], int r, int c, int n){
    if(r >= n || c >= n){
        return NULL;
    }
    
    Node* node = new Node();
    node->data = mat[r][c];
    node->right = make(mat, r, c+1, n);
    node->down = make(mat, r+1, c, n);
    
    return node;
}

// n is the size of the matrix
// function must return the pointer to the first element 
// of the in linked list i.e. that should be the element at arr[0][0]
Node* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    // code here
    return make(mat, 0, 0, n);
}
