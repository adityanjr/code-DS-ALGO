//  https://www.interviewbit.com/problems/shortest-unique-prefix/

struct TrieNode {
    struct TrieNode *children[26];
    bool isEndOfWord;
    int freq;
    TrieNode(): isEndOfWord(false), freq(0) {
        for(int i=0;i<26;i++)
            children[i] = NULL;
    }
};

void insert(TrieNode* root, string key) {
    
    TrieNode* temp = root;
    
    for(int i=0;i<key.size();i++) {
        int index = key[i]-'a';
        
        if(!temp->children[index]) {
            temp->children[index] = new TrieNode();
        }
        temp = temp->children[index];
        temp->freq++;
    }
    temp->isEndOfWord = true;
}

void findUniPref(TrieNode* root, vector<string> &prefix, string key) {
    
    TrieNode* temp = root;
    int sz = key.size();
    
    string pref;
    
    for(int i=0;i<sz;i++) {
        int index = key[i]-'a';
        pref += key[i];
        if(temp->children[index]->freq <= 1)
            break;
        temp = temp->children[index];
    }
    prefix.push_back(pref);
}

bool search(TrieNode* root, vector<string> &prefix, string key) {
    TrieNode* temp = root;
    
    for(int i=0;i<key.size();i++) {
        int index = key[i]-'a';
        if(!temp->children[index])
            return false;
        temp = temp->children[index];
    }
    return (temp && temp->isEndOfWord);
}

vector<string> Solution::prefix(vector<string> &A) {
    
    TrieNode* root = new TrieNode();
    
    for(auto a: A)
        insert(root, a);
    
    vector<string> prefix;
    
    for(auto a: A)
        findUniPref(root, prefix, a);
    
    return prefix;
}

