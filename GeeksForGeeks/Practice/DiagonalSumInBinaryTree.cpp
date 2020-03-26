/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
};
*/
void make(Node* root, int diag, map<int, int>& m){
    if(!root){
        return;
    }
    
    if(m.find(diag) == m.end()){
        m[diag] = root->data;
    }
    else{
        m[diag] += root->data;
    }
    
    make(root->left, diag+1, m);
    make(root->right, diag, m);
}

void diagonalSum(Node* root)
{
 // Add your code here
    map<int, int> m;
    
    make(root, 0, m);
    
    map<int, int> :: iterator it = m.begin();
    
    while(it != m.end()){
        cout << it->second << " ";
        it++;
    }
    
    cout << endl;
}
