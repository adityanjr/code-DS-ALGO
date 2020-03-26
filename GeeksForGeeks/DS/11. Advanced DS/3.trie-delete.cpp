// http://www.geeksforgeeks.org/trie-delete
/*Doubt*/

#include <bits/stdc++.h>
using namespace std;

#define SIZE 26
#define TO_INDEX(c) ((int)c - (int)'a')

struct node {
	int data;
	node *child[SIZE];
};

struct Trie {
	node *root;
	int count;
};

node *getNode(){
	node *t = new node;
	t->data = 0;
	for(int i=0; i<SIZE; i++)
		t->child[i] = NULL;
	return t;
}

void initialize(Trie *tries){
	tries->root = getNode();
	tries->count = 0;
}

void insert(Trie *trie, string str){
	int n = str.length();
	node *ptr = trie->root;
	trie->count++;
	int idx;
	for(int i=0; i<n; i++){
		idx = TO_INDEX(str[i]);
		if(!ptr->child[idx]){
			ptr->child[idx] = getNode();
		}
		ptr = ptr->child[idx];
	}
	ptr->data = trie->count;
}

int search(Trie *trie, string str){
	int n = str.length();
	node *ptr = trie->root;
	int idx;
	for(int i=0; i<n; i++){
		idx = TO_INDEX(str[i]);
		if(!ptr->child[idx])
			return 0;
		ptr = ptr->child[idx];
	}
	if(ptr->data)
		return 1;
	return 0;
}

bool isFree(node *root){
	for(int i=0; i<SIZE; i++){
		if(root->child[i])
			return false;
	}
	return true;
}

bool deleteHelper(node *root, string str, int i, int n){
	if(root == NULL)
		return true;;
	int idx = TO_INDEX(str[0]);
	if(i == n){
		if(root->data){
			cout<<root->data;
			root->data = 0;
			if(isFree(root)){
				delete(root);
				root = NULL;
				return true;
			}
			else
				return false;
		}
	}
	else {
		cout<<"@";
		if(deleteHelper(root->child[idx], str, i+1, n)){
			node *del = root->child[idx];
			cout<<"!";
			del = NULL;
			delete(del);
			return (root->data == 0 && isFree(root->child[idx]));
		}
	}
}

void deleteKey(Trie *trie, string str){
 	deleteHelper(trie->root, str, 0, str.length());
}

int main(){
	char keys[][8] = {"she", "sells", "sea", "shore", "the", "b", "sheer"};
    Trie trie;

    initialize(&trie);

    for(int i = 0; i < 7; i++)
    {
        insert(&trie, keys[i]);
    }

    deleteKey(&trie, keys[5]);

    printf("%s %s\n", "b", search(&trie, "b") ? "Present in trie" : "Not present in trie");

    return 0;
}

