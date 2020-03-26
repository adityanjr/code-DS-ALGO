/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
Structure of the node of the binary search tree is as
struct node 
{
	int data;
	struct node* left;
	struct node* right;
};
*/
// your task is to complete the below function
int minValue(struct node* root)
{
    // Code here
    if(!root){
        return 0;
    }
    else if(!root->left){
        return root->data;
    }
    
    return minValue(root->left);
}
