/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Structure of the node of the binary tree
struct Node
{
	int key;
	Node* left, *right;
};
*/

void makeMap(Node* node, map<Node*, bool>& m){
    if(!node){
        return;
    }
    if(m.find(node) != m.end()){
        m[node] = true;
        return;
    }
    m[node] = false;
    makeMap(node->left, m);
    makeMap(node->right, m);
}

int height(Node* root, map<Node*, bool>& m){
    if(!root){
        return 0;
    }
    if(m.find(root) != m.end()){
        if(m[root]){
            return 1;
        }
    }
    return 1 + max(height(root->left, m), height(root->right, m));
}

// function should return the height of the binary tree
int findTreeHeight(Node* node)
{
	// Code here
	map<Node*, bool> m;
	makeMap(node, m);
	
	return height(node, m);
}
