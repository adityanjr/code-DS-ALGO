/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//User function Template for C++
/*
Structure of the Node of the tree is 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};*/

int getHeight(Node* root){
    if(!root){
        return 0;
    }
    else if(!root->left && !root->right){
        return 1;
    }
    else if(!root->left){
        return 1 + getHeight(root->right);
    }
    else if(!root->right){
        return 1 + getHeight(root->left);
    }
    
    return 1 + min(getHeight(root->right), getHeight(root->left));
}

void getSum(Node* root, int curr, int& height, int& sum){
    if(!root){
        return;
    }
    else if(!root->left && !root->right){
        if(curr == height){
            sum += root->data;
        }
        return;
    }
    else if(curr > height){
        return;
    }
    
    getSum(root->left, curr + 1, height, sum);
    getSum(root->right, curr + 1, height, sum);
}

// Your task is to complete this function
// function shoudl return the required sum
int minLeafSum(Node* root)
{
	// Code here
	int height = getHeight(root);
	int sum = 0;
	
	getSum(root, 1, height, sum);
	
	return sum;
}
