#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node{
    int val;
  
    Node* left;
    Node* right;
  
    Node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

Node* makeTree(vector<int> temp, int start, int end){
    if(start > end){
        return NULL;
    }
    
    int mid = start + (end-start)/2;
    
    Node* root = new Node(temp[mid]);
    
    root->left = makeTree(temp, start, mid-1);
    root->right = makeTree(temp, mid+1, end);
    
    return root;
}

void printTree(Node* root){
    stack<Node*> st;
    
    while(!st.empty() || root != NULL){
        if(root == NULL){
            root = st.top();
            root = root->right;
            st.pop();
        }
        else{
            cout << root->val << " ";
            st.push(root);
            root = root->left;
        }
    }
    
}

int main() {
	//code
	int test;
	cin >> test;
	
	while(test){
	    int n;
	    cin >> n;
	    
	    vector<int> temp(n);
	    
	    for(int i = 0; i < n; i++){
	        cin >> temp[i];
	    }
	    
	    Node* root = makeTree(temp, 0, n-1);
	    
	    printTree(root);
	    
	    cout << endl;
	    
	    test--;
	}
	
	return 0;
}
