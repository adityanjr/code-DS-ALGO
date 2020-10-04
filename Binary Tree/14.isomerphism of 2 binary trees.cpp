#include <bits/stdc++.h>

using namespace std;

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
//isomerphism means either 2 trees are the same or mirror image of each other
bool check(struct Node*root1,struct Node* root2)
{
    if(root1==NULL&&root2==NULL)//checks for both are null
    {
        return true;
    }
    else if(root1==NULL||root2==NULL)//checks for if one of the roots is null
    {
        return false;
    }
    else if(root1->data!=root2->data)//if at the roor node the data is different then they cannot be isomers
    {
        return false;
    }
    else if((check(root1->left,root2->left)&&(check(root1->right,root2->right)))||(check(root1->left,root2->right)&&(check(root1->right,root2->left))))
    {//the 1st part before or checks for the if the trees are same and the condition after or checks if the trees are mirror images of each other
        return true;
    }
}
int main()
{
    struct Node* root1 = NULL;
    root1 = create(1);
    root1->left = create(2);
    root1->right = create(3);

    struct Node* root2 = NULL;
    root2 = create(1);
    root2->left = create(3);
    root2->right = create(2);
    if(check(root1,root2)==true)//function to check the trees
    {
        cout<<"they are isomers\n";
    }
    else{
        cout<<"they are not isomers\n";
    }
    return 0;
}
