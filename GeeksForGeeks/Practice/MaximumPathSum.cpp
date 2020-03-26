/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Complete the function below
Node is as follows
struct Node{
	int data;
	Node *left, *right;
};
*/
int sum(Node* root){
    if(!root){
        return 0;
    }
    else if(!root->left && !root->right){
        return root->data;
    }
    else if(root->left && root->right){
        return root->data + max(sum(root->left), sum(root->right));
    }
    else if(root->left){
        return root->data + sum(root->left);
    }
    return root->data + sum(root->right);
}


int maxPathSum(struct Node *root)
{
//add code here.
    if(!root){
        return 0;
    }
    else if(!root->left && !root->right){
        return root->data;
    }
    else if(root->left && root->right){
        return max(root->data + sum(root->left) + sum(root->right), max(maxPathSum(root->left), maxPathSum(root->right)));
    }
    else if(root->left){
        return maxPathSum(root->left);
    }
    return maxPathSum(root->right);
}
