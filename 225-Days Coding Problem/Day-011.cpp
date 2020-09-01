/*
    This problem was asked by Twitter.

    Implement an autocomplete system. 

    That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.

    For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

    Hint: Try preprocessing the dictionary into a more efficient data structure to speed up queries.


*/
#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node*alphabets[26];
    bool isEnd; // for the end of word 
    Node(){
        for(int i=0;i<26;++i){
            alphabets[i] = nullptr;
        }
        isEnd = false;
    }
};
void addword(Node*root,string s){
    Node*t_Node=root; 
    for(int i=0; i<(int)s.size(); ++i){
        int index = s[i]-'a';
        if(t_Node->alphabets[index]==nullptr){
            t_Node->alphabets[index]=new Node();
        }
        t_Node = t_Node->alphabets[index];
    }
    t_Node->isEnd = true;
    return;
}
bool last(Node*temp){
    for(int i=0;i<26;++i){
        if(temp->alphabets[i]!=nullptr){
            return false;
        }
    }
    return true;
}

void util(Node*root , string ans){
    if(root->isEnd){
        cout<<ans<<endl;
    }
    if(last(root)){
        return;
    }
    for(int i=0;i<26;++i){
        if(root->alphabets[i]!=nullptr){
            ans.push_back(char((int)'a'+i));
            util(root->alphabets[i],ans);
            ans.pop_back();
        }
    }
}
void autocomplete(Node*root ,string search_Pattern){
    struct Node*temp = root;
    for(int i=0;i<(int)search_Pattern.size();++i){
        int index = search_Pattern[i]-'a';
        if(temp->alphabets[index]==nullptr){
            return;
        }
        temp=temp->alphabets[index];
    }
    if(last(temp)){
        cout<<search_Pattern<<endl;
        return;
    }else{
        util(temp , search_Pattern ); // utility function
    }
}

int main(void){
    Node*root=new Node();
    addword(root,"dog");
    addword(root,"deer");
    addword(root,"deal");
    autocomplete(root,"de");
    return 0;
}
