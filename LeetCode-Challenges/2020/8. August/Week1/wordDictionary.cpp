class TrieNode {
public:
    bool is_leaf;
    TrieNode* children[26];
    TrieNode() {
        is_leaf = false;
        memset(children, NULL, sizeof(children));
    }
};

class WordDictionary {
private:
    TrieNode* root = new TrieNode();
    
    bool search(const char* word, TrieNode* node) {
        for(int i = 0; word[i] && node; ++i) {
            if(word[i] != '.') {
                node = node->children[word[i] - 'a'];
            } else {
                TrieNode* temp = node;
                for(int j = 0; j < 26; ++j) {
                    node = temp->children[j];
                    if(search(word + i + 1, node)) {
                        return true;
                    }
                }
            }
        }
        
        return node && node->is_leaf;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node = root;
        for(char c: word) {
            if(!node->children[c - 'a']) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->is_leaf = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word.c_str(), root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */