/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
Structure of the node of the tree is as
struct Node {
	struct Node* left, *right;
	int key;
};
*/

bool search(Node* root, int key1, int key2){
    if(!root){
        return false;
    }
    else if(root->key == key1 || root->key == key2){
        return true;
    }
    return search(root->left, key1, key2) || search(root->right, key1, key2);
}

int turns(Node* root, int key, bool leftTurn){
    if(!root){
        return 10000;
    }    
    else if(root->key == key){
        return 0;
    }
    
    int left, right;
    if(leftTurn){
        left = turns(root->left, key, leftTurn);
        right = 1 + turns(root->right, key, !leftTurn);
    }
    else{
        left = 1 + turns(root->left, key, !leftTurn);
        right = turns(root->right, key, leftTurn);
    }
    
    return min(left, right);
}

// fundtion should return the number of turns 
// form first node to second node
int NumberOFTurn(struct Node* root, int first, int second)
{
	// Code here
	if(!root){
	    return 0;
	}
	else if(root->key == first || root->key == second){
	    return min(turns(root, first, true), turns(root, first, false)) + min(turns(root, second, true), turns(root, second, false));
	}
	
	bool left = search(root->left, first, second), right = search(root->right, first, second);
	if(left && right){
	    return 1 + min(turns(root, first, true), turns(root, first, false)) + min(turns(root, second, true), turns(root, second, false));
	}
	else if(left){
	    return NumberOFTurn(root->left, first, second);
	}
	return NumberOFTurn(root->right, first, second);
}
