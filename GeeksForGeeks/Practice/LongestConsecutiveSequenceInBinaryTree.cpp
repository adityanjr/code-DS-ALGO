/*
struct Node
{
	int data;
	Node *left, *right;
};
*/
// your task is tp complete this function
// function should return the length of the longestConsecutive
// sequence
void check(Node* root, int last, int& ans, int temp){
    if(!root){
        return;
    }
    
    if(root->data == (last + 1)){
        temp++;
    }
    else{
        temp = 0;
    }
    
    ans = max(ans, temp);
    
    check(root->left, root->data, ans, temp);
    check(root->right, root->data, ans, temp);
}

int longestConsecutive(Node* root)
{
     //Code here
     int ans = 0;
     
     check(root, -1, ans, 0);
     
     if(ans == 0){
         return -1;
     }
     
     return ans+1;
}
