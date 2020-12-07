class StreamChecker {
private:
    class Trie {
    public:
        bool is_leaf;
        Trie* children[26];
        
        Trie() {
            this->is_leaf = false;
            for(int i = 0; i < 26; ++i) {
                this->children[i] = NULL;
            }
        }
        
        void insert_reversed(string word) {
            reverse(word.begin(), word.end());
            Trie* root = this;
            
            for(char c: word) {
                int idx = c - 'a';
                
                if(root->children[idx] == NULL)
                    root->children[idx] = new Trie();
                
                root = root->children[idx];
            }
            
            root->is_leaf = true;
        }
            
    };
public:
    Trie trie;
    vector<char> queries;
    int longest_word = 0;
    
    StreamChecker(vector<string>& words) {
        for(auto& word: words) {
            trie.insert_reversed(word);
            
            if(word.size() > longest_word)
                longest_word = word.size();
        }
    }
    
    bool query(char letter) {
        queries.insert(queries.begin(), letter);
        
        if(queries.size() > longest_word)
            queries.pop_back();
        
        Trie* curr = &trie;
        
        for(char c: queries) {
            if(curr->is_leaf) return true;
            if(curr->children[c - 'a'] == NULL) return false;
            
            curr = curr->children[c - 'a'];
        }
        
        return curr->is_leaf;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */