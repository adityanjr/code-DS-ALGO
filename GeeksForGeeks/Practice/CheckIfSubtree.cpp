/* A binary tree node
struct Node
{
    int key;
    Node* left, * right;
}; */


/*you are required to 
complete this function */
bool isSubtree(Node*  T1 ,Node * T2)
{
     //Your code here 
     //return 1 if T2 is subtree of T1 else 0
     if(!T1 && !T2){
         return true;
     }
     if(!T1 || !T2){
         return false;
     }
     
     if(T1->key != T2->key){
         return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);         
     }
     return (isSubtree(T1->right, T2->right) && isSubtree(T1->left, T2->left)) ||  isSubtree(T1->left, T2) || isSubtree(T1->right, T2);         
}
