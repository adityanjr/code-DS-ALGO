/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node {
	int data;
	struct Node *left, *right;
};
*/

int sum(Node* root){
    if(!root){
        return 0;
    }
    
    return root->data + sum(root->left) + sum(root->right);
}

// your are required to complete this function
// function should return the count of the number of 
// subtrees with Sum equal to X
int countSubtreesWithSumX(Node* root, int x)
{
	// Code here
	if(!root){
	    return 0;
	}
	
	int ans = 0;
	if(sum(root) == x){
	    ans = 1;
	}
	
	return ans + countSubtreesWithSumX(root->left, x) + countSubtreesWithSumX(root->right, x);
}
