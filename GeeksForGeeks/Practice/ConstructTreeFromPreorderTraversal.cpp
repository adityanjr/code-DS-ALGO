/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/

Node* make(int pre[], char preLN[], int& curr, int n){
    if(curr+1 >= n){
        return NULL;
    }
    
    curr++;
    Node* root = new Node();
    root->data = pre[curr];
    
    if(preLN[curr] == 'N'){
        root->left = make(pre, preLN, curr, n);
        root->right = make(pre, preLN, curr, n);
    }
    
    return root;
}

// function should return the root of the new binary tree formed
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    int curr = -1;
    return make(pre, preLN, curr, n);
}
