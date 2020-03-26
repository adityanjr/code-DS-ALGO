// http://www.geeksforgeeks.org/pattern-searching-using-trie-suffixes

#include <iostream>
#include <cstdio>
#include <list>
using namespace std;

#define MAX 256

struct node {
    char data;
    node *child[MAX];
};

node *createSuffix(char data){
    node *n =  new node;
    n->data = data;
    for(int i=0; i<MAX; i++)
        n->child[i] = NULL;
    return n;
}

void insertString(node *root, string str){
    if(str == "")
        return;
    int idx = int(str[0]);
    if(!root->child[idx])
        root->child[idx] = createSuffix(str[0]);
    insertString(root->child[idx], str.substr(1));
}

void insertSuffixes(node *root, string suffix){
    int N = suffix.length();
    for(int i=0; i<N; i++){
        insertString(root, suffix.substr(i));
    }
}

void search(node *root, string str){
    if(str == ""){
        cout<<"found";
        return;
    }
    int idx = int(str[0]);
    if(root->child[idx]){
        search(root->child[idx], str.substr(1));
    }
    else {
        cout<<"Not found!";
        return;
    }
}

int main(){
    // Let us build a suffix trie for text "geeksforgeeks.org"
    string txt = "geeksforgeeks.org";
    node *root = createSuffix('\n');
    insertSuffixes(root, txt);
    //cout<<root->child[int('g')]->data<<'\n';
    cout << "Search for 'ee'" << endl;
    search(root, "ee");

    cout << "\nSearch for 'geek'" << endl;
    search(root, "geek");

    cout << "\nSearch for 'quiz'" << endl;
    search(root, "quiz");

    cout << "\nSearch for 'forgeeks'" << endl;
    search(root, "forgeeks");
    return 0;
}
