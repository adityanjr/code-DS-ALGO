/*

Word Search II
--------------

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
 

Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.

*/

class Solution {
        class Trie{
        public:
            Trie *children[26]; // pointers to its substrings starting with 'a' to 'z'
            bool leaf; // if the node is a leaf, or if there is a word stopping at here
            int idx; // if it is a leaf, the string index of the array words
            Trie()
            {
                this->leaf = false;
                this->idx = 0;
                fill_n(this->children, 26, nullptr);            
            }
        };
        
    public:
        void insertWords(Trie *root, vector<string>& words, int idx)
        {
            int pos = 0, len = words[idx].size();
            while(pos<len)
            {
                if(nullptr == root->children[words[idx][pos]-'a']) root->children[words[idx][pos]-'a'] = new Trie();
                root = root->children[words[idx][pos++]-'a'];
            }
            root->leaf = true;
            root->idx = idx;
        }
        
        Trie *buildTrie(vector<string>& words)
        {
            Trie *root = new Trie(); 
            int i;
            for(i=0; i<words.size();i++) insertWords(root, words, i);
            return root;
        }
        
        void checkWords(vector<vector<char>>& board, int i, int j, int row, int col, Trie *root, vector<string> &res, vector<string>& words)
        {
            char temp;
            if(board[i][j]=='X') return; // visited before;
            if(nullptr == root->children[board[i][j]-'a']) return ; // no string with such prefix
            else
            {
                temp = board[i][j];
                if(root->children[temp-'a']->leaf)  // if it is a leaf
                {
                    res.push_back(words[root->children[temp-'a']->idx]);
                    root->children[temp-'a']->leaf = false; // set to false to indicate that we found it already
                }
                board[i][j]='X'; //mark the current position as visited
// check all the possible neighbors
                if(i>0) checkWords(board, i-1, j, row, col, root->children[temp-'a'], res, words);
                if((i+1)<row) checkWords(board, i+1, j, row, col,  root->children[temp-'a'], res, words);
                if(j>0) checkWords(board, i, j-1,  row, col, root->children[temp-'a'], res, words);
                if((j+1)<col)  checkWords(board, i, j+1,  row, col, root->children[temp-'a'], res, words);
                board[i][j] = temp; // recover the current position
            }
        }
    
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
           vector<string> res;
           int row = board.size();
           if(0==row) return res;
           int col = board[0].size();
           if(0==col) return res;
           int wordCount = words.size();
           if(0==wordCount) return res;
           
           Trie *root = buildTrie(words);
           
           int i,j;
           for(i =0 ; i<row; i++)
           {
               for(j=0; j<col && wordCount > res.size(); j++)
               {
                   checkWords(board, i, j, row, col, root, res, words);
               }
           }
           return res;
        }
 };