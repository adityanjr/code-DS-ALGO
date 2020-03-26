// http://www.geeksforgeeks.org/reverse-alternate-levels-binary-tree
/***/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node {
	char data;
	Node *right, *left;
};

void printLevelorder(Node *root){
	if(root == NULL)
		return;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node *tmp = q.front();  q.pop();
		cout<<tmp->data<<" ";
		if(tmp->left)
			q.push(tmp->left);
		if(tmp->right)
			q.push(tmp->right);
	}
}

Node *newnode(char data){
	Node *n = new Node;
	n->data = data;
	n->right = NULL;
	n->left = NULL;
	return n;
}

void reverseAlternate(Node *root){
	if(root == NULL)
		return;
	queue<Node*> q;
	stack<Node*> s;
	q.push(root);
	bool flag = false;
	while(!q.empty()){
		int count = q.size();
		if(!q.front()->left && !q.front()->right){
			q.pop();
			continue;
		}
		while(count){
			Node *tmp = q.front();  q.pop();
			if(!flag){
				if(tmp->left)
					s.push(tmp->left);
				if(tmp->right)
					s.push(tmp->right);
			}
			else{
				if(tmp->right)
					s.push(tmp->right);
				if(tmp->left)
					s.push(tmp->left);
			}
			q.push(tmp);
			count--;
		}
		flag = !flag;
		while(!s.empty()){
			Node *tmp = q.front();
			q.push(s.top());
			tmp->left = s.top();    s.pop();
			q.push(s.top());
			tmp->right = s.top();   s.pop();
			q.pop();
		}
	}
}

int main(){
	Node *root = newnode('a');
    root->left = newnode('b');
    root->right = newnode('c');
    root->left->left = newnode('d');
    root->left->right = newnode('e');
    root->right->left = newnode('f');
    root->right->right = newnode('g');
    root->left->left->left = newnode('h');
    root->left->left->right = newnode('i');
    root->left->right->left = newnode('j');
    root->left->right->right = newnode('k');
    root->right->left->left = newnode('l');
    root->right->left->right = newnode('m');
    root->right->right->left = newnode('n');
    root->right->right->right = newnode('o');

    cout << "Inorder Traversal of given tree\n";
    printLevelorder(root);

    reverseAlternate(root);

    cout << "\n\nInorder Traversal of modified tree\n";
    printLevelorder(root);
	return 0;
}

