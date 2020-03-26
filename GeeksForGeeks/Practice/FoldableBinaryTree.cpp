/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/

bool check(node* l, node* r){
    if(!l && !r){
        return true;
    }
    else if(!l || !r){
        return false;
    }
    return (check(l->left, r->right) && (check(l->right, r->left)))
            || (check(l->right, r->left) && check(l->left, r->right));
}


/* Returns true if the given tree is foldable */
bool isFoldable(struct node *root)
{
  // Your code goes here
  return check(root->left, root->right);
}
