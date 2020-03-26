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
int isSumProperty(Node *node)
{
 // Add your code here
    if(!node){
        return 1;
    }
    else if(!node->left && !node->right){
        return 1;
    }
    
    int value = 0;
    
    if(node->left){
        value += (node->left)->data;
    }
    if(node->right){
        value += (node->right)->data;
    }
    
    if(node->data != value){
        return 0;
    }
    
    return isSumProperty(node->left) && isSumProperty(node->right);
}
