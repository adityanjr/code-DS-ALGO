// http://www.geeksforgeeks.org/trie-insert-and-search

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

// Dummy pointer root
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

int main(){
	// Input keys (use only 'a' through 'z' and lower case)
    char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    Trie trie;

    char output[][32] = {"Not present in trie", "Present in trie"};

    initialize(&trie);
    // Construct trie
    for(int i = 0; i < 8; i++)
    {
        insert(&trie, keys[i]);
    }

    // Search for different keys
    printf("%s --- %s\n", "the", output[search(&trie, "the")] );
    printf("%s --- %s\n", "these", output[search(&trie, "these")] );
    printf("%s --- %s\n", "their", output[search(&trie, "their")] );
    printf("%s --- %s\n", "thaw", output[search(&trie, "thaw")] );
	return 0;
}

