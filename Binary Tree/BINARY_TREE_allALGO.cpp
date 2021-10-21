  
  #include<bits/stdc++.h>

  using namespace std;

  struct Node{
      int data;
      struct Node* left;
      struct Node* right;
  };
  
  vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> ans;
      
      if(node==NULL)
      return ans;
      
      queue<Node*> q;
      q.push(node);
      
      while(q.empty()==false){
          Node* current = q.front();
          ans.push_back(current->data);
          
          q.pop();
          
            if (current->left != NULL)
            q.push(current->left);
 
        /*Enqueue right child */
        if (current->right != NULL)
            q.push(current->right);
      }
      
      return ans;
    }

    //another algo for level order traversal
    void printLevelOrder(node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printGivenLevel(root, i);
}
 
/* Print nodes at a given level */
void printGivenLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
 
/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/


int height(node* node)   //O(n)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
            return(lheight + 1);
        else return(rheight + 1);
    }
}

//another algo for level order traversal

void printLevelOrder(Node * root){
    if(root==NULL)
    return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(q.empty()==false){
         Node* current = q.front();

         q.pop();
          
          if(current!=NULL){
              cout<<current->data<<" ";

               if (current->left != NULL)
                 q.push(current->left);

              /*Enqueue right child */
              if (current->right != NULL)
               q.push(current->right);
      

          }
          
          
        else if(!q.empty()){
            q.push(NULL);
        }
    }      
}

//SUM OF NODES AT Kth LEVEL

int SumAtKthLevel(Node* root , int k){
    if(root==NULL)
    return -1;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    int level = 0;
    int sum =0;

    while(q.empty()==false){
        Node* node = q.front();
        q.pop();

        if(node!=NULL){
            if(level==k){
                sum+= node->data ;
            }

            if(node->left)
            q.push(node->left);

            if(node->right)
            q.push(node->right);
        }

        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }


    return sum;
}


//algorithm to count all the nodes in given Binary Tree

int CountNodes(Node* root){

    if(root==NULL)
    return 0;

    return CountNodes(root->left) + CountNodes(root->right) + 1;
}

//algorithm to find sum of all nodes of binary tree

 
int Sum_of_Nodes(Node* root){

    if(root==NULL)
    return 0;

    return CountNodes(root->left) + CountNodes(root->right) + root->data;
}

//DIAMETER OF A BINARY TREE :: NUMBER OF NODES IN THE LONGEST PATH B/W ANY 2 LEAVES


int diameter_binary_tree(Node* root){         //O(n^2)

    if(root==NULL)
    return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    int currDiameter = lheight + rheight +1;

    int ldiameter = diameter_binary_tree(root->left);
    int rdiameter = diameter_binary_tree(root->right);


  return max(currDiameter,max(ldiameter,rdiameter));
}

//another finction
int diameter_binary_tree(Node* root,int * height){          //O(n)

    if(root==NULL)
    {   
        *height = 0;
        return 0;
    }

    int lh=0, rh=0;

    int ldiameter = diameter_binary_tree(root->left,&lh);
    int rdiameter = diameter_binary_tree(root->right,&rh);

    int currDiameter  = lh + rh + 1;
    *height = max(lh,rh) +1;

    return max(currDiameter,max(ldiameter,rdiameter));
}
//passing of above function
/*
int height = 0;
diameter_binary_tree(node,&height);
*/



//algorithm for sum replacement in binary_tree
//replace the value of each node with the sum of all subtree nodes and itself

void sumReplace(Node * root){

    //O(n) since all the nodes are traversed once and O(1) operations are being performed
    
    if(root==NULL){
        return;
    }

    sumReplace(root->left);
    sumReplace(root->right);

    if(root->left!=NULL){
        root->data  +=  root->left->data;
    }

    if(root->right!=NULL){
        root->data  += root->right->data;
    }
}


bool isBalanced(Node* root){
    //O(N^2)
    //since all nodes are traversed once and for each node ,, height(O(N)) fn is called

    if(root==NULL){
        return true;
    }

    if(isBalanced(root->left)==false){
        return false;
    }

    if(isBalanced(root->right)==false){
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
}

bool isBalanced(Node * root,int *height){
    //O(N) -- optimized code

    if(root==NULL)
    {
        return true;
    }

    int lh=0;
    int rh=0;

    if(isBalanced(root->left,&lh)==false){
        return false;
    }

    if(isBalanced(root->right,&rh)==false){
        return false;
    }

  *height = max(lh,rh) +1;
  if(abs(lh-rh)<=1)
  {
  return true;
  }
  else{
      return false;
  }

}
////for passing this fn
int height = 0 ;
isBalanced(root,&height);



//right view of binary tree

void rightView(Node* root){
    if(root==NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(q.empty()==false){
        
        int n=q.size();

        for(int i=0;i<n;i++){
            Node* curr = q.front();
            q.pop();

            if(i==n-1){        //for leftView of B.T ,, (i==0)
                cout<<curr->data<<" , ";
            }

            if(curr->left!=NULL){
                q.push(curr->left);
            }

            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}


//distance b/w two nodes in a binary tree ::
//the distance b/w two nodes is the minimum no. of edges to be traversed to reach one node from another

//LCA is lowest common ancestor

Node* LCA(Node* root,int n1,int n2){
    

    //O(N)

    if(root==NULL){
        return NULL;
    }

    if(root->data==n1  ||  root->data==n2){
        return root;

    }

    Node* left_lca =  LCA(root->left,n1,n2);
    Node* right_lca = LCA(root->right,n1,n2);

    if(left_lca!=NULL  and  right_lca!=NULL){
         return root;
    }

    if(left_lca==NULL and right_lca==NULL){
        return NULL;
    }

    if(left_lca!=NULL){
        return left_lca;
    }

    return right_lca;
}

//another LCA algo

bool getPath(Node * root,int key, vector<int> &path){      

    if(root==NULL){
        return false;
    }

    path.push_back(root->data);
    if(root->data==key){
        return true;
    }

    if(getPath(root->left,key,path) ||  getPath(root->right,key,path)){
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(Node *root, int n1,int n2){     //O(N)

    vector<int> path1,path2;

    if(!getPath(root,n1,path1) ||  !getPath(root,n2,path2)){
        return -1;      // no LCA node is found
    }

    int pc ;   //path change
    for(pc=0;pc<path1.size() and path2.size();pc++){
        if(path1[pc] != path2[pc]){
            break;
        }
    }

    return path1[pc-1];
}

int findDist(Node* root,int k,int dist){

    if(root==NULL){
        return -1;
    }
    if(root->data==k){
        return dist;
    }

    int left = findDist(root->left,k,dist+1);
    if(left!=-1){
        return left;
    }

    return findDist(root->right,k,dist+1);
}

int DistancebtwNodes(Node* root,int n1,int n2){

    Node* lca = LCA(root,n1,n2);

    int d1 = findDist(lca,n1,0);
    int d2 = findDist(lca,n2,0);

    return d1+d2;
}


//flatten a binary tree in to a linked list

void flatten(Node * root){

      if(root==NULL ||  root->left==NULL and root->right==NULL){
          return;
      }

    if(root->left!=NULL){

        flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* t= root->right;
        while(t->right!=NULL){
            t = t->right;
        }

        t->right = temp;
    }

    flatten(root->right);
}

//algorithm to print all the subtree nodes which are at distance k from the given node

void printSubtreeNodes(Node * root,int k){

    if(root==NULL || k<0){
        return ;
    }

    if(k==0){
        cout<< root->data<<" , ";
        return;
    }

    printSubtreeNodes(root->left,k-1);
    printSubtreeNodes(root->right,k-1);
}

int printNodesAtk(Node* root,Node* target,int k){

    if(root==NULL){
        return -1;
    }

    if(root==target){
        printSubtreeNodes(root,k);
        return 0;
    }

    int dl = printNodesAtk(root->left,target,k);

    if(dl != -1){
        if(dl+1 == k){
            cout<<root->data<<" ";
        }
        else{
            printNodesAtk(root->right,target,k-dl-2);
        }

        return 1+dl;
    }

     int dr = printNodesAtk(root->right,target,k);

    if(dr != -1){
        if(dr+1 == k){
            cout<<root->data<<" ";
        }
        else{
            printNodesAtk(root->left,target,k-dr-2);
        }

        return 1+dr;
    }

return -1;
}


//maximum possible sum of path in binary tree through root

int maxPathSum(Node* root){
    int ans = INT_MIN;
    maxPathSumUtil(root,ans);
    return ans;
}

int maxPathSumUtil(Node* root,int &ans){

    if(root==NULL){
        return 0;
    }

    int left = maxPathSumUtil(root->left,ans);
    int right = maxPathSumUtil(root->right,ans);

    int nodeMax = max(max(root->data,root->data + left + right),
    max(root->data + left,root->data + right));

    ans = max(ans,nodeMax);

    int singlePathSum = max(root->data,max(root->data + left , root->data + right));
    //ancestors can be include

    return singlePathSum;
}