/*Node structure
struct Node
{
	int data;
	struct Node *left, *right;
};*/

bool search(Node* root, int key){
    if(!root){
        return false;
    }
    else if(root->data == key){
        return true;
    }
    else if(root->data > key){
        return search(root->left, key);    
    }
    return search(root->right, key);
}

void print(Node* root1, Node* root2, vector<int>& sol){
    if(!root1){
         return;
     }
     
     if(search(root2, root1->data)){
         sol.push_back(root1->data);
     }
     
     print(root1->left, root2, sol);
     print(root1->right, root2, sol);
}

/* Function should print common elements in given two trees */
void printCommon(Node *root1, Node *root2)
{
     //Your code here
     vector<int> sol;
     
     print(root1, root2, sol);
     
     if(sol.size() != 0){
        sort(sol.begin(), sol.end());
     
        for(int i = 0; i < sol.size(); i++){
            cout << sol[i] << " ";
        } 
        
        cout << endl; 
     }
     
}
