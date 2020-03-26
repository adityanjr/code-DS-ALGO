// http://www.practice.geeksforgeeks.org/viewSol.php?subId=974406

/* A binary tree node
struct Node
{
    int data;
    struct Node* left, * right;
}; */

/* Should return minimum distance between a and b 
   in a tree with given root*/
bool find(Node* root, int a){
    if(root == NULL){
        return false;
    }
    if(root->data == a){
        return true;
    }
    return find(root->left, a) || find(root->right, a);
}

Node* find(Node* root, int a, int b){
    if(root == NULL){
        return NULL;
    }
    if(root->data == a || root->data == b){
        return root;
    }
    bool l = find(root->left, a) || find(root->left, b);
    bool r = find(root->right, a) || find(root->right, b);
    
    if(l && r){
        return root;
    }
    else if(l){
        return find(root->left, a, b);
    }
    else if(r){
        return find(root->right, a, b);
    }
    return NULL;
}   

int dis(Node* root, int a){
    if(root == NULL){
        return 0;
    }
    if(root->data == a){
        return 0;
    }
    if(find(root->left, a)){
        return 1 + dis(root->left, a);
    }
    return 1 + dis(root->right, a);
}
   
int findDist(Node* root, int a, int b){
    Node* an = find(root, a, b);
    return dis(an, a) + dis(an, b);
}
