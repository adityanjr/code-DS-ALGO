/*
   This problem was asked by Microsoft.

   Suppose an arithmetic expression is given as a binary tree. Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.

   Given the root to such a tree, write a function to evaluate it.

   For example, given the following tree:

         *
        / \
       +    +
      / \  / \
     3  2  4  5

 You should return 45, as it is (3 + 2) * (4 + 5).
 */
#include <bits/stdc++.h>
using namespace std;
struct Node{
    string value;
    Node* left;
    Node* right;

    Node(): left{nullptr} , right{nullptr} {  };
};

double solExpression( Node* root ) {
    if(root == nullptr){
        return 0.0f;
    }

    double leftAns = solExpression(root -> left);
    double rightAns = solExpression(root -> right);

    if(root -> value == "+"){
        return leftAns + rightAns;
    }

    if(root -> value == "-"){
        return leftAns - rightAns;
    }

    if(root -> value == "*"){
        return leftAns * rightAns;
    }

    if(root -> value == "/"){
        return leftAns / rightAns;
    }

    return std::stof(root->value);

}

int main(void){
    Node*root = new Node();
    root -> value = "*";

    root -> left = new Node();
    root -> left -> value = "+";

    root -> left -> left = new Node();
    root -> left -> left -> value = "3";
    
    root -> left -> right = new Node();
    root -> left -> right -> value = "2";

    root -> right = new Node();
    root -> right -> value = "+";

    root -> right -> left = new Node();
    root -> right -> left -> value = "4";

    root -> right -> right = new Node();
    root -> right -> right -> value = "5";
    

    double ans = solExpression(root);

    if(ans - (int)ans==0){
        cout << ans ;
    }else{ 
        cout << fixed  << setprecision(2) << ans;
    }
    cout << '\n';

    return 0;
}
