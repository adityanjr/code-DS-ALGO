/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//User function Template for C++
/*
structure of the node of the binary tree is as
struct Node {
	int data;
	Node* left, *right;
};
*/

void calSum(Node* root, int currSum, int currLevel, int& sum, int& level){
    if(!root){
        if(currLevel > level){
            level = currLevel;
            sum = currSum;
        }
        else if(currLevel == level){
            sum = max(sum, currSum);
        }
        return;
    }
    calSum(root->left, currSum + root->data, currLevel+1, sum, level);
    calSum(root->right, currSum + root->data, currLevel+1, sum, level);
}

// your task is to complete this function
int sumOfLongRootToLeafPath(Node* root)
{
	// Code here
	int sum = 0, level;
	calSum(root, 0, 0, sum, level);
	
	return sum;
}
