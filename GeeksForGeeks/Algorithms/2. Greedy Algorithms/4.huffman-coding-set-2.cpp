// http://www.geeksforgeeks.org/greedy-algorithms-set-3-huffman-coding-set-2/

#include <iostream>
#include <climits>
#include <cstdio>
#include <queue>
//#include <vector>
//#include <string>
using namespace std;

struct node {
	char data;
	int freq;
	node *left, *right;
};

node* newNode(char data, int freq) {
	node *tmp = new node;
	tmp->data = data;
	tmp->freq = freq;
	tmp->right = tmp->left = NULL;
}

node* popQueue(queue<node*> &q1, queue<node*> &q2) {
	node *tmp;
	if(q1.empty() || !q2.empty() && q1.front()->freq > q2.front()->freq) {
		tmp = q2.front();
		q2.pop();
	}
	else {
		tmp = q1.front();
		q1.pop();
	}
	return tmp;
}

void recurse(queue<node*> &q1, queue<node*> &q2) {
	while(!q1.empty()) {
		node *left = popQueue(q1, q2);
		node *right = popQueue(q1, q2);
		node *top = newNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		//cout<<left->data<<" "<<right->data;
		q2.push(top);
	}
	if(q2.size() == 1)
		return;
	else
		recurse(q2, q1);
}

void printArr(int arr[], int n) {
	for (int i = 0; i < n; ++i){
		cout<<arr[i]<<" ";
	}
	cout<<'\n';
}

void printCodes(node* root, int arr[], int top){
	if(root->left) {
		arr[top] = 0;
		printCodes(root->left, arr, top+1);
	}
	if(root->right) {
		arr[top] = 1;
		printCodes(root->right, arr, top+1);
	}

	if(root->right == NULL && root->left == NULL) {
		cout<<root->data<<": ";
		printArr(arr, top);
	}
}

void HuffmanCodes(char *arr, int *freq, int size) {
	queue<node*> q1, q2;

	for (int i = 0; i < size; ++i) {
		q1.push(newNode(arr[i], freq[i]));
	}
	recurse(q1, q2);
	node *root = q2.front();
	//cout<<root->freq;
	int a[100];
	printCodes(root, a, 0);
}

int main(){
	char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
	return 0;
}