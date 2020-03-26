// http://www.practice.geeksforgeeks.org/problem-page.php?pid=700180

/* node structure  used in the program
 struct Node
 {
     int data;
     struct node* left, *right;
}; */

/*  Function which returns the  root of 
    the constructed binary tree. */

Node *createTree(int parent[], int n){
    if(n == 0){
        return NULL;
    }
    
    map<int, vector<int> > m;
    
    for(int i = 0; i < n; i++){
        m[parent[i]].push_back(i);
    }
    
    queue<Node*> q;
    
    if(m.find(-1) == m.end()){
        return NULL;
    }
     
    Node* root = new Node();
    root->data = m[-1][0];
    
    q.push(root);
    
    Node* curr;
    
    while(!q.empty()){
        curr = q.front();
        int i = curr->data;
        map<int, vector<int> > :: iterator it = m.find(i);
        
        if(it != m.end()){
            vector<int> t = it->second;
            if(t.size() == 1){
                Node* temp = new Node();
                temp->data = t[0];
                q.push(temp);   
                curr->left = temp;
            }
            else if(t.size() == 2){
                Node* temp = new Node();
                temp->data = t[0];
                q.push(temp);    
                curr->left = temp;
                Node* tem = new Node();
                tem->data = t[1];
                q.push(tem);    
                curr->right = tem;
            }
        }
        
        q.pop();
    }
    
    return root;
}
