#include <bits/stdc++.h>

using namespace std;
int s = 0;
stack<struct Node*> st;//for storing the nodes
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* create(int n)
{
 struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
 temp->data = n;
 temp->left = NULL;
 temp->right = NULL;

 return temp;
}
int sum(struct Node* root,int k)//inorder traversal is used for this algorithm
{
    if(root==NULL)
    {
        return 0;
    }
    s+=root->data;
    st.push(root);
    if(s==k)//k is the required sum provided by the user
    {
        while(!st.empty())
        {
            struct Node* temp = st.top();
            st.pop();
            cout<<temp->data<<" ";
        }
        cout<<endl;
    }
    sum(root->left,k);
    sum(root->right,k);
    s-=root->data;
    st.pop();//the top element is poped out as we are moving backwards
    return 0;
}
int main()
{
    struct Node* root = NULL;
    root = create(1);
    root->left = create(2);
    root->left->left = create(4);
    root->left->right = create(5);
    root->left->left->left = create(8);
    root->left->left->right = create(9);
    root->right = create(3);
    root->right->left = create(6);
    root->right->left->left = create(10);
    root->right->left->right = create(11);

    root->right->right = create(7);
    root->right->right->right = create(12);
    int k;
    cin>>k;
    sum(root,k);

    return 0;
}
