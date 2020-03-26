/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

// Should set the nextRight for all nodes
void con(Node* root, Node* parent, bool isLeft){
    if(!root){
        return;
    }
    
    if(!isLeft){
        if(!parent->nextRight){
            root->nextRight = NULL;
        }
        else{
            Node* temp = parent->nextRight;
            while(temp != NULL && (temp->left == NULL || temp->right == NULL)){
                temp = temp->nextRight;
            }
            if(!temp){
                root->nextRight == NULL;
            }
            else{
                if(temp->left != NULL){
                    root->nextRight = temp->left;
                }
                else{
                    root->nextRight = temp->right;
                }
            }
        }
    }
    else{
        if(parent->right){
            root->nextRight = parent->right;
        }
        else{
            Node* temp = parent->nextRight;
            while(temp != NULL && (temp->left == NULL || temp->right == NULL)){
                temp = temp->nextRight;
            }
            if(!temp){
                root->nextRight = NULL;
            }
            else{
                if(temp->left != NULL){
                    root->nextRight = temp->left;
                }
                else{
                    root->nextRight = temp->right;
                }
            }
        }
    }
    con(root->right, root, false);
    con(root->left, root, true);
}

void connect(Node *p)
{
   if(!p){
       return;
   }
   
   p->nextRight = NULL;
   
   con(p->right, p, false);
   con(p->left, p, true);
}

